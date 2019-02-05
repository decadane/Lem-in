/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:20:07 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/05 17:44:18 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_farm	*farm;

	farm = NULL;
	farm = ft_init_farm(&farm);
	ft_print_farm_structure(farm);
	ft_farm_destroyer(farm);
	return (0);
}
