/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:20:07 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/31 21:04:27 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main()
{
	t_farm	*farm;
	char	*solution;

	
	
	farm = NULL;
	farm = ft_init_farm(&farm);
	printf("size of rooms = %lu\n", farm->rooms_count);
	t_room	*tmp = farm->rooms;
	while (tmp)
	{
		printf("%s: ", tmp->name);
		for(int i = 0; i < tmp->degree; i++)
			printf("%s ", tmp->links[i]->name);
		printf("\n");
		tmp = tmp->next;
	}
	printf("start name: %s\n", farm->start);
	printf("end name: %s\n", farm->end);
	printf("Ants count: %lu\n", farm->ants_count);
	ft_farm_destroyer(farm);
//	solution = ft_ants_power(farm);
	
	return (0);
}
