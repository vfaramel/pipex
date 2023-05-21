/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:33:34 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/21 08:43:26 by vfaramel         ###   ########.fr       */
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
		parameters->commands[i] = ft_split_quote(argv[i + 2], ' ');
	parameters->commands[i] = 0;
	parameters->input = argv[1];
	parameters->output = argv[argc - 1];
}

int	**init_pipes(int i)
{
	int	**pipes;

	pipes = malloc((i + 1) * sizeof(int *));
	pipes[i] = 0;
	while (--i >= 0)
		pipes[i] = malloc(2 * sizeof(int));
	return (pipes);
}

void	init_parameters(t_parameters *parameters,
char **argv, int argc, char **envp)
{
	parameters->paths = find_path(envp);
	get_commands(argv, argc, parameters);
	parameters->pipes = init_pipes(argc - 4);
	parameters->envp = envp;
}
