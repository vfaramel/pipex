/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:52:43 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/18 00:26:21 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	i = 0;
	while (parameters->pipes[i])
		free(parameters->pipes[i++]);
	free(parameters->pipes);
	free(parameters);
}
