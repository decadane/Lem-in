/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:22:08 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/31 21:09:48 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_rooms_destroyer(t_room **room)
{
	t_room	*tmp;

	if (room && *room)
	{
		while (*room)
		{
			tmp = (*room)->next;
			free((*room)->name);
			free((*room)->links);
			free(*room);
			*room = tmp;
		}
		free(*room);
		*room = NULL;
	}
}

void	ft_farm_destroyer(t_farm *farm)
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
