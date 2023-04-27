/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 02:29:50 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/27 04:14:07 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(t_parameters *parameters, int cmd)
{
	int		i;
	char	*try;

	i = 0;
	while (parameters->paths[i] != 0)
	{
		try = ft_strjoin(parameters->paths[i], parameters->commands[cmd][0]);
		if (execve(try, parameters->commands[cmd], parameters->envp) != -1)
		{
			free(try);
			exit(EXIT_SUCCESS);
		}
		free(try);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	first_cmd(t_parameters *parameters, int cmd)
{
	int	input_fd;

	input_fd = open(parameters->input, O_RDONLY);
	if (0 > dup2(parameters->pipes[cmd][1], STDOUT_FILENO)
	|| 0 > dup2(input_fd, STDIN_FILENO))
		perror("Fork one");
	execute(parameters, cmd);
}

void	last_cmd(t_parameters *parameters, int cmd)
{
	int	output_fd;

	output_fd = open(parameters->output, O_RDWR, O_TRUNC, O_CREAT);
	if (0 > dup2(output_fd, STDOUT_FILENO)
		|| 0 > dup2(parameters->pipes[cmd - 1][0], STDIN_FILENO))
		perror("Fork one");
	execute(parameters, cmd);
}

void	run_cmds(t_parameters *parameters, int cmd)
{
	if (0 > dup2(parameters->pipes[cmd][1], STDOUT_FILENO)
	|| 0 > dup2(parameters->pipes[cmd - 1][0], STDIN_FILENO))
		perror("Fork one");
	execute(parameters, cmd);
}
