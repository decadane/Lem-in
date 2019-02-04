/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:49:40 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/04 18:05:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

 void print_matrix(unsigned char **cross_m)
{
	int i;
	int j;

	i = 0;
	while (cross_m[i])
	{
		j = 0;
		while (cross_m[i][j])
		{
			//k = 8;
			//while (--k)
			//{
				//printf("%d", cross_m[i][j] & (1 << k));
				//ft_putnbr(cross_m[i][j] & ((unsigned char)1 << k));
				//cross_m[i][j] <<= 1;
			//}
			ft_putnbr((int)cross_m[i][j]);
			ft_putchar('\n');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

static int		check_cross(t_path **paths, unsigned char **matrix, int i, int j)
{
	t_path *r1;
	t_path *r2;

	if (i == j)
		return (1);
	if (i > j)
		return (1 & (matrix[j][i / 8] >> (7 - i % 8)));
	r2 = paths[j];
	while (r2)
	{
		r1 = paths[i];
		while (r1)
		{
			if (r1->room == r2->room && r1->room->state >= 0)
				return (1);
			r1 = r1->next;
		}
		r2 = r2->next;
	}
	return (0);
}

unsigned char			**make_cross_matrix(t_path **paths, int l) // Составляю матрицу пересечений путей. 1 - есть пересечение между двумя путями, 0 - нет.
{
	int				i;
	int				ii;
	int				j;
	unsigned char	**matrix;

	i = 0;
	matrix = (unsigned char**)malloc(sizeof(unsigned char*) * (l + 1));
	while (i < l)
	{
		j = 0;
		ii = -1;
		matrix[i] = (unsigned char*)malloc(sizeof(unsigned char) * (l / 8) + (l % 8) ? 2 : 1);
		while (j < l)
		{
			if (!(j % 8))
				ii++;
			matrix[i][ii] |= check_cross(paths, matrix, i, j);
			matrix[i][ii] <<= 1;
			j++;
		}
		matrix[i][ii] |= (unsigned char)1;
		j = (7 - (j % 8));
		while (j)
		{
			matrix[i][ii] <<= 1;
			matrix[i][ii] |= (unsigned char)1;
			j--;
		}
		matrix[i][ii + 1] = 0;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
