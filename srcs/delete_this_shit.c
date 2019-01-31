/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_this_shit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:52:38 by marvin            #+#    #+#             */
/*   Updated: 2019/01/31 18:35:11 by marvin           ###   ########.fr       */
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
	room->name = name;
	room->id = id;
	room->links = NULL;
	room->x = 0;
	room->y = 0;
	room->state = state;
	new_room->next = room;
	room = new_room;
	return (room);
}

t_farm	*ft_init_farm(void)
{
	t_farm	*new_farm;

	new_farm = (t_farm*)malloc(sizeof(t_farm));
	new_farm->rooms_count = 8;
	new_farm->rooms = NULL;
	new_farm->rooms = ft_init_room(new_farm->rooms, "Start", START, 0);
	new_farm->rooms->links = NULL;
	new_farm->rooms = ft_init_room(new_farm->rooms, "kmedhurs", 0, 1);
	new_farm->rooms = ft_init_room(new_farm->rooms, "ffahey", 0, 2);
	new_farm->rooms = ft_init_room(new_farm->rooms, "trhogoro", 0, 3);
	new_farm->rooms = ft_init_room(new_farm->rooms, "huyak", 0, 4);
	new_farm->rooms = ft_init_room(new_farm->rooms, "ebst", 0, 5);
	new_farm->rooms = ft_init_room(new_farm->rooms, "fuck", 0, 6);
	new_farm->rooms = ft_init_room(new_farm->rooms, "Finish", END, 7);
	new_farm->ants_count = 4;
	new_farm->ants = NULL;
}

void	ft_print_farm(t_farm *farm)
{
	int		i;

	i = -1;
	while (++i < farm->rooms_count)
	{
		printf("Room: %d, Name: %s", farm->rooms->id, farm->rooms->name);
		while (farm->rooms->links)
		{
			printf(" Ptr: %d", farm->rooms->links->ptr->id);
			farm->rooms->links = farm->rooms->links->next;
		}
	}
}
