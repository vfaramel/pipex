/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:21:44 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/20 23:58:17 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen1(char *c)

{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat1(char *dst, char *src, size_t len)
{
	size_t	lendst;

	if (len == 0)
		return (len + ft_strlen1(src));
	lendst = ft_strlen1(dst);
	if (len < lendst)
		return (len + ft_strlen1(src));
	while (lendst < len - 1 && *src != '\0')
	{
		dst[lendst++] = *(src++);
	}
	dst[lendst] = '\0';
	return (ft_strlen1(src) + ft_strlen1(dst));
}

size_t	ft_strlcpy1(char *dst, char *src, size_t size)

{
	size_t	i;
	size_t	n;

	n = ft_strlen1(src);
	if (!size)
		return (n);
	if (!src || !dst)
		return ((size_t) NULL);
	i = 0;
	while (size-- != 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (n);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*arr;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen1(s1) + ft_strlen1(s2) + 1;
	arr = malloc(size * sizeof(char));
	if (!arr)
		return (0);
	ft_strlcpy1(arr, s1, size);
	ft_strlcat1(arr, s2, size);
	free(s1);
	free(s2);
	return (arr);
}

char	*get_next_line(int fd)
{
	static t_fdlist	arr[4096];
	int				i;
	char			*final;

	if (read(fd, 0, 0) < 0)
		return (0);
	i = 0;
	while (arr[i].fd)
	{
		if (arr[i].fd == fd)
			break ;
		i++;
	}
	arr[i].fd = fd;
	final = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ft_strlcpy1(final, arr[i].memory, BUFFER_SIZE);
	final = makestr(final, fd);
	if (!*final)
	{
		free(final);
		return (0);
	}
	separate(final, arr[i].memory);
	return (final);
}
