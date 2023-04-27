/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:52:43 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/27 04:45:16 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	quit(t_parameters *parameters)
{
	int	i;
	int	j;

	i = 0;
	while (parameters->commands[i] != 0)
	{
		j = 0;
		while (parameters->commands[i][j])
		{
			if (i == 0 && parameters->commands[i][j + 1] == 0)
				break ;
			free(parameters->commands[i][j++]);
		}
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
