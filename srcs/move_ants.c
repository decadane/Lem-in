/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:59:48 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/05 17:44:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	**create_ants(size_t num)
{
	t_ant	**res;
	size_t	i;

	i = 1;
	res = (t_ant**)malloc(sizeof(t_ant*) * (num + 1));
	while (i <= num)
	{
		res[i - 1] = (t_ant*)malloc(sizeof(t_ant));
		res[i - 1]->id = 0;
		i++;
	}
	res[i - 1] = NULL;
	return (res);
}

void	assign_route(t_ant *ant, t_path_set *paths)
{
	size_t	i;
	int		j;
	int		min;
	int		res;

	i = 1;
	res = 0;
	min = (paths->lens)[0] + (paths->ants)[0];
	while (i < paths->num_of_paths)
	{
		j = (paths->lens)[i] + (paths->ants)[i];
		if (j < min)
		{
			min = j;
			res = i;
		}
		i++;
	}
	ant->route = (paths->paths)[res];
	if ((paths->paths)[res]->next->room->state != -2)
		(paths->ants)[res] += 1;
}

int		finish(t_ant **ants)
{
	int i;

	i = 0;
	while (ants[i])
	{
		if (ants[i]->route->next)
			return (0);
		i++;
	}
	return (1);
}

void	print_move(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->id);
	ft_putchar('-');
	ft_putstr(ant->route->room->name);
//	printf("\n-------%s--------\n", ant->route->room->name);
	ft_putchar(' ');
}

void	ants_moving(t_ant **ants)
{
	int	i;

	i = 0;
	while (ants[i])
	{
		if ((ants[i])->route->next && (ants[i])->route->next->room->state < 1)
		{
			if (!(ants[i])->id)
			{
				(ants[i])->id = num;
				num++;
			}
			ants[i]->route->room->state = 0;
			//
			ants[i]->route = ants[i]->route->next;
			ants[i]->route->room->state += (ants[i]->route->room->state < 0) ? 0 : 1;
			print_move(ants[i]);
		}
		i++;
	}
}

void	move_ants(int ants_c, t_path_set *paths)
{
	t_ant	**ants;
	int		i;

	ants = create_ants(ants_c);
	i = 0;
	while (i < ants_c)
	{
		assign_route(ants[i], paths);
		i++;
	}
	while (!finish(ants))
	{
		ants_moving(ants);
		ft_putchar('\n');
	}
}
