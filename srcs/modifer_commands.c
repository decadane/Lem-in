/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifer_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:40:28 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/02 18:33:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_start_mod(t_farm *farm)
{
	char	*data;

	data = NULL;
	if (farm->start != NULL)
		ft_error_output(farm, "Double ##start modifer");
	get_next_line(0, &data);
	if (ft_is_comment(data))
		ft_error_output(farm, "After modifer must be valit line");
	if (ft_read_room(farm, data) != 3)
		ft_error_output(farm, "Wrong format for read room");
	farm->start = farm->rooms->name;
	farm->rooms->state = START_ROOM;
}

void	ft_end_mod(t_farm *farm)
{
	char	*data;

	data = NULL;
	if (farm->end != NULL)
		ft_error_output(farm, "Double ##end modifer");
	get_next_line(0, &data);
	if (ft_is_comment(data))
		ft_error_output(farm, "After modifer must be valit line");
	if (ft_read_room(farm, data) != 3)
		ft_error_output(farm, "Wrong format for read room");
	farm->end = farm->rooms->name;
	farm->rooms->state = END_ROOM;
}

