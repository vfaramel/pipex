/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:14:16 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/20 22:56:37 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**init_pipes(int i)
{
	int	**pipes;

	pipes = malloc(i * sizeof(int *));
	while (--i > -1)
	{
		pipes[i] = malloc(2 * sizeof(int));
		pipe(i);
	}
	return (pipes);
}
