/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:14:16 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/26 23:44:47 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**init_pipes(int i)
{
	int	**pipes;

	pipes = malloc((i + 1) * sizeof(int *));
	pipes[i] = 0;
	while (--i >= 0)
		pipes[i] = malloc(2 * sizeof(int));
	return (pipes);
}
