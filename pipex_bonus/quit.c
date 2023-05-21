/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:52:43 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/21 09:30:00 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_free1(char *s1, char *s2)
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
	return (arr);
}

int	ft_strncmpnl(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (p1[i] != '\0' && p2[i] != '\0')
	{
		if (p1[i] != p2[i] || n-- == 1)
			return (p1[i] - p2[i]);
		i++;
	}
	if (p1[i] == '\0' && p2[i] == '\n')
		return (0);
	else
		return (1);
}

void	quit(t_parameters *parameters)
{
	int	i;
	int	j;

	i = 0;
	while (parameters->commands[i] != 0)
	{
		j = 0;
		while (parameters->commands[i][j])
			free(parameters->commands[i][j++]);
		free(parameters->commands[i++]);
	}
	free(parameters->commands);
	i = 0;
	while (parameters->paths[i] != 0)
		free(parameters->paths[i++]);
	free(parameters->paths);
	i = -1;
	while (parameters->pipes[++i])
	{
		free(parameters->pipes[i]);
	}
	free(parameters->pipes);
	free(parameters);
	exit(1);
}
