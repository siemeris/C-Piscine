/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:13:33 by issierra          #+#    #+#             */
/*   Updated: 2023/08/13 22:49:50 by lsirpa-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	imprimirlineas(char esquina1, char esquina2, char intermedio, int x)
{
	int	max;

	max = x;
	while (x > 0)
	{
		if (x == max)
		{
			ft_putchar(esquina1);
		}
		else if (x == 1)
		{
			ft_putchar(esquina2);
		}
		else
		{
			ft_putchar(intermedio);
		}
		x--;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	filas;
	int	columnas;

	filas = y;
	columnas = x;
	while (y > 0)
	{
		if (y == filas || y == 1)
		{
			imprimirlineas('A', 'C', 'B', x);
		}
		else
		{
			imprimirlineas('B', 'B', ' ', x);
		}
		y--;
	}
}
