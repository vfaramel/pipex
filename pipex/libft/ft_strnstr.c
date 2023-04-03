/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:20:53 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/30 21:01:59 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *whole, const char *part, size_t len)
{
	size_t	w;
	size_t	p;

	w = 0;
	p = 0;
	if (ft_strlen(part) == 0)
		return ((char *) whole);
	if (len == 0)
		return (0);
	ft_strlen(whole);
	while (len - w >= ft_strlen(part) && w < ft_strlen(whole))
	{
		while (p < ft_strlen(part))
		{
			if (part[p] != whole[w + p])
				break ;
			p++;
		}
		if (p == ft_strlen(part))
			return ((char *)(whole + w));
		p = 0;
		w++;
	}
	return (0);
}
