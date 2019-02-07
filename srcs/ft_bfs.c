/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:52:17 by marvin            #+#    #+#             */
/*   Updated: 2019/02/07 21:37:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path_set	*ft_convert_to_arr(t_ps *ps)
{
	t_path_set	*set;
	int			i;
	t_ps		*tmp;

	if (!ps)
		return (NULL);
	i = -1;
	tmp = ps;
	set = (t_path_set*)malloc(sizeof(t_path_set));
	set->num_of_paths  = ft_num_paths(ps);
	set->paths = (t_path**)malloc(sizeof(t_path*) * set->num_of_paths);
	set->lens = (size_t*)malloc(sizeof(size_t) * set->num_of_paths);
	set->ants = (size_t*)malloc(sizeof(size_t) * set->num_of_paths);
	while (++i < (int)set->num_of_paths)
	{
		set->paths[i] = ps->path;
		set->lens[i] = ft_path_len(ps->path);
		set->ants[i] = 0;
		ps = ps->next;
	}
	ps = tmp;
//	ft_ps_destroyer(tmp);
	return (set);
}

static void			ft_bfs(t_path **room_queue, t_ps **path_queue, t_ps **result, int max_len)
{
	t_room	*room;
	t_path	*path;
	int		i;

	i = -1;
	path = ft_pop_path_line(path_queue);
	room = ft_pop_path(room_queue);
	if (!(ft_check_path(path, room->id)))
		return ;
	path = ft_complete_path(path, room);
	if ((int)ft_path_len(path) > max_len)
		return ;
	if (room->state == END_ROOM)
	{
		*result = ft_new_path(*result, path);
		return ;
	}
	while (++i < room->degree)
	{
		*room_queue = ft_complete_path(*room_queue, room->links[i]);
		*path_queue = ft_new_path(*path_queue, ft_copy_path(path));
	}
	ft_path_destroyer(path);
}

static void			ft_find_start_room(t_farm *farm, t_path **queue)
{
	int		i;
	t_room	*tmp;

	i = -1;
	tmp = farm->rooms;
	while (++i < (int)farm->rooms_count)
	{
		if (farm->rooms->state == START_ROOM)
			*queue = ft_complete_path(*queue, farm->rooms);
		farm->rooms = farm->rooms->next;
	}
	farm->rooms = tmp;
}

static int			ft_max_len(t_ps *result, int ac)
{
	int		num_of_paths;
	int		max_len;
	int		i;
	t_ps	*tmp;
	int		len_sum;

	if (!result)
		return (9999);
	tmp = result;
	i = 0;
	num_of_paths = ft_num_paths(result);
	len_sum = 0;
	while (i < num_of_paths)
	{
		len_sum += ft_path_len(result->path);
		result = result->next;
		i++;
	}
	result = tmp;
	max_len = ((len_sum + ac) / num_of_paths) * (num_of_paths + 1) - ac - len_sum;
	return (max_len);
}

t_path_set			*ft_start_bfs(t_farm *farm, int nop)
{
	t_ps	*path_queue;
	t_path	*queue;
	int		min_paths;
	t_ps	*result;
	t_path_set	*set;

	path_queue = NULL;
	queue = NULL;
	result = NULL;
	ft_find_start_room(farm, &queue);
	min_paths = 1;
	while (queue)
	{
		ft_bfs(&queue, &path_queue, &result, ft_max_len(result,
					farm->ants_count));			
		if ((int)ft_num_paths(result) == min_paths)
		{
			set = ft_convert_to_arr(result);
			set->ants_count = farm->ants_count;
			set = find_paths(farm->ants_count, set, nop);
			if ((int)set->num_of_paths >= nop)
				return (set);
			else
				min_paths += DELTA_PATHS;
		}
	}
	nop = 0;
	set = ft_convert_to_arr(result);
	set->ants_count = farm->ants_count;
	set = find_paths(farm->ants_count, set, nop);
	return (set);
}
