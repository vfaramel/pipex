/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:00:29 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/15 23:16:21 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr1(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s)
	{
		if ('\n' == s[i++])
			return (i);
	}
	return (0);
}

char	*makestr(char *final, int fd)
{
	char	*pbuf;
	ssize_t	x;

	x = BUFFER_SIZE;
	while (!ft_strchr1(final) && x == BUFFER_SIZE)
	{
		pbuf = malloc(BUFFER_SIZE + 1);
		x = read(fd, pbuf, BUFFER_SIZE);
		pbuf[x] = '\0';
		final = ft_strjoin1(final, pbuf);
	}
	return (final);
}

char	*separate(char *final, char *backup)
{
	int		i;

	i = ft_strchr1(final);
	if (i)
	{
		ft_strlcpy1(backup, final + i, BUFFER_SIZE);
		final[i] = '\0';
	}
	else
		backup[0] = '\0';
	return (final);
}
