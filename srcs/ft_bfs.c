/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:52:17 by marvin            #+#    #+#             */
/*   Updated: 2019/02/07 13:34:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path_set	*ft_convert_to_arr(t_ps *ps)
{
	t_path_set	*set;
	int			i;
	t_ps		*tmp;

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
	ft_ps_destroyer(tmp);
	return (set);
}

static void			ft_bfs(t_path **room_queue, t_ps **path_queue, t_ps **result)
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
}

static t_path_set	*ft_check_solution(t_farm *farm, t_ps *result, int *i)
{
	t_path_set	*set;

	set = ft_convert_to_arr(result);
	if (find_paths(farm->ants_count, set))
		return (set);
	else
		i += 5;
	return (set);
}

static void			ft_find_start_room(t_farm *farm, t_path *queue)
{
	int		i;
	t_room	*tmp;

	i = -1;
	tmp = farm->rooms;
	while (++i < (int)farm->rooms_count)
	{
		if (farm->rooms->state == START_ROOM)
			queue = ft_complete_path(queue, farm->rooms);
		farm->rooms = farm->rooms->next;
	}
	farm->rooms = tmp;
}

t_path_set			*ft_start_bfs(t_farm *farm)
{
	t_ps	*path_queue;
	t_path	*queue;
	int		i;
	t_ps	*result;
	t_path_set	*set;

	path_queue = NULL;
	queue = NULL;
	result = NULL;
	ft_find_start_room(farm, queue);
	i = 5;
	while (queue)
	{
		ft_bfs(&queue, &path_queue, &result);			
		if ((int)ft_num_paths(result) == i)
			if ((set = ft_check_solution(farm, result, &i)) != NULL)
				return (set);
	}
	return (NULL);
}
