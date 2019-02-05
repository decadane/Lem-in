/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:49:40 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/04 20:12:10 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"


void	print_bits(unsigned char octet)
{
	int				x;
	char			res[8];

	x = 8;
	while (x--)
	{
		res[x] = (octet % 2) ? '1' : '0';
		octet = octet / 2;
	}
	write(1, res, 8);
}



 void print_matrix(unsigned char **cross_m, int l)
{
	int i;
	int j;
	int len;
	
	len = l / 8;
	len += (l % 8) ? 1 : 0;
	ft_putnbr(l);
	ft_putstr("\n\n");
	
	ft_putnbr(len);
	ft_putstr("\n\n");
	i = 0;
	while (i < l)
	{
		j = 0;
		while (j < len)
		{
			print_bits(cross_m[i][j]);
			//ft_putnbr((int)cross_m[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putstr("\n\n");
	}
}

static unsigned char		check_cross(t_path **paths, unsigned char **matrix, int i, int j)
{
	t_path *r1;
	t_path *r2;

	if (i == j)
		return (1);
	if (matrix)
		r2 = 0;
	//if (i > j)
	//	return (matrix[j][i / 8] & ((unsigned char)1 << (7 - i % 7)));
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
	int				rows;
	int				chars;
	int				j;
	unsigned char	**matrix;
	unsigned char	check_c;

	rows = 0;
	matrix = (unsigned char**)malloc(sizeof(unsigned char*) * (l + 1));
	while (rows < l)
	{
		j = 0;
		chars = 0;
		matrix[rows] = (unsigned char*)malloc(sizeof(unsigned char) * ((l / 8) + (l % 8) ? 2 : 1));
		matrix[rows][chars] = 0;
		while (j < l)
		{
			if (j && !(j % 8))
				chars++;
			check_c = check_cross(paths, matrix, rows, j);
			check_c <<= (7 - j % 8);
			matrix[rows][chars] |= check_c;
			j++;
		}
		j = j % 8;
		while (j < 7)
		{
			matrix[rows][chars] |= (unsigned char)255 >> j;
			j++;
		}
		matrix[rows][chars + 1] = 0;
		rows++;
	}
	matrix[rows] = NULL;
	return (matrix);
}
