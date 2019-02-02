/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:52:17 by marvin            #+#    #+#             */
/*   Updated: 2019/02/02 14:53:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void			ft_bfs(t_path *path, t_ps **ps, t_room *room, size_t ac)
{
	int		i;

	i = -1;
	if (!ft_check_path(path, room->id) || ft_path_len(path) > ac)
	{
		ft_path_destroyer(path);
		return ;
	}
	path = ft_complete_path(path, room);
	if (room->state == END)
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

static void			ft_sort_path_set(t_path_set *set, size_t len)
{
	size_t	tmp_st;
	t_path	*tmp_p;
	int		i;
	int		j;

	i = -1;
	while (++i < (int)len)
	{
		j = -1;
		while (++j < (int)len - i - 1)
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
	size_t		len;
	int			i;
	t_ps		*tmp;

	i = -1;
	tmp = ps;
	len = ft_num_paths(ps);
	set = (t_path_set*)malloc(sizeof(t_path_set));
	set->paths = (t_path**)malloc(sizeof(t_path*) * len);
	set->lens = (size_t*)malloc(sizeof(size_t) * len);
	set->ants = (size_t*)malloc(sizeof(size_t) * len);
	while (++i < (int)len)
	{
		set->paths[i] = ps->path;
		set->lens[i] = ft_path_len(ps->path);
		set->ants[i] = 0;
		ps = ps->next;
	}
	ft_sort_path_set(set, len);
	ft_ps_destroyer(tmp);
	return (set);
}

t_path_set			*ft_start_bfs(t_farm *farm)
{
	t_ps		*ps;
	t_path		*path;
	t_path_set	*set;

	set = NULL;
	ps = NULL;
	path = NULL;
	ft_bfs(path, &ps, &farm->rooms[0], farm->ants_count);
	set = ft_convert_to_arr(ps);
	return (set);
}
