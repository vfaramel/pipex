/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 04:04:39 by vfaramel          #+#    #+#             */
/*   Updated: 2023/05/21 06:52:03 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	countwords_quote(char const *s, char c)
{
	int	i;
	int	words;

	i = -1;
	words = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			words++;
			if (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'')
					i++;
			}
			else
			{
				while (s[i] != c && s[i])
					i++;
			}
		}
	}
	return (words);
}

void	write_words(t_split *splat, char **arr, const char *s)
{
	int	j;

	arr[splat->z] = malloc((splat->len + 1) * sizeof(char));
	j = 0;
	while (j < splat->len)
		arr[splat->z][j++] = s[splat->i++];
	if (s[splat->i] == '\'')
		splat->i++;
	arr[splat->z][j] = '\0';
	splat->z++;
}

void	fillarr_quote(char **arr, char const *s, char c)
{
	t_split	splat;

	splat.i = -1;
	splat.z = 0;
	while (s[++(splat.i)])
	{
		if (s[splat.i] != c)
		{
			splat.len = 0;
			if (s[splat.i] == '\'')
			{
				splat.i++;
				while (s[splat.i + splat.len] != '\'')
					splat.len++;
			}
			else
			{
				while (s[splat.i + splat.len] != c && s[splat.i + splat.len])
					splat.len++;
			}
			write_words(&splat, arr, s);
		}
		if (!s[splat.i])
			break ;
	}
}

char	**ft_split_quote(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (0);
	words = countwords_quote(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (0);
	fillarr_quote(arr, s, c);
	arr[words] = 0;
	return (arr);
}
