/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_this_shit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:52:38 by marvin            #+#    #+#             */
/*   Updated: 2019/02/02 19:23:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

t_room	*ft_search_node(t_room *room, int id)
{
	while (room)
	{
		if (room->id == id)
			return (room);
		room = room->next;
	}
	return (NULL);
}

t_room	*ft_init_room(t_room *room, char *name, char state, int id)
{
	t_room	*new_room;

	new_room = (t_room*)malloc(sizeof(t_room));
	new_room->name = name;
	new_room->id = id;
	new_room->links = NULL;
	new_room->x = 0;
	new_room->y = 0;
	new_room->state = state;
	new_room->next = room;
	room = new_room;
	return (room);
}

void	ft_print_farm(t_farm *farm)
{
	int		i;
	int		j;
	t_room	*tmp;

	i = -1;
	tmp = farm->rooms;
	while (++i < (int)farm->rooms_count)
	{
		printf("Degree: %d, ID: %d, State: %d", farm->rooms->degree, farm->rooms->id, farm->rooms->state);
		j = -1;
		while (++j < farm->rooms->degree)
			printf(" Ptr: %d", farm->rooms->links[j]->id);
		printf("\n");
		farm->rooms = farm->rooms->next;
	}
	farm->rooms = tmp;
}
