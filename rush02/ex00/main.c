/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:38:53 by issierra          #+#    #+#             */
/*   Updated: 2023/08/27 17:45:47 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*find_number(char *buffer, int num);

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	return (num);
}

void	dic_info(int num)
{
	int		fd1;
	char	buffer[500];
	int		numbytes;

	fd1 = open("numbers.dict", O_RDWR);
	if (fd1 == -1)
	{
		write(1, "Dict Error\n", 11);
	}
	else
	{
		numbytes = read(fd1, &buffer, 351);
		if (numbytes == 0)
		{
			write (1, "Error\n", 1);
		}
		else
			find_number(buffer, num);
	}
	close(fd1);
}

int	ft_strlen(char *argv[])
{
	int	longnum;

	longnum = 0;
	while (argv[1][longnum] != '\0')
	{
		longnum++;
	}
	return (longnum);
}

void	check_arguments(char *argv[])
{
	int	i;
	int	len;
	int	num;

	i = 0;
	num = 0;
	len = ft_strlen(argv);
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < 48 || argv[1][i] > 57)
		{
			write(1, "Error\n", 6);
		}
		if (i == len - 1)
		{
			num = ft_atoi(argv[1]);
			dic_info(num);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	len;
	int	num;

	len = 0;
	i = 0;
	num = 0;
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		check_arguments(argv);
	return (0);
}
