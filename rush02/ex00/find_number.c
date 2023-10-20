/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:32:21 by issierra          #+#    #+#             */
/*   Updated: 2023/08/27 17:54:22 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_result(int i, char *buffer)
{
	while (buffer[i] != '\n')
	{
		write(1, &buffer[i], 1);
		i++;
	}
}

char	*find_number(char *buffer, int num)
{
	int		i;
	int		j;
	char	*to_find;

	i = 0;
	j = 0;
	num = 40;
	to_find = "40";
	while (buffer[i] != '\0')
	{
		if (buffer[i] == to_find[j])
		{
			while (buffer[i + j] != '\0' && buffer[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
			{
				print_result(i, buffer);
			}
			else
				j = 0;
		}
		i++;
	}
	return (0);
}
