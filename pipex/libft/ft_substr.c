/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:14:24 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/27 00:54:47 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		arr = (char *)malloc(sizeof(char));
		if (!arr)
			return (0);
		arr[i] = '\0';
	}
	else
	{
		if (ft_strlen(s) - start < len)
			len = ft_strlen(s) - start;
		arr = (char *)malloc((len + 1) * sizeof(char));
		if (!arr || !s)
			return (0);
		while (len--)
			arr[i++] = s[start++];
		arr[i] = '\0';
	}
	return (arr);
}
