/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:36:25 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/05 17:44:06 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_rooms_reverse(t_room **rooms)
{
	t_room	*prev;
	t_room	*current;
	t_room	*next;

	if (rooms && *rooms)
	{
		prev = NULL;
		current = *rooms;
		next = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*rooms = prev;
	}
}
