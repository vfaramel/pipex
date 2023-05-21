/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:15:59 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/21 10:04:43 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_parameters *parameters, int i, int argc)
{
	printf("%d\n", i);
	if (i < argc - 4)
		close(parameters->pipes[i][0]);
	if (i == 0)
	{
		if (0 == ft_strncmp(parameters->input, "here_doc", 9))
		{
			close(parameters->pipes[i][1]);
			quit(parameters);
		}
		else
			first_cmd(parameters, i);
	}
	else if (i == argc - 4)
		last_cmd(parameters, i);
	else
		run_cmds(parameters, i);
}

void	parent(t_parameters *parameters, int i, int argc)
{
	if (i == 0)
	{
		if (0 == ft_strncmp(parameters->input, "here_doc", 9))
			here_doc(parameters, i);
	}
	if (i < argc - 4)
		close(parameters->pipes[i][1]);
	if (i > 1)
		close(parameters->pipes[i - 1][0]);
}

int	main(int argc, char **argv, char **envp)
{
	int				i;
	t_parameters	*parameters;
	int				pid;
	int				status;

	if (argc < 5)
		return (0);
	parameters = malloc(sizeof(t_parameters));
	if (!parameters)
		return (0);
	init_parameters(parameters, argv, argc, envp);
	i = -1;
	while (++i < argc - 3)
	{
		if (i < argc - 4)
			pipe(parameters->pipes[i]);
		pid = fork();
		if (pid == 0)
			child(parameters, i, argc);
		else
		{
			waitpid(pid, &status, 0);
			if (WEXITSTATUS(status) == 1)
				quit(parameters);
			parent(parameters, i, argc);
		}
	}
	quit(parameters);
}
