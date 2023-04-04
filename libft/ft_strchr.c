/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:20:23 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/30 18:31:21 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;
	char			*s1;

	c1 = (unsigned char) c;
	i = 0;
	s1 = (char *) s;
	while (*(s1 + i) != '\0')
	{
		if (c1 == *(s1 + i))
			return (s1 + i);
		i++;
	}
	if (c1 == '\0')
		return (s1 + i);
	return (NULL);
}
