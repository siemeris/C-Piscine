/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:07:00 by issierra          #+#    #+#             */
/*   Updated: 2023/08/13 17:54:15 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	imprimir(int i, int j)
{
	char	asciii1;
	char	asciii2;
	char	asciij1;
	char	asciij2;

	asciii1 = i / 10 + '0';
	asciii2 = i % 10 + '0';
	asciij1 = j / 10 + '0';
	asciij2 = j % 10 + '0';
	write(1, &asciii1, 1);
	write(1, &asciii2, 1);
	write(1, " ", 1);
	write(1, &asciij1, 1);
	write(1, &asciij2, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{	
		j = 0;
		while (j <= 99)
		{
			if (j > i)
			{
				imprimir(i, j);
				if (i != 98)
				{
					write(1, ", ", 2);
				}		
			}
			j++;
		}
	i++;
	}
}
