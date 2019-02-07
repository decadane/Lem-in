/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_farm_structure.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:50:38 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/07 21:12:57 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_room(t_room *room)
{
	size_t	i;

	printf("Room \"%s\":\n", room->name);
	printf("id: %d\n", room->id);
	printf("Coords: %d %d\n", room->x, room->y);
	printf("State: %d\n", room->state);
	printf("Links count: %d\n", room->degree);
	printf("Links:\n");
	i = 0;
	while (room->links && room->links[i])
	{
		printf("\t%s(%d)\n", room->links[i]->name, room->links[i]->id);
		i++;
	}
}

void		ft_print_farm_structure(t_farm *farm)
{
	t_room	*room;

	if (!farm)
		return ;
	printf("Farm structure:\n");
	printf("\n1. GENERAL\n");
	printf("\tNumber of ants:  %lu\n", farm->ants_count);
	printf("\tNumber of rooms: %lu\n", farm->rooms_count);
	printf("\tStart room name: %s\n", farm->start);
	printf("\tEnd room name:   %s\n", farm->end);
	printf("\n2. ROOMS\n");
	room = farm->rooms;
	while (room)
	{
		ft_print_room(room);
		printf("\n");
		room = room->next;
	}
}
