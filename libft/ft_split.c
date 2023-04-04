/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:53:52 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/26 04:19:46 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countwords(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i])
			i++;
	}
	return (words);
}

void	fillarr(char **arr, char const *s, char c)
{
	int	i;
	int	len;
	int	j;
	int	z;

	i = 0;
	z = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] != c && s[i + len])
				len++;
			arr[z] = malloc((len + 1) * sizeof(char));
			j = 0;
			while (j < len)
				arr[z][j++] = s[i++];
			arr[z][j] = '\0';
			z++;
		}
		if (s[i])
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (0);
	words = countwords(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (0);
	fillarr(arr, s, c);
	arr[words] = 0;
	return (arr);
}
