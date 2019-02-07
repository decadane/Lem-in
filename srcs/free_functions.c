/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:22:08 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/05 18:13:07 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	ft_free_room(t_room *room)
{
	free(room->name);
	free(room->links);
	free(room);
}

void			ft_room_delete(t_room **rooms, t_room *room)
{
	t_room	*prev;

	if (rooms && *rooms && room)
	{
		if (*rooms == room)
		{
			*rooms = (*rooms)->next;
			ft_free_room(room);
		}
		else
		{
			prev = *rooms;
			while (prev->next != room)
				prev = prev->next;
			if (prev == NULL)
				return ;
			prev->next = room->next;
			free(room);
		}
	}
}

void			ft_rooms_destroyer(t_room **room)
{
	t_room	*tmp;

	if (room && *room)
	{
		while (*room)
		{
			tmp = (*room)->next;
			ft_free_room(*room);
			*room = tmp;
		}
		*room = NULL;
	}
}

void			ft_farm_destroyer(t_farm *farm)
{
	if (farm)
	{
		if (farm->rooms)
			ft_rooms_destroyer(&(farm->rooms));
		if (farm->ants)
			free(farm->ants);
		free(farm);
	}
}
