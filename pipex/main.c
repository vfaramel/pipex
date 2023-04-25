/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:15:59 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/20 18:54:18 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	add_file(t_file *file, char *argv)
{
	int		i;
	char	**new_split;

	i = 0;
	while (file->cmd[i] != 0)
		i++;
	new_split = malloc((i + 2) * sizeof(char *));
	i = -1;
	while (file->cmd[++i] != 0)
		new_split[i] = file->cmd[i];
	new_split[i++] = argv;
	new_split[i] = 0;
	file->cmd_file = new_split;
}

char	**find_path(char **envp)
{
	int		i;
	char	*arr;
	char	**paths;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	arr = ft_substr(envp[i], 6, ft_strlen(envp[i]));
	paths = ft_split(arr, ':');
	i = -1;
	while (paths[++i] != 0)
		ft_strlcat(paths[i], "/", ft_strlen(paths[i]) + 2);
	return (paths);
}

void	cmd_1(int *pipe, t_file *file_1, char**envp)
{
	int		i;
	char	*cmd;
	char	**path;

	i = 0;
	path = find_path(envp);
	if (0 > dup2(pipe[1], STDOUT_FILENO) || 0 > dup2(file_1->fd, STDIN_FILENO))
		perror("Fork one");
	close(pipe[0]);
	while (path[i] != 0)
	{
		cmd = ft_strjoin(path[i], file_1->cmd_file[0]);
		if (execve(cmd, file_1->cmd_file, envp) != -1)
		{
			free(path);
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		free(cmd);
		i++;
	}
	free(path);
	exit(EXIT_FAILURE);
}

void	cmd_2(int *pipe, t_file *file_2, char**envp)
{
	int		i;
	char	*cmd;
	char	**path;

	i = 0;
	path = find_path(envp);
	dup2(file_2->fd, STDOUT_FILENO);
	if (0 > dup2(pipe[0], STDIN_FILENO))
		perror("Fork one");
	close(pipe[1]);
	while (path[i] != 0)
	{
		cmd = ft_strjoin(path[i], file_2->cmd[0]);
		if (execve(cmd, file_2->cmd, envp) != -1)
		{
			free(path);
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		free(cmd);
		i++;
	}
	free(path);
	exit(EXIT_FAILURE);
}

void	use_pipe(t_file *file_1, t_file *file_2, char **envp)
{
	int	pipo[2];
	int	x;

	pipe(pipo);
	x = fork();
	if (x < 0)
		perror("Fork one");
	if (!x)
		cmd_1(pipo, file_1, envp);
	// x = fork();
	// if (x < 0)
	// 	perror("Fork two");
	// if (!x)
	// {
		wait(NULL);
		cmd_2(pipo, file_2, envp);
	// }
	// waitpid(-1, &x, 0);
	// 	waitpid(-1, &x, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_file	*file_1;
	t_file	*file_2;

	if (argc != 5)
		return (0);
	file_1 = malloc(sizeof(t_file));
	file_2 = malloc(sizeof(t_file));
	file_1->fd = open(argv[1], O_RDONLY);
	file_2->fd = open(argv[4], O_RDWR, O_TRUNC, O_CREAT);
	file_1->cmd = ft_split(argv[2], ' ');
	add_file(file_1, argv[1]);
	file_2->cmd = ft_split(argv[3], ' ');
	use_pipe(file_1, file_2, envp);
	quit(file_1, file_2);
	close(file_1->fd);
	close(file_2->fd);
	return (0);
}
