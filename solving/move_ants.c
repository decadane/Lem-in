/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:59:48 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/03 14:13:59 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_ant	**create_ants(size_t num)
{
	t_ant	**res;
	int		i;

	i = 1;
	res = (t_ant**)malloc(sizeof(t_ant*) * num + 1);
	while (i <= num)
	{
		res[i - 1] = (t_ant*)malloc(sizeof(t_ant));
		res[i - 1]->id = 0;
		i++;
	}
	res[i - 1] = NULL;
	return (res);
}

void	assign_route(t_ant *ant, t_path **paths, int *assign_ants)
{
	int	i;
	int j;
	int min;
	int res;

	i = 1;
	res = 0;
	min = paths[0]->path_len + paths[0]->ants;
	while (paths[i])
	{
		j = paths[i]->path_len + paths[i]->ants;
		if (j < min)
		{
			min = j;
			res = i;
		}
		i++;
	}
	ant->route = paths[res];
	(paths[res])->ants += 1;
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
			ants[i]->route = ants[i]->route->next;
			ants[i]->route->room->state += (ants[i]->route->room->state < 0) ? 0 : 1;
			print_move(ants[i]);
		}
		i++;
	}
}

void	move_ants(int ants_c, t_path **paths, int *assign_ants, int l)
{
	t_ant	**ants;
	int		i;

	ants = create_ants(ants_c);
	i = 0;
	while (i < ants_c)
	{
		assign_route(ants[i], paths, assign_ants);
		i++;
	}
	while (!finish(ants))
	{
		ants_moving(ants);
		ft_putchar('\n');
	}
}
