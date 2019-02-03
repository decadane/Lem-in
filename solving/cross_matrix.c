/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:49:40 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/03 14:15:58 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/* void print_matrix(char **cross_m)
{
	int i = 0;
	int j;

	while (cross_m[i])
	{
		j = 0;
		while (cross_m[i][j])
		{
			ft_putnbr((int)cross_m[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
} */

static int		check_cross(t_path **paths, char **matrix, int i, int j)
{
	int res;
	t_path *r1;
	t_path *r2;

	if (i == j)
		return (1);
	if (i > j)
		return (0 & (matrix[j][i / 8] >> (7 - i % 8)));
	r2 = paths[j];
	while (r2)
	{
		r1 = paths[i];
		while (r1)
		{
			if (r1->room == r2->room)
				return (1);
			r1 = r1->next;
		}
		r2 = r2->next;
	}
	return (0);
}

char			**make_cross_matrix(t_path **paths, int l) // Составляю матрицу пересечений путей. 1 - есть пересечение между двумя путями, 0 - нет.
{
	int		i;
	int		ii;
	int		j;
	int		count;
	char	**matrix;

	i = 0;
	matrix = (char**)malloc(sizeof(char*) * l + 1);
	while (i < l)
	{
		j = 0;
		ii = 0;
		count = 8;
		matrix[i] = (char*)malloc(sizeof(char) * (l / 8) + (l % 8) ? 1 : 0 + 1);
		while (j < l && count--)
		{
			matrix[i][ii] |= check_cross(paths, matrix, i, j);
			matrix[i][ii] <<= 1;
			j++;
			if (j < l && !count && ++ii)
				count = 8;
		}
		ii++;
		matrix[i][ii] = 0;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
