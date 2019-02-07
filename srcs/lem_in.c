/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:20:07 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/07 20:34:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_farm		*farm;
	t_path_set	*set;
	int			num_of_paths;
	int			i;
	t_room		*start;
	t_room		*end;
	t_room		*tmp;

	i = -1;
	farm = NULL;
	set = NULL;
	farm = ft_init_farm();
	tmp = farm->rooms;
	while (++i < (int)farm->rooms_count)
	{
		if (farm->rooms->state == START_ROOM)
			start = farm->rooms;
		farm->rooms = farm->rooms->next;
	}
	farm->rooms = tmp;
	i = -1;
	while (++i < (int)farm->rooms_count)
	{
		if (farm->rooms->state == END_ROOM)
			end = farm->rooms;
		farm->rooms = farm->rooms->next;
	}
	farm->rooms = tmp;
	num_of_paths = MIN(MIN((int)farm->ants_count, start->degree), end->degree);
	ft_print_farm(farm);
	set = ft_start_bfs(farm, num_of_paths);
	if (!set)
		ft_error_output(farm, "No possible solutions");
	ft_farm_destroyer(farm);
	return (0);
}
