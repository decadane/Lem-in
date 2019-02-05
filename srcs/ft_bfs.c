/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:52:17 by marvin            #+#    #+#             */
/*   Updated: 2019/02/05 17:43:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			ft_bfs(t_path *path, t_ps **ps, t_room *room, size_t ac)
{
	int		i;

	i = -1;
	if (!ft_check_path(path, room->id))
	{
		ft_path_destroyer(path);
		return ;
	}
	path = ft_complete_path(path, room);
	if (room->state == END_ROOM)
	{
		*ps = ft_new_path(*ps, path);
		return ;
	}
	while (++i < room->degree)
	{
		ft_bfs(ft_copy_path(path), ps, room->links[i], ac);
	}
	ft_path_destroyer(path);
}

static void			ft_sort_path_set(t_path_set *set)
{
	size_t	tmp_st;
	t_path	*tmp_p;
	int		i;
	int		j;

	i = -1;
	while (++i < (int)set->num_of_paths)
	{
		j = -1;
		while (++j < (int)set->num_of_paths - i - 1)
		{
			if (set->lens[j] > set->lens[j + 1])
			{
				tmp_st = set->lens[j];
				set->lens[j] = set->lens[j + 1];
				set->lens[j + 1] = tmp_st;
				tmp_p = set->paths[j];
				set->paths[j] = set->paths[j + 1];
				set->paths[j + 1] = tmp_p;
			}
		}
	}
}

static t_path_set	*ft_convert_to_arr(t_ps *ps)
{
	t_path_set	*set;
	int			i;
	t_ps		*tmp;

	i = -1;
	tmp = ps;
	set = (t_path_set*)malloc(sizeof(t_path_set));
	set->num_of_paths  = ft_num_paths(ps);
	if (set->num_of_paths == 0)
	{
		free(set);
		return (NULL);
	}
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
	ft_sort_path_set(set);
	ft_ps_destroyer(tmp);
	return (set);
}

t_path_set			*ft_start_bfs(t_farm *farm)
{
	t_ps		*ps;
	t_path		*path;
	t_path_set	*set;
	int			i;
	t_room		*tmp;

	i = -1;
	set = NULL;
	ps = NULL;
	path = NULL;
	tmp = farm->rooms;
	while (++i < (int)farm->rooms_count)
	{
		if (farm->rooms->state == START_ROOM)
		{
			ft_bfs(path, &ps, farm->rooms, farm->ants_count);
		}
		farm->rooms = farm->rooms->next;
	}
	farm->rooms = tmp;
	set = ft_convert_to_arr(ps);
	return (set);
}
