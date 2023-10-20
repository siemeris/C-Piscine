/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirpa-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:40:20 by lsirpa-g          #+#    #+#             */
/*   Updated: 2023/08/13 22:49:31 by lsirpa-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_roof(int ancho, char cornerl, char cornerr, char fill)
{
	int	j;

	j = 2;
	if (ancho > 0)
	{
		ft_putchar(cornerl);
		while (ancho > j++)
			ft_putchar(fill);
		if (ancho != 1)
			ft_putchar(cornerr);
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
	char	cornerl;
	char	cornerr;
	int		f;

	f = 1;
	cornerl = '/';
	cornerr = '\\';
	if (alto > 1)
	{
		while (2 > f++)
		{
			print_roof(ancho, cornerl, cornerr, '-');
			print_walls(alto, ancho, '|');
			print_roof(ancho, cornerr, cornerl, '-');
		}
	}
	else
	{
		print_roof(ancho, cornerl, cornerr, '-');
	}
}
