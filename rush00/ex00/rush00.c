/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirpa-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:25:50 by lsirpa-g          #+#    #+#             */
/*   Updated: 2023/08/13 22:49:13 by lsirpa-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_roof(int ancho, char corners, char fill)
{
	int	j;

	j = 2;
	if (ancho > 0)
	{
		ft_putchar(corners);
		while (ancho > j++)
			ft_putchar(fill);
		if (ancho != 1)
			ft_putchar(corners);
		ft_putchar ('\n');
	}
}

void	print_walls(int alto, int ancho, char border)
{
	int	i;

	i = 2;
	while (alto-- > 2)
	{
		ft_putchar(border);
		while (ancho > i++)
			ft_putchar(' ');
		if (ancho != 1)
		{
			ft_putchar(border);
		}
		ft_putchar('\n');
	}
}

void	rush(int ancho, int alto)
{
	int		f;

	f = 1;
	if (alto > 1)
	{
		while (2 > f++)
		{
			print_roof(ancho, '*', '-');
			print_walls(alto, ancho, '|');
			print_roof(ancho, '*', '-');
		}
	}
	else
	{
		print_roof(ancho, '*', '-');
	}
}
