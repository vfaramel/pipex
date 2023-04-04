/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:18:26 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/25 04:29:18 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	lendst;

	if (len == 0)
		return (len + ft_strlen(src));
	lendst = ft_strlen(dst);
	if (len < lendst)
		return (len + ft_strlen(src));
	while (lendst < len - 1 && *src != '\0')
	{
		dst[lendst++] = *(src++);
	}
	dst[lendst] = '\0';
	return (ft_strlen(src) + ft_strlen(dst));
}
