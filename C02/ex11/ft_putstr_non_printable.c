/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:43:28 by issierra          #+#    #+#             */
/*   Updated: 2023/08/21 11:17:54 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		mod;
	char	*hexa;

	i = 0;
	mod = 0;
	hexa = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (!(str[i] >= 0 && str[i] <= 31))
		{
			write(1, &str[i], 1);
		}	
		else
		{	
			write(1, "\\", 1);
			mod = str[i] % 16;
			if (str[i] / 16 == 0)
				write(1, "0", 1);
			if (str[i] / 16 == 1)
				write(1, "1", 1);
			write(1, &hexa[mod], 1);
		}
		i++;
	}
}
