/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:28:00 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/05 17:43:24 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error_output(t_farm *farm, const char *error_message)
{
	ft_putstr("ERROR\n");
	ft_putstr(error_message);
	ft_putchar('\n');
	ft_farm_destroyer(farm);
	exit(0);
}
