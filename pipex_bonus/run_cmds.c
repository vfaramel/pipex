/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 02:29:50 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/21 09:52:29 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(t_parameters *parameters, int cmd)
{
	int		i;
	char	*try;

	i = 0;
	execve(parameters->commands[cmd][0], parameters->commands[cmd],
		parameters->envp);
	while (parameters->paths[i] != 0)
	{
		try = ft_strjoin(parameters->paths[i], parameters->commands[cmd][0]);
		if (execve(try, parameters->commands[cmd], parameters->envp) == -1)
			free(try);
		i++;
	}
	perror("command not found");
	quit(parameters);
}

void	here_doc(t_parameters *parameters, int cmd)
{
	char	*arr;
	char	*limiter;
	int		i;

	i = 0;
	limiter = malloc(sizeof(char));
	*limiter = '\0';
	while (parameters->commands[cmd][i])
		limiter = ft_strjoin_free1(limiter, parameters->commands[cmd][i++]);
	write(1, "pipe heredoc> ", 14);
	arr = get_next_line(STDIN_FILENO);
	while (ft_strncmpnl(limiter, arr,
			ft_strlen(limiter) + 1))
	{
		write(parameters->pipes[cmd][1], arr, ft_strlen(arr));
		write(1, "pipe heredoc> ", 14);
		arr = get_next_line(STDIN_FILENO);
	}
}

void	first_cmd(t_parameters *parameters, int cmd)
{
	int	input_fd;

	input_fd = open(parameters->input, O_RDONLY);
	if (input_fd < 0)
	{
		perror("open infile failed");
		close(parameters->pipes[cmd][1]);
		quit(parameters);
	}
	if (0 > dup2(parameters->pipes[cmd][1], STDOUT_FILENO)
	|| 0 > dup2(input_fd, STDIN_FILENO))
	{
		perror("First fork");
		quit(parameters);
	}
	execute(parameters, cmd);
}

void	last_cmd(t_parameters *parameters, int cmd)
{
	int	output_fd;

	if (ft_strncmp(parameters->input, "here_doc", 9))
		output_fd = open(parameters->output, O_RDWR, O_APPEND, O_CREAT);
	else
		output_fd = open(parameters->output, O_RDWR, O_TRUNC, O_CREAT);
	if (output_fd < 0)
	{
		perror("open outfile failed");
		quit(parameters);
	}
	if (0 > dup2(output_fd, STDOUT_FILENO)
		|| 0 > dup2(parameters->pipes[cmd - 1][0], STDIN_FILENO))
	{
		perror("Last fork");
		quit(parameters);
	}
	execute(parameters, cmd);
}

void	run_cmds(t_parameters *parameters, int cmd)
{
	if (0 > dup2(parameters->pipes[cmd][1], STDOUT_FILENO)
	|| 0 > dup2(parameters->pipes[cmd - 1][0], STDIN_FILENO))
	{
		perror("Fork one");
		quit(parameters);
	}
	execute(parameters, cmd);
}
