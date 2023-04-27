/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maic.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:58:52 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/27 02:31:37 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"



void	execute(int *pipe, char **argv, char **envp, char **path)
{
	int		x;
	int		filein;
	char	**cmd;
	char	*try;

	x = 0;
	cmd = ft_split(argv[2], ' ');
	filein = open(argv[1], O_RDONLY);
	if (0 > dup2(pipe[1], STDOUT_FILENO) || 0 > dup2(filein, STDIN_FILENO))
		perror("Fork one");
	close(pipe[0]);
	while (path[x] != 0)
	{
		try = ft_strjoin(path[x], argv[2][0]);
		if (execve(try, cmd, envp) != -1)
		{
			free(try);
			exit(EXIT_SUCCESS);
		}
		free(try);
		x++;
	}
	exit(EXIT_FAILURE);
	// int		i;
	// char	*cmd;
	// char	**path;

	// i = 0;
	// path = find_path(envp);
	// if (0 > dup2(pipe[1], STDOUT_FILENO) || 0 > dup2(file_1->fd, STDIN_FILENO))
	// 	perror("Fork one");
	// close(pipe[0]);
	// while (path[i] != 0)
	// {
	// 	cmd = ft_strjoin(path[i], file_1->cmd_file[0]);
	// 	if (execve(cmd, file_1->cmd_file, envp) != -1)
	// 	{
	// 		free(path);
	// 		free(cmd);
	// 		exit(EXIT_SUCCESS);
	// 	}
	// 	free(cmd);
	// 	i++;
	// }
	// free(path);
	// exit(EXIT_FAILURE);
}

void	cmd_2(int *pipe, t_file *file_2, char **envp)
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
// pipi write[1] pipe



void	first_pipe(int **pipes, char ***commands, char **envp, char **path)
{
	int		x;
	int		i;
	int		filein;
	char	*try;

	i = 0;
	while (pipes[i] != 0)
	{
		pipe(pipes[i]);
		if (fork() == 0)
		{
			close(pipes[i][0]);
			if (0 > dup2(pipes[i][1], STDOUT_FILENO) || 0 > dup2(pipes[i - 1][0], STDIN_FILENO))
				perror("Fork one");
			execute();
			close(pipes[i][1]);
			close(pipes[i - 1][0]);
		}
		else
		{
			close(pipes[i][1]);
			close(pipes[i - 1][0]);
		}
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fileout;
	int		**pipes;
	int		i;
	char	**path;
	char	***commands;
	t_parameters	*paramenters;

	paramenters = ft_calloc(sizeof(t_parameters));
	if (argc != 5)
		return (0);
	parameters->paths = find_path(envp);
	parameters->commands = get_commands(argv, argc);
	paramenters->pipes = init_pipes(argc - 4);
	fileout = open(argv[4], O_RDWR, O_TRUNC, O_CREAT);
	first_pipe()
	while ()
	// x = fork();
	// if (x < 0)
	// 	perror("Fork one");
	// if (!x)
	// {
	// 	pipe(pipes[0]);
	// 	first_pipe(pipes[0], argv, envp, path);
	// }
	// wait(NULL);
	// i = 1
	// while (i < argc - 4)
	// {
	// 	execute();
	// }
	// use_pipe(file_1, file_2, envp);
	return (0);
}
