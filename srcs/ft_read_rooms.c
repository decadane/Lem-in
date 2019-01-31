/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:25:43 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/31 20:55:46 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_room	*ft_find_room(t_room *rooms, char *name)
{
		while (rooms)
		{
			if (ft_strcmp(rooms->name, name) == 0)
				return (rooms);
			rooms = rooms->next;
		}
		return (NULL);
}

static void		ft_link_rooms(t_room *r1, t_room *r2, size_t size)
{
	if (r1->links == NULL)
		r1->links = (t_room**)malloc(sizeof(t_room*) * size);
	if (r2->links == NULL)
		r2->links = (t_room**)malloc(sizeof(t_room*) * size);
	r1->links[(r1->degree)++] = r2;
	r1->links[(r1->degree)] = NULL;
	r2->links[(r2->degree)++] = r1;
	r2->links[(r2->degree)] = NULL;
}

int		ft_read_rooms(t_farm *farm, char **data)
{
	char		**tab;
	unsigned	size;
	int			limit;
	char		*defis;
	t_room		*room1;
	t_room		*room2;

	if (farm && data)
	{
		limit = 3;
		while (get_next_line(0, data))
		{
			if ((ft_is_modifer(*data, farm) && limit == 3) || ft_is_comment(*data))
				continue ;
			size = 0;
			if (limit == 3)
			{
				if (!(tab = ft_strsplit(*data, ' ')))
					exit(OUT_OF_MEMORY);
				while (tab[size])
					size++;
			}
			if (size == 3)
			{
				ft_add_room(farm, tab);
				farm->rooms_count++;
				continue ;
			}
			else if (size == 1)
			{
				free(tab[0]);
				free(tab);
				limit = 1;
			}
			if (limit == 1)
			{
				if (!(defis = ft_strchr(*data, '-')))	//error manegment
					return (0);
				*defis = '\0';
				room1 = ft_find_room(farm->rooms,*data);
				room2 = ft_find_room(farm->rooms, defis + 1);
				ft_link_rooms(room1, room2, farm->rooms_count); //error manegment
			}
		}
	}
	return (1);
}
