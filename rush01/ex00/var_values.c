/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:08:05 by issierra          #+#    #+#             */
/*   Updated: 2023/08/20 18:27:02 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	check_values(int *tab, int **pos_tab);
void	get_table(int **tab);

void	check_if_border_two(int **pos_tab, int *bor)
{
	int	i;

	i = 0;
	while (bor[i] != '\0')
	{
		if (bor[i] == 2)
		{
			if (i >= 0 && i <= 3)
				pos_tab[0][i] = 1;
			else if (i >= 4 && i <= 7)
				pos_tab[3][i - 4] = 1;
			else if (i >= 8 && i <= 11)
				pos_tab[i - 8][0] = 1;
			else if (i >= 12 && i <= 15)
				pos_tab[i - 12][3] = 1;
		}
		i++;
	}
}

void	var_values(int **tab, int *bor)
{
	int	i;
	int	j;
	int	**pos_tab;

	pos_tab = (int **) malloc(8 * 4);
	i = 0;
	j = 0;
	while (i < 4)
	{
		pos_tab[i] = malloc(4 * 4);
		j = 0;
		while (j < 4)
		{
			pos_tab[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	check_if_border_two(pos_tab, bor);
}
