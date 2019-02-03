/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:16:33 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/03 18:26:41 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int one_path(size_t *path_len)
{
	int i;
	int ind;
	int min;

	min = path_len[0];
	ind = 0;
	i = 1;
	while (path_len[i])
	{
		if (path_len[i] < min)
		{
			min = path_len[i];
			ind = i;
		}
		i++;
	}
	return(ind);
}


int		total_path_len(int *i, int ants, size_t *path_len)
{
	int p_num;
	int res;
	int len;

	len = 0;
	p_num = 0;
	while (i[p_num] != -1)
	{
		len += path_len[i[p_num]];
		p_num++;
	}
	res = (len % p_num) ? len / p_num + 1 : len / p_num;
	res += (ants % p_num) ? ants / p_num + 1 : ants / p_num;
	return (res);
}

int     no_crosses(char **cross_m, int *res, int j, int mv)
{
	int	ii;

	ii = 0;
	while (res[ii] != -1)
	{
		if (cross_m[res[ii]][j] >> mv & 1)
			return (0);
		ii++;
	}
	return (1);
}

int		*recursion(t_path_set *set, int *res, char **cross_m, int ants)
{
	int i;
	int ii;
	int mv;
	int *res2;
	int min_len;

	i = 0;
	while (cross_m[res[0]][i])
	{
		mv = 8;
		while (--mv)
		{
			if (no_crosses(cross_m, res, i, mv))
			{
				ii = 0;
				while (res[ii] != -1)
					ii++;
				res2 = (int*)malloc(ii + 2);
				ft_memcpy(res2, res, 4 * ii);
				res2[ii] = i * 8 + (7 - mv);
				res2[ii + 1] = -1;
				if (total_path_len(recursion(set, res2, cross_m, ants), ants, set->lens) < total_path_len(res, ants, set->lens))
				{
					free(res);
					res = res2;
				}
			}
		}
		i++;
	}
	return (res);
}


int		*check_path_len(char **cross_m, t_path_set *set, int i, int ants)
{
	int	*res;
	int	j;

	j = 0;
	res = (int*)malloc(sizeof(int) * 2);
	res[0] = i;
	res[1] = -1;
	res = recursion(set, res, cross_m, ants);
	return (res);
}


int		*find_best_path(size_t ants, t_path_set *set, char **cross_m) // Ищу лучшее решение: либо 1 самый короткий путь, либо комбинация из 2х и больше непересекающихся путей.
{
	int		min;
	int		ind;
	int		*res;
	int		*res2;
	int		i;

	i = 0;
	ind = one_path(set->lens); // находим один путь с минимальным кол-вом шагов
	min = (set->lens)[ind] + ants - 1; //узнаем, за сколько ходов мы прогоним всех муравьев по одному самому короткому пути
	write(1, "2", 1);
	res = (int*)malloc(sizeof(int));
	res[0] = ind;
	i = 0;
	write(1, "3", 1);
	while ((set->paths)[i])
	{
		res2 = check_path_len(cross_m, set, i, ants); // проверяем кол-во ходов, если использовать несколько непересекающихся путям
		if (total_path_len(res2, ants, set->lens) < min)
		{
			free(res);
			res = res2;
			min = total_path_len(res, ants, set->lens);
		}
		else
			free(res2);
		i++;
		write(1, "4", 1);
	}
	return (res);
}



void	find_paths(int ants_c, t_path_set *set) // Получаю все возможные пути. Поиск решения
{
	int			*best;
	t_path_set	*res;
	char		**cross_m;
	int			i;
	int			j;

	cross_m = make_cross_matrix(set->paths, set->num_of_paths); // Матрица пересечений между всеми путями
	write(1, "1", 1);
	best = find_best_path(ants_c, set, cross_m); // Получаю массив путей, которые буду использовать
	write(1, "1", 1);
	i = 0;
	while (best[i] != -1)
		i++;
	res = (t_path_set*)malloc(sizeof(t_path_set));
	res->paths = (t_path**)malloc(sizeof(t_path*) * i + 1);
	res->num_of_paths = i;
	res->lens = (size_t*)malloc(sizeof(size_t) * i);
	res->ants = (size_t*)malloc(sizeof(size_t) * i);
	j = 0;
	while (j < i)
	{
		(res->paths)[j] = (set->paths)[best[j]];
		(res->lens)[j] = (set->lens)[best[j]];
		(res->ants)[j] = 0;
	}
	move_ants(ants_c, res);
}
