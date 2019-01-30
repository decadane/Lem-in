/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_this_shit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:52:38 by marvin            #+#    #+#             */
/*   Updated: 2019/01/30 19:36:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room	*ft_init_room(t_room *room, char *name, char state, int id)
{
	t_room	*new_room;

	new_room = (t_room*)malloc(sizeof(t_room));
	room->name = name;
	room->id = id;
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
