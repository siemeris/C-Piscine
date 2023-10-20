/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:12:26 by issierra          #+#    #+#             */
/*   Updated: 2023/08/28 09:45:55 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_length(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}	
	return (i);
}

int	ft_check_base(char *base, int len)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (len < 2)
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == 43 || base[i] == 45)
			return (1);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	int	mod;
	int	error;

	mod = 0;
	len = ft_length(base);
	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	error = ft_check_base(base, len);
	if (error == 1)
		return ;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		write(1, "-", 1);
	}
	if (nbr > (len - 1))
	{
		ft_putnbr_base(nbr / len, base);
	}
	mod = nbr % len;
	write(1, &base[mod], 1);
}
