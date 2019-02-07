/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:20:07 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/07 13:26:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_farm		*farm;
	t_path_set	*set;

	farm = NULL;
	set = NULL;
	farm = ft_init_farm();
	ft_print_farm(farm);
	set = ft_start_bfs(farm);
	if (!set)
		ft_error_output(farm, "No possible solutions");
	ft_farm_destroyer(farm);
	return (0);
}
