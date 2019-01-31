/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:18:10 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/31 20:53:30 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"


t_farm	*ft_create_farm()
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

char		**ft_ants_generator(size_t	size)
{
	char	**ants;
	size_t	i;

	if (!(ants = (char**)malloc(sizeof(char*) * (size + 1))))
		exit(OUT_OF_MEMORY);
	i = 0;
	while (i <= size)
	{
		ants[i] = NULL;
		i++;
	}
	return (ants);
}

t_room		*ft_create_room(char **tab)
{
	t_room	*room;

	room = NULL;
	if (tab)
	{
		if (!(room = (t_room*)malloc(sizeof(t_room))))
			exit(OUT_OF_MEMORY);
		room->name = tab[0];
		room->links = NULL;
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
		new_room = ft_create_room(data);
		new_room->next = farm->rooms;
		farm->rooms = new_room;
		if (farm->start && ft_strcmp(farm->start, START_STR) == 0)
			farm->start = new_room->name;
		if (farm->end && ft_strcmp(farm->end, END_STR) == 0)
			farm->end = new_room->name;
	}
}


