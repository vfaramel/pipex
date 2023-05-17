/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:14:03 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/15 23:16:02 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER_SIZE 5

typedef struct fd_list
{
	int		fd;
	char	memory[BUFFER_SIZE];
}	t_fdlist;

char	*get_next_line(int fd);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlcpy1(char *dst, char *src, size_t size);
size_t	ft_strlcat1(char *dst, char *src, size_t len);
size_t	ft_strlen1(char *c);
char	*separate(char *final, char *backup);
char	*makestr(char *final, int fd);
int		ft_strchr1(char *s);

#endif
