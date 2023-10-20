/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:13:33 by issierra          #+#    #+#             */
/*   Updated: 2023/08/13 22:49:42 by lsirpa-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	imprimirlineas(char esquinas, char intermedio, int x)
{
	int	max;

	max = x;
	while (x > 0)
	{
		if (x != max && x != 1)
		{
			ft_putchar(intermedio);
		}
		else
		{
			ft_putchar(esquinas);
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
		if (y == filas)
		{
			imprimirlineas('A', 'B', x);
		}
		else if (y == 1)
		{
			imprimirlineas('C', 'B', x);
		}
		else
		{
			imprimirlineas('B', ' ', x);
		}
		y--;
	}
}
