/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:20:07 by ffahey            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/02/04 20:35:36 by marvin           ###   ########.fr       */
=======
/*   Updated: 2019/02/04 17:36:36 by marvin           ###   ########.fr       */
>>>>>>> b26f5bcbad3bd6c386ff443e608ecfd7f8a2a791
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main()
{
	t_farm		*farm;
	t_path_set	*set;
	int			i;

	farm = NULL;
	i = 0;
	farm = ft_init_farm();
//	ft_print_farm(farm);
	set = ft_start_bfs(farm);
/*	while (i < (int)set->num_of_paths)
	{
		ft_print_path(set->paths[i]);
		printf(", Len: %zu, Ants: %zu\n", set->lens[i], set->ants[i]);
		i++;
	}
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
//	solution = ft_ants_power(farm);
*/	
	find_paths(farm->ants_count, set);
	ft_farm_destroyer(farm);
	return (0);
}
