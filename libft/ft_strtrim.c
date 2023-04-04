/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:59:05 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/26 02:49:22 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strim(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

size_t	etrim(char const *s1, char const *set)
{
	size_t	f;
	size_t	len;

	len = ft_strlen(s1);
	f = 0;
	while (len - f > 0)
	{
		if (!ft_strchr(set, s1[len - f - 1]))
			break ;
		f++;
	}
	return (f);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	i;
	size_t	len;
	size_t	f;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	f = 0;
	i = strim(s1, set);
	if (i < len - 2)
		f = etrim(s1, set);
	arr = malloc((len - i - f + 1) * sizeof(char));
	if (!arr)
		return (0);
	ft_strlcpy(arr, s1 + i, len - i - f + 1);
	return (arr);
}
