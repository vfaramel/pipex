/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:12:40 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/21 05:49:00 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line_bonus.h"

typedef struct g_split
{
	int	i;
	int	len;
	int	z;
}	t_split;

typedef struct g_parameters
{
	char	***commands;
	int		**pipes;
	char	**envp;
	char	**paths;
	char	*input;
	char	*output;
}	t_parameters;

void	init_parameters(t_parameters *parameters,
			char **argv, int argc, char **envp);
void	get_commands(char **argv, int arg, t_parameters *parameters);
char	**find_path(char **envp);
char	**add_file(char **cmd, char *argv);
int		**init_pipes(int i);

void	run_cmds(t_parameters *parameters, int cmd);
void	last_cmd(t_parameters *parameters, int cmd);
void	first_cmd(t_parameters *parameters, int cmd);
void	here_doc(t_parameters *parameters, int cmd);
void	execute(t_parameters *parameters, int cmd);
int		ft_strncmpnl(const char *s1, const char *s2, size_t n);
char	*ft_strjoin_free1(char *s1, char *s2);
char	**ft_split_quote(char const *s, char c);

void	quit(t_parameters *parameters);

#endif
