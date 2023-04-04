/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:38:25 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/30 18:23:35 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c1;
	unsigned char	i;

	i = 0;
	n = (unsigned char) n;
	c1 = (unsigned char) c;
	if (!n)
		return (0);
	ptr = (unsigned char *) s;
	while (i < n)
	{
		if (c1 == ptr[i])
			return (&ptr[i]);
		i++;
	}
	if (c1 == 0 && i < n)
		return (ptr + i);
	return (NULL);
}
