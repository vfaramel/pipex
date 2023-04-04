/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 04:22:35 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/26 05:46:21 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nlen(long n1)
{
	int	len;

	len = 0;
	if (n1 == 0)
		len++;
	while (n1 > 0)
	{
		n1 = n1 / 10;
		len++;
	}
	return (len);
}

void	fill(char *arr, long n1, int z)
{
	int	i;

	i = 0;
	if (n1 == 0)
		arr[z] = 48;
	while (n1 > 0)
	{
		arr[z] = n1 % 10 + 48;
		n1 /= 10;
		z--;
	}
}

char	*ft_itoa(int n)
{
	long	n1;
	int		z;
	int		len;
	char	*arr;

	z = 0;
	n1 = n;
	if (n1 < 0)
	{
		z++;
		n1 *= -1;
	}
	len = nlen(n1);
	arr = malloc((len + z + 1) * sizeof(char));
	if (!arr)
		return (0);
	if (z == 1)
		arr[0] = '-';
	arr[len + z] = '\0';
	fill(arr, n1, len + z - 1);
	return (arr);
}
