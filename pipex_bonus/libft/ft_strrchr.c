/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:10:15 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/30 20:50:23 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*ptr;
	unsigned char	c1;

	c1 = (unsigned char) c;
	i = 0;
	ptr = 0;
	while (*(s + i) != '\0')
	{
		if (c1 == *(s + i))
			ptr = (char *) s + i;
		i++;
	}
	if (c1 == '\0')
		ptr = (char *) s + i;
	return (ptr);
}
