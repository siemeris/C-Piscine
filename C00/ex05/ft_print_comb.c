/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:08:57 by issierra          #+#    #+#             */
/*   Updated: 2023/08/13 17:36:27 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	imprimir(int i, int j, int k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i != '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;

	i = '0';
	j = '0';
	k = '0';
	while (i <= '9')
	{
		while (j <= '9')
		{
			while (k <= '9')
			{
				if (i < j && j < k)
				{
					imprimir(i, j, k);
				}
				k++;
			}
			j++;
			k = '0';
		}
		i++;
		j = '0';
	}
}
