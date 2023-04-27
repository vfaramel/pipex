/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:20:04 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/27 04:23:53 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*arr;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	arr = malloc(size * sizeof(char));
	if (!arr)
		return (0);
	ft_strlcpy(arr, s1, size);
	ft_strlcat(arr, s2, size);
	free((void *)s1);
	return (arr);
}
