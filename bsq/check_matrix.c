/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:43:51 by issierra          #+#    #+#             */
/*   Updated: 2023/08/30 17:39:49 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_and(int **mat_ones)
{
	int	i;
	int	j;
	int	dim;

	dim = 1;
	i = 0;
	j = 0;
	while (i < 9 - 1)
	{
		j = 0;
		while (j < 27)
		{
			printf("%i", mat_ones[i][j] && mat_ones[i + 1][j]);
			j++;
		}
		printf("\n");
		dim++;
		i++;
	}
}

int	**transform_matrix(char **mat, int *dim, char *mapa)
{
	int		i;
	int		j;
	int		**mapa_ones;

	i = 0;
	j = 0;
	mapa_ones = (int **)malloc(sizeof(int *) * dim[0]);
	while (i < dim[0])
	{
		mapa_ones[i] = malloc(sizeof(int) * dim[1]);
		j = 0;
		while (j < dim[1])
		{
			if (mat[i][j] == mapa[1])
				mapa_ones[i][j] = 1;
			else
				mapa_ones[i][j] = 0;
			j++;
		}
		i++;
	}
	return (mapa_ones);
}

int	*dimensions(char *mat)
{
	int	c;
	int	r;
	int	*dim;
	int	k;

	dim = malloc(sizeof(int) * 2);
	c = 0;
	r = 0;
	k = 0;
	while (mat[k + 5] != '\0')
	{
		c = 0;
		while (mat[k + 5] != '\n')
		{
			k++;
			c++;
		}
		k++;
		r++;
	}
	dim[0] = r;
	dim[1] = c;
	return (dim);
}

void	check_matrix(char **mat, char *mapa)
{
	int	i;
	int	j;
	int	**mat_ones;

	mat_ones = transform_matrix(mat, dimensions(mapa), mapa);
	j = 0;
	i = 0;
	while (i < dimensions(mapa)[0])
	{
		j = 0;
		while (j < dimensions(mapa)[1])
		{
			printf("%c", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	ft_and(mat_ones);
}
