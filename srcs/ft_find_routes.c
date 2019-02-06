/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:59 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/06 20:12:36 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_add_room_to_step(t_step **next_step, t_room *room, t_step *step)
{
	t_step	*new;

	if (next_step)
	{
		new = (t_step*)malloc(sizeof(t_step));
		new->room = room;
		new->parent = step;
		new->next = *next_step;
		*next_step = new;
	}
}

void	ft_print_step(t_step *step)
{
	while (step)
	{
		printf("%s ", step->room->name);
		step = step->next;
	}
	printf("\n");
}

void	ft_delete_step(t_step **head, t_step **step)
{
	t_step	*cur;
	
	if (*step == *head)
	{
		*head = (*head)->next;
		free(*step);
	}
	else
	{
		cur = *head;
		while (cur->next != *step)
			cur = cur->next;
		cur->next = (*step)->next;
		free(*step);
	}
}

void	ft_add_route(t_routes **routes, t_step *step)
{
	t_routes	*new_route;
	t_path		*head;
	t_path		*path;

	head = NULL;
	while (step)
	{
		path = (t_path*)malloc(sizeof(t_path));
		path->room = step->room;
		path->next = head;
		head = path;
		step = step->parent;
	}
	new_route = (t_routes*)malloc(sizeof(t_routes));
	new_route->routes = head;
	new_route->next = *routes;
	*routes = new_route;
}

void	ft_check_step(t_step **step, t_routes **routes)
{
	t_step	*cur;

	if (step && *step)
	{
		cur = *step;
		while (cur)
		{
			if (cur->room->state == -2)
			{
				ft_add_route(routes, cur);
				ft_delete_step(step, &cur);
			}
			cur = cur->next;
		}
	}
}

void	ft_one_step(t_step *step, size_t *step_count, size_t ac, t_routes **routes)
{
	t_step		*next_step;
	size_t		i;

	if (step == NULL || *step_count > 20)
		return ;
	printf("%lu: ", *step_count);
	ft_print_step(step);
	(*step_count)++;
	next_step = NULL;
	while (step)
	{
		i = 0;
		while (step->room->links && i < (size_t)step->room->degree)
		{
			if (step->room->links[i]->state == 0 || step->room->links[i]->state == -2)
			{
				ft_add_room_to_step(&next_step, step->room->links[i], step);
				if (step->room->links[i]->state == 0)
					step->room->links[i]->state = 1;
			}
			i++;
		}
		step = step->next;
	}
	ft_check_step(&next_step, routes);
	ft_one_step(next_step, step_count, ac, routes);
	free(next_step);
}

void	ft_print_routes(t_routes *routes)
{
	t_path	*path;

	while (routes)
	{
		path = routes->routes;
		while (path)
		{
			printf("%s ", path->room->name);
			path = path->next;
		}
		printf("\n");
		routes = routes->next;
	}
}

void	ft_find_routes(t_farm *farm)
{
	t_step	*step;
	size_t	step_count;
	t_routes	*routes;

	routes = NULL;
	step = (t_step*)malloc(sizeof(t_step));
	step->room = ft_find_room(farm->rooms, farm->start);
	step->next = NULL;
	step->parent = NULL;
	step_count = 0;
	ft_one_step(step, &step_count, farm->ants_count, &routes);
	printf("\n");
	ft_print_routes(routes);
}
