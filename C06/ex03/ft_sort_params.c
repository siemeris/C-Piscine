/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:02:10 by issierra          #+#    #+#             */
/*   Updated: 2023/08/30 08:12:08 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

void	ft_print(int argc, char *argv[])
{
	int	j;
	int	i;

	j = 1;
	i = 0;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			write(1, &argv[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int	main(int argc, char *argv[])
{
	int		j;
	int		k;
	char	*temp;

	j = 1;
	k = 1;
	while (k < argc -1)
	{
		j = k + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[k], argv[j]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[k];
				argv[k] = temp;
			}
			j++;
		}
		k++;
	}
	ft_print(argc, argv);
}
