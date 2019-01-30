/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_farm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:10:03 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/30 17:35:39 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_farm		*ft_init_farm(t_farm **farm)
{
	char	*input_data;

	while (get_next_line(0, &input_data))
	{
		printf("\t%s\n", input_data);
	}
	return (NULL);
}
