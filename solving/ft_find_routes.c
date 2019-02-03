/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:16:33 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/03 14:11:06 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_path	**final_path(char **cross_m, t_path **paths, int ind, int sign)
{
	int		j;
	int		i;
	t_path	**res;

	if (!sign)
	{
		res = (t_path**)malloc(sizeof(t_path*) * 2);
		res[0] = paths[ind];
		res[1] = NULL;
		return (res);
	}
	j = 0;
	i = 1;
	while (cross_m[ind][j])
		if (cross_m[ind][j++] == 1)
			i++;
	res = (t_path**)malloc(sizeof(t_path*) * i + 1);
	res[0] = paths[ind];
	i = 1;
	j = 0;
	while (cross_m[ind][j])
	{
		if (cross_m[ind][j] == 1)
			res[i++] = paths[j];
		j++;
	}
	res[i] = NULL;
	return (res);
}

int		check_path_len(char **cross_m, int *path_len, int i, int ants)
{
	int res;
	int paths_num;
	int j;

	j = 0;
	paths_num = 1;
	res = (path_len[i]);
	while (cross_m[i][j])
	{
		if (cross_m[i][j] == 1)
		{
			res += path_len[j];
			paths_num++;
		}
		j++;
	}
	res = (res % paths_num) ? res / paths_num + 1 : res / paths_num;
	res += (ants % paths_num) ? ants / paths_num + 1 : ants / paths_num;
	return (res - 1);
}

int one_path(int *path_len)
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

t_path	**find_best_path(size_t ants, t_path **paths, int *path_len, char **cross_m) // Ищу лучшее решение: либо 1 самый короткий путь, либо комбинация из 2х и больше непересекающихся путей.
{
	int		min;
	int		min2;
	int		ind;
	int		i;
	int		sign;

	sign = 0;
	ind = one_path(path_len); // находим один путь с минимальным кол-вом шагов
	min = path_len[ind] + ants - 1; //узнаем, за сколько ходов мы прогоним всех муравьев по одному самому короткому пути
	i = 0;
	while (paths[i])
	{
		min2 = check_path_len(cross_m, path_len, i, ants); // проверяем кол-во ходов, если использовать несколько непересекающихся путям
		if (min2 < min)
		{
			sign = 1; // показывает, что вариант с одним самым коротким путем - не самый оптимальный
			min = min2;
			ind = i;
		}
		i++;
	}
	return (final_path(cross_m, paths, ind, sign));
}

void	find_paths(int ants_c, t_path_set *set) // Получаю все возможные пути. Поиск решения
{
	t_path		**best;
	char		**cross_m;
	int			l;
	int			i;
	int			*assigned_ants;

	cross_m = make_cross_matrix(set->paths, set->num_of_paths); // Матрица пересечений между всеми путями
	best = find_best_path(ants_c, set->paths, set->lens, cross_m); // Получаю массив путей, которые буду использовать
	l = 0;
	i = 0;
	while (best[l])
		l++;
	assigned_ants = (int*)malloc(sizeof(int) * l + 1);
	while (i < l)
		assigned_ants[i] = 0;
	move_ants(ants_c, best, assigned_ants, l);



}
