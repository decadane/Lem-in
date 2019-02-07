/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:16:33 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/07 20:31:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_matrix(unsigned char **cross_m, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		free(cross_m[i]);
		i++;
	}
	free(cross_m);
}

static void		clear_all(unsigned char **matrix, t_path_set *res,
							int *arr, size_t path_num)
{
	int	i;

	free_matrix(matrix, path_num);
	free(arr);
	i = res->num_of_paths - 1;
	/*while (i >= 0)
	{
		free((res->paths)[i]);
		i--;
	}
	free(res->paths);
	free(res->lens);
	free(res->ants);
	free(res);
*/}

static int		find_num(int *best)
{
	int i;

	i = 0;
	while (best[i] != -1)
		i++;
	return (i);
}

t_path_set		*find_paths(int ants_c, t_path_set *set, int nop)
{
	int					*best;
	t_path_set			*res;
	unsigned char		**cross_m;
	size_t				j;

	cross_m = make_cross_matrix(set->paths, set->num_of_paths);
//	print_matrix(cross_m, set->num_of_paths);
	best = find_best_path(ants_c, set, cross_m);
	res = (t_path_set*)malloc(sizeof(t_path_set));
	res->num_of_paths = find_num(best);
	res->paths = (t_path**)malloc(sizeof(t_path*) *
	(res->num_of_paths + 1));
	res->lens = (size_t*)malloc(sizeof(size_t) * res->num_of_paths);
	res->ants = (size_t*)malloc(sizeof(size_t) * res->num_of_paths);
	j = 0;
	while (j < res->num_of_paths)
	{
		(res->paths)[j] = (set->paths)[best[j]];
		(res->lens)[j] = (set->lens)[best[j]];
		(res->ants)[j] = 0;
		j++;
	}
	(res->paths)[j] = NULL;
	if ((int)res->num_of_paths >= nop)
		move_ants(ants_c, res);
	//else
		//while (v_move_ants(ants_c, res))
			//somegraficfunction();
	clear_all(cross_m, res, best, set->num_of_paths);
	return (res);
}
