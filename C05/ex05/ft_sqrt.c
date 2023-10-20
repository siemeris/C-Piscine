/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:03:19 by issierra          #+#    #+#             */
/*   Updated: 2023/08/31 11:28:41 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long int	num;

	num = 1;
	while (num * num <= nb)
	{
		if (num * num == nb)
			return (num);
		num++;
	}
	return (0);
}