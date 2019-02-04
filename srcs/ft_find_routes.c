/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:16:33 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/04 17:45:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
/*
int one_path(size_t *path_len)
{
	int		i;
	int		ind;
	size_t	min;

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
*/

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
	res += (ants % p_num) ? ants / p_num : ants / p_num - 1;
	return (res);
}

int     no_crosses(unsigned char **cross_m, int *res, int j, int mv)
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

int		*recursion(t_path_set *set, int *res, unsigned char **cross_m, int ants, int n)
{
	int i;
	int ii;
	int mv;
	int *res2;
	
	i = 0;
	while (res[i] != -1)
		i++;
	res[i] = n;
	n += (n < 0) ? 1 : 0;
	mv = 8 - n % 8;
	n = n / 8;
	//printf("\nthis is n: %d\n", n);
	//printf("\nthis is ints: %d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
	//printf("\nthis is mv: %d\n", mv);
	while (cross_m[res[0]][n])
	{
		while (mv--)
		{
			if (no_crosses(cross_m, res, n, mv))
			{
				ii = n * 8 + (7 - mv);
				//printf("\nthis is ii: %d\n", ii);
				res2 = recursion(set, res, cross_m, ants, ii);
				if (total_path_len(res2, ants, set->lens) < total_path_len(res, ants, set->lens))
				{
					free(res);
					res = res2;
				}
			}
		}
		n++;
		mv = 8;
	}
	return (res);
}


int		*check_path_len(unsigned char **cross_m, t_path_set *set, int i, int ants)
{
	int				*res;
	unsigned long	j;

	j = 0;
	res = (int*)malloc(sizeof(int) * (set->num_of_paths + 1));
	while (j <= set->num_of_paths)
		res[j++] = -1;
	res[0] = i;
	res = recursion(set, res, cross_m, ants, -1);
	return (res);
}


int		*find_best_path(size_t ants, t_path_set *set, unsigned char **cross_m) // Ищу лучшее решение: либо 1 самый короткий путь, либо комбинация из 2х и больше непересекающихся путей.
{
	int		min;
//	int		ind;
	int		*res;
	int		*res2;
	size_t	i;

	i = 0;
//	ind = one_path(set->lens); // находим один путь с минимальным кол-вом шагов
	min = (set->lens)[0] + ants - 1; //узнаем, за сколько ходов мы прогоним всех муравьев по одному самому короткому пути

	//write(1, "2", 1);
	res = (int*)malloc(sizeof(int) * 2);
	res[0] = 0;
	res[1] = -1;
	i = 0;
	//write(1, "3", 1);
	while (i < set->num_of_paths)
	{
		//write(1, "4", 1);
		res2 = check_path_len(cross_m, set, i, ants); // проверяем кол-во ходов, если использовать несколько непересекающихся путям
	
	
	//	int k = 0;
	//	while (res2[k] != -1)
	//	printf("LOOK:  %d  \n", res2[k++]);
	
	
	//printf("\nTHIS IS MIN: %d", min);
//	printf("\nTHIS IS NEW_PATH_LEN: %d\n", total_path_len(res2, ants, set->lens));
		if (total_path_len(res2, ants, set->lens) < min)
		{
			//write(1, "YES\n", 4);
			free(res);
			res = res2;
			min = total_path_len(res, ants, set->lens);
		}
		else
			free(res2);
		i++;
		//write(1, "7\n", 2);
	}
	return (res);
}



void	find_paths(int ants_c, t_path_set *set) // Получаю все возможные пути. Поиск решения
{
	int					*best;
	t_path_set			*res;
	unsigned char		**cross_m;
	int					i;
	int					j;

	cross_m = make_cross_matrix(set->paths, set->num_of_paths); // Матрица пересечений между всеми путями
	//write(1, "1", 1);
	best = find_best_path(ants_c, set, cross_m); // Получаю массив путей, которые буду использовать
	//write(1, "10", 2);
	i = 0;
	while (best[i] != -1)
	{
		//ft_putnbr(best[i]);
		//ft_putchar('\n');
		i++;
	}
	//write(1, "11\n", 3);
	res = (t_path_set*)malloc(sizeof(t_path_set));
	res->paths = (t_path**)malloc(sizeof(t_path*) * i + 1);
	res->num_of_paths = i;
	//printf("-----%i----\n", i);
	res->lens = (size_t*)malloc(sizeof(size_t) * i);
	res->ants = (size_t*)malloc(sizeof(size_t) * i);
	j = 0;
	while (j < i)
	{
		(res->paths)[j] = (set->paths)[best[j]];
		(res->lens)[j] = (set->lens)[best[j]];
		(res->ants)[j] = 0;
		j++;
		//write(1, "\n12", 3);
	}
	move_ants(ants_c, res);
}
