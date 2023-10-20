/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:33:12 by clagarci          #+#    #+#             */
/*   Updated: 2023/08/30 17:38:16 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	validation(char *mapa);

void	check_map(int error)
{
	if (error == -1)
		write(1, "map error\n", 10);
}

int	allocate(void)
{
	int		size;
	char	*prueba;
	int		file;
	int		cols;

	size = 1;
	cols = 0;
	prueba = malloc(1 * sizeof(char));
	file = open("example_file", O_RDONLY);
	if (file == -1)
		exit(1);
	else
	{
		while (read(file, prueba, 1) != '\0')
			size++;
	}
	close(file);
	return (size);
}

ssize_t	read_file(char **argv, int argc, char *map)
{
	int		file;
	ssize_t	file_bytes;
	int		i;

	i = 1;
	file_bytes = 0;
	if (argc > 1)
	{
		while (i < argc)
		{
			file = open(argv[i], O_RDONLY);
			if (file == -1)
				exit(1);
			file_bytes = read(file, map, allocate());
			close (file);
			check_map(validation(map));
			i++;
		}
	}
	return (file_bytes);
}

int	main(int argc, char **argv)
{
	int		file;
	ssize_t	file_bytes;
	char	*mapa;
	int		i;
	int		error;

	error = 0;
	i = 1;
	mapa = malloc(allocate() * sizeof(char));
	file_bytes = read_file(argv, argc, mapa);
	if (file_bytes == 0 || file_bytes == -1)
	{
		file = -1;
		write(1, "Error\n", 6);
	}
	free(mapa);
	return (0);
}
