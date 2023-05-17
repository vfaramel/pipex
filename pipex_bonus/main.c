/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:15:59 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/17 23:47:35 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	int		i;
	char	*arr;
	char	**paths;
	char	**paths_slash;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	arr = ft_substr(envp[i], 6, ft_strlen(envp[i]));
	paths = ft_split(arr, ':');
	free(arr);
	i = 0;
	while (paths[i])
		i++;
	paths_slash = malloc((i + 1) * sizeof(char *));
	i = -1;
	while (paths[++i] != 0)
	{
		paths_slash[i] = ft_strjoin(paths[i], "/");
		free(paths[i]);
	}
	paths_slash[i] = 0;
	free(paths);
	return (paths_slash);
}

void	get_commands(char **argv, int argc, t_parameters *parameters)
{
	int		i;

	i = -1;
	parameters->commands = malloc((argc - 2) * sizeof(char **));
	while (++i < argc - 3)
		parameters->commands[i] = ft_split(argv[i + 2], ' ');
	parameters->commands[i] = 0;
	parameters->input = argv[1];
	parameters->output = argv[argc - 1];
}

void	init_parameters(t_parameters *parameters,
char **argv, int argc, char **envp)
{
	parameters->paths = find_path(envp);
	get_commands(argv, argc, parameters);
	parameters->pipes = init_pipes(argc - 4);
	parameters->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	int				i;
	t_parameters	*parameters;

	if (argc < 5)
		return (0);
	parameters = malloc(sizeof(t_parameters));
	init_parameters(parameters, argv, argc, envp);
	i = -1;
	while (++i < argc - 3)
	{
		if (i < argc - 4)
			pipe(parameters->pipes[i]);
		if (fork() == 0)
		{
			if (i < argc - 4)
				close(parameters->pipes[i][0]);
			if (i == 0)
			{
				if (0 == ft_strncmp(parameters->input, "here_doc", 9))
					exit(0);
				else
					first_cmd(parameters, i);
			}
			else if (i == argc - 4)
				last_cmd(parameters, i);
			else
				run_cmds(parameters, i);
		}
		else
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
	}
	quit(parameters);
	exit(0);
}
