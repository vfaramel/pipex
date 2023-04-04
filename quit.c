/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:52:43 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/04 01:47:55 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	quit(t_file *file_1, t_file *file_2)
{
	int	i;

	i = 0;
	while (file_1->cmd[i])
		free(file_1->cmd[i++]);
	free(file_1->cmd);
	free(file_1->cmd_file);
	free(file_1);
	i = 0;
	while (file_2->cmd[i])
		free(file_2->cmd[i++]);
	free(file_2->cmd);
	free(file_2);
}
