/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_this_shit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:52:38 by marvin            #+#    #+#             */
/*   Updated: 2019/01/31 20:58:12 by marvin           ###   ########.fr       */
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

t_farm	*ft_init_farm(void)
{
	t_farm	*new_farm;
	t_room	*room0;
	t_room	*room1;
	t_room	*room2;
	t_room	*room3;
	t_room	*room4;
	t_room	*room5;
	t_room	*room6;
	t_room	*room7;

	new_farm = (t_farm*)malloc(sizeof(t_farm));
	new_farm->rooms_count = 8;
	new_farm->rooms = NULL;
	room7 = new_farm->rooms = ft_init_room(new_farm->rooms, "Finish", END, 7);
	room6 = new_farm->rooms = ft_init_room(new_farm->rooms, "fuck", 0, 6);
	room5 = new_farm->rooms = ft_init_room(new_farm->rooms, "ebst", 0, 5);
	room4 = new_farm->rooms = ft_init_room(new_farm->rooms, "huyak", 0, 4);
	room3 = new_farm->rooms = ft_init_room(new_farm->rooms, "trhogoro", 0, 3);
	room2 = new_farm->rooms = ft_init_room(new_farm->rooms, "ffahey", 0, 2);
	room1 = new_farm->rooms = ft_init_room(new_farm->rooms, "kmedhurs", 0, 1);
	room0 = new_farm->rooms = ft_init_room(new_farm->rooms, "Start", START, 0);
	room0->links = (t_room**)malloc(sizeof(t_room*) * 2);
	room0->links[0] = room1;
	room0->links[1] = room4;
	room0->degree = 2;
	room1->links = (t_room**)malloc(sizeof(t_room*) * 3);
	room1->links[0] = room0;
	room1->links[1] = room2;
	room1->links[2] = room6;
	room1->degree = 3;
	room2->links = (t_room**)malloc(sizeof(t_room*) * 3);
	room2->links[0] = room1;
	room2->links[1] = room3;
	room2->links[2] = room5;
	room2->degree = 3;
	room3->links = (t_room**)malloc(sizeof(t_room*) * 2);
	room3->links[0] = room2;
	room3->links[1] = room7;
	room3->degree = 2;
	room4->links = (t_room**)malloc(sizeof(t_room*) * 2);
	room4->links[0] = room0;
	room4->links[1] = room5;
	room4->degree = 2;
	room5->links = (t_room**)malloc(sizeof(t_room*) * 2);
	room5->links[0] = room2;
	room5->links[1] = room4;
	room5->degree = 2;
	room6->links = (t_room**)malloc(sizeof(t_room*) * 2);
	room6->links[0] = room1;
	room6->links[1] = room7;
	room6->degree = 2;
	room7->links = (t_room**)malloc(sizeof(t_room*) * 2);
	room7->links[0] = room3;
	room7->links[1] = room6;
	room7->degree = 2;
	new_farm->ants_count = 4;
	new_farm->ants = NULL;
	return (new_farm);
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
		printf("Room: %d, Name: %s", farm->rooms->id, farm->rooms->name);
		j = -1;
		while (++j < farm->rooms->degree)
			printf(" Ptr: %d", farm->rooms->links[j]->id);
		printf("\n");
		farm->rooms = farm->rooms->next;
	}
	farm->rooms = tmp;
}
