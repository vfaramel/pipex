/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:31:24 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/24 02:54:53 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n1;
	long	c;
	long	z;

	n1 = n;
	if (n1 < 0)
	{
		n1 *= -1;
		ft_putchar_fd('-', fd);
	}
	c = 10;
	while (c <= n1)
		c *= 10;
	c /= 10;
	while (c > 0)
	{
		z = (n1 / c % 10) + 48;
		ft_putchar_fd(z, fd);
		c /= 10;
	}
}
