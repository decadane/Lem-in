/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:52:17 by marvin            #+#    #+#             */
/*   Updated: 2019/01/31 21:05:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_path		*ft_bfs(t_path *path, t_ps *ps, t_room *room)
{
	int		i;

	i = -1;
	path = ft_complete_path(path, room);
	ft_print_path(path);
	if (room->state > 5)
	{
		///////free path
		return (NULL);
	}
	if (room->state == END)
	{
		ps = ft_new_path(ps, path);
		return (0);
	}
	room->state += 5;
	while (++i < room->degree)
		ft_bfs(ft_copy_path(path), ps, room->links[i]);
	return (0);
}

t_ps		*ft_start_bfs(t_farm *farm)
{
	t_ps	*ps;
	t_path	*path;

	ps = NULL;
	path = NULL;
	path = ft_bfs(path, ps, &farm->rooms[0]);
	return (ps);
}
