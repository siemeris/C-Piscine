/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:52:16 by issierra          #+#    #+#             */
/*   Updated: 2023/08/31 08:50:24 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	last_num(int nb)
{
	write(1, "-", 1);
	write(1, "2", 1);
	nb = 147483648;
	return (nb);
}

void	ft_putnbr(int nb)
{
	int		num;

	if (nb == -2147483648)
	{
		nb = last_num(nb);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	num = nb % 10 + '0';
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	write(1, &num, 1);
}
