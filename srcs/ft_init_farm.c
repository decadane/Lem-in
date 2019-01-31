/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_farm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:10:03 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/31 20:30:04 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		ft_get_ants_count(t_farm *farm, char **data)
{
	int		check; 
	size_t	i;

	if (get_next_line(0, data) != 1)
		return 0;
	i = 0;
	while ((*data)[i])
	{
		if (!(ft_isdigit((*data)[i])))
			return 0;
		i++;
	}
	check = ft_atoi(*data);
	if (i != ft_strlen(ft_itoa(check)))
		return 0;
	else
		farm->ants_count = (size_t)check;
	if (!(farm->ants = ft_ants_generator(farm->ants_count)))
		exit (OUT_OF_MEMORY);
	return (1);
}

int				ft_is_modifer(char	*input_data, t_farm *farm)
{
	if (ft_strcmp(input_data, START_STR) == 0)
	{
		if (farm->start == NULL)
			farm->start = START_STR;
		else
		{
			free(input_data);
			ft_error_output(farm);
		}
		return (1);
	}
	else if (ft_strcmp(input_data, END_STR) == 0)
	{
		if (farm->end == NULL)
			farm->end = END_STR;
		else
		{
			free(input_data);
			ft_error_output(farm);
		}
		return (1);
	}
	else
		 return (0);
}

int				ft_is_comment(char	*input_data)
{
	if (input_data)
	{
		if (input_data[0] == '#' && input_data[1] != '#')
			return (1);
	}
	return (0);
}

t_farm			*ft_init_farm()
{
	char	*input_data;
	t_farm	*farm;
	
	farm = ft_create_farm();
	if (ft_get_ants_count(farm, &input_data) == 0)
		ft_error_output(farm);
	if (ft_read_rooms(farm, &input_data) == 0)
	{
		ft_error_output(farm);
		farm = 0;
	}
	return (farm);
}
