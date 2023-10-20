/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:08:05 by issierra          #+#    #+#             */
/*   Updated: 2023/08/20 18:38:20 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>  
#include <stdlib.h> 

void	var_values(int **tab, int *bor);
void	get_table(int **tab1);

void	put_values_up(int **tab, int x, int i, int z)
{
	while (z < 4)
	{
		tab[z][i - x] = z + 1;
		z++;
	}
}

void	put_values_down(int **tab, int i, int z)
{
	while (z < 4)
	{
		tab[z][i - 4] = 4 - z;
		z++;
	}
}

void	casefour(int **tab, int i)
{	
	int	z;

	if (i >= 0 && i <= 3)
		put_values_up(tab, 0, i, 0);
	else if (i >= 4 && i <= 7)
		put_values_down(tab, i, 0);
	else if (i >= 8 && i <= 11)
	{
		z = 0;
		while (z < 4)
		{
			tab[i - 8][z] = z + 1;
			z++;
		}
	}
	else if (i >= 12 && i <= 15)
	{
		z = 0;
		while (z < 4)
		{
			tab[i - 12][z] = 4 - z;
			z++;
		}
	}
}

void	case_four_and_one(int **tab, int *bor)
{
	int	i;

	i = 0;
	while (bor[i] != '\0')
	{
		if (bor[i] == 4)
			casefour(tab, i);
		if (bor[i] == 1)
		{
			if (i >= 0 && i <= 3)
				tab[0][i] = 4;
			else if (i >= 4 && i <= 7)
				tab[3][i - 4] = 4;
			else if (i >= 8 && i <= 11)
				tab[i - 8][0] = 4;
			else if (i >= 12 && i <= 15)
				tab[i - 12][3] = 4;
		}
	i++;
	}
}

void	fix_values(int *bor)
{
	int	**tab;
	int	i;
	int	j;

	tab = (int **)malloc(8 * 4);
	i = 0;
	j = 0;
	while (i < 4)
	{
		tab[i] = malloc(sizeof(int) * 4);
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	case_four_and_one(tab, bor);
	get_table(tab);
	var_values(tab, bor);
}
