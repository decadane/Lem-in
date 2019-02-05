/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifer_commands2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:40:05 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/05 17:40:20 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_rename_mod(t_farm *farm, char *mod)
{
	char	*data;
	char	**names;
	size_t	size;
	t_room	*room;

	get_next_line(0, &data);
	if (ft_is_comment(data))
		ft_error_output(farm, "After modifer must be valid line");
	if (!(names = ft_strsplit(data, ' ')))
		exit(OUT_OF_MEMORY);
	size = 0;
	while (names[size])
		size++;
	if (size != 2)
		ft_error_output(farm, "Wrong format for rename command");
	if (!(room = ft_find_room(farm->rooms, names[0])))
		ft_error_output(farm, "Room`s name doesn`t exist");
	if (names[1][0] == 'L' || names[1][0] == '#')
		ft_error_output(farm, "Invalid room`s name");
	if (ft_find_room(farm->rooms, names[1]))
		ft_error_output(farm, "Room`s name already exist");
	free(room->name);
	room->name = ft_strdup(names[1]);
	ft_free_tab(&names);
	free(data);
}

void	ft_edit_mod(t_farm *farm, char *mod)
{
	char	*data;
	size_t	size;
	t_room	*room;
	char	**names;

	get_next_line(0, &data);
	if (ft_is_comment(data))
		ft_error_output(farm, "After modifer must be valid line");
	if (!(names = ft_strsplit(data, ' ')))
		exit(OUT_OF_MEMORY);
	size = 0;
	while (names[size])
		size++;
	if (size != 3)
		ft_error_output(farm, "Wrong format for rename command");
	if (!(room = ft_find_room(farm->rooms, names[0])))
		ft_error_output(farm, "Room`s name doesn`t exist");
	if (!ft_is_str_integer(names[1]) || !ft_is_str_integer(names[2]))
		ft_error_output(farm, "Coords must be integer");
	room->x = ft_atoi(names[1]);
	room->y = ft_atoi(names[2]);
	ft_free_tab(&names);
	free(data);
}

void	ft_delete_mod(t_farm *farm, char *mod)
{
	char	*data;
	t_room	*room;
	t_room	*prev;

	get_next_line(0, &data);
	if (ft_is_comment(data))
		ft_error_output(farm, "After modifer must be valid line");
	if (!(room = ft_find_room(farm->rooms, data)))
		ft_error_output(farm, "Room`s name doesn`t exist");
	ft_room_delete(&farm->rooms, room);
	farm->rooms_count--;
	free(data);
}
