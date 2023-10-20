/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:04:14 by issierra          #+#    #+#             */
/*   Updated: 2023/08/21 15:14:16 by issierra         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	lendest;
	int	i;

	i = 0;
	lendest = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[lendest] = src[i];
		lendest++;
		i++;
	}
	dest[lendest] = '\0';
	return (dest);
}
