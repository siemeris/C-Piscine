/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:08:05 by issierra          #+#    #+#             */
/*   Updated: 2023/08/20 19:31:28 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	fix_values(int *bor);

void	borders(char *argv, int *bor)
{
	int	contador;

	contador = 0;
	while (*argv != '\0')
	{
		if (*argv <= '4' && *argv > '0')
		{
			*bor = *argv - '0';
			contador++;
			bor++;
		}
		else if (*argv != 32)
		{
			write(1, "Error\n", 6);
			return ;
		}
		argv++;
	}
	if (contador != 16)
	{
		write(1, "Error\n", 6);
		return ;
	}
}

void	check_borders(char *argv)
{
	int	*bor;
	int	contador;
	int	i;

	i = 0;
	contador = 0;
	bor = (int *) malloc (4 * 16);
	borders(argv, bor);
	bor = bor - contador;
	while (i < 12)
	{
		if (!((bor[i] + bor[i + 4]) >= 3 && (bor[i] + bor[i + 4]) <= 5))
		{
			write(1, "Error\n", 6);
			return ;
		}
		i++;
	}
	fix_values(bor);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		argv++;
		check_borders(*argv);
	}	
	else
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
