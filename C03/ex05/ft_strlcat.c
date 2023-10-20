/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:04:14 by issierra          #+#    #+#             */
/*   Updated: 2023/08/24 15:57:02 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	lendest;
	unsigned int	lensrc;
	unsigned int	i;
	unsigned int	k;
	unsigned int	j;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	i = 0;
	j = 0;
	k = lendest;
	if (size > lendest)
	{
		while (src[i] != '\0' && j < size - lendest - 1)
		{
			dest[k] = src[i];
			k++;
			i++;
			j++;
		}
		dest[k] = '\0';
		return (lendest + lensrc);
	}
	return (lensrc + size);
}
