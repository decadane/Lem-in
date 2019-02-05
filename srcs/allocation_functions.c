/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:18:10 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/05 17:42:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


t_farm		*ft_create_farm()
{
	t_farm	*farm;

	farm = NULL;
	if (!(farm = (t_farm*)malloc(sizeof(t_farm))))
		exit(OUT_OF_MEMORY);
	farm->rooms_count = 0;
	farm->rooms = NULL;
	farm->start = NULL;
	farm->end = NULL;
	farm->ants_count = 0;
	farm->ants = NULL;
	return (farm);
}

void		ft_ants_generator(t_farm *farm)
{
	size_t	i;

	if (farm->ants_count == 0)
		ft_error_output(farm, "Ants count must be > 0");
	if (!(farm->ants = (char**)malloc(sizeof(char*) * (farm->ants_count + 1))))
		exit(OUT_OF_MEMORY);
	i = 0;
	while (i <= farm->ants_count)
	{
		farm->ants[i] = NULL;
		i++;
	}
}

t_room		*ft_create_room(char **tab)
{
	static	int	idd;
	t_room	*room;

	room = NULL;
	if (tab)
	{
		if (!(room = (t_room*)malloc(sizeof(t_room))))
			exit(OUT_OF_MEMORY);
		room->name = tab[0];
		room->links = NULL;
		room->id = idd++;
		room->degree = 0;
		room->x = ft_atoi(tab[1]);
		room->y = ft_atoi(tab[2]);
		room->state = 0;
		room->next = 0;
		free(tab[1]);
		free(tab[2]);
		free(tab);
	}
	return (room);
}

void		ft_add_room(t_farm *farm, char **data)
{
	t_room		*new_room;
	
	if (data)
	{
		if (ft_find_room(farm->rooms, data[0]))
		{
				ft_free_tab(&data);
				ft_error_output(farm, "Room`s name alredy exist");
		}
		new_room = ft_create_room(data);
		new_room->next = farm->rooms;
		farm->rooms = new_room;
	}
}
