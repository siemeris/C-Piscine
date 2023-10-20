/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:37:15 by issierra          #+#    #+#             */
/*   Updated: 2023/08/15 16:05:07 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	*inicio;
	int	temp;
	int	*fin;

	inicio = tab + 1;
	fin = tab + size -1;
	while (*tab && size > 0)
	{
		while (inicio <= fin)
		{
			if (*tab > *inicio)
			{
				temp = *inicio;
				*inicio = *tab;
				*tab = temp;
			}
			inicio++;
		}
		tab++;
		inicio = tab + 1;
		size--;
	}	
}
