/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:35:46 by marvin            #+#    #+#             */
/*   Updated: 2019/01/31 21:05:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_path	*ft_complete_path(t_path *path, t_room *room)
{
	t_path	*new_node;
	t_path	*head;

	head = path;
	if (!path)
	{
		new_node = (t_path*)malloc(sizeof(t_path));
		new_node->room = room;
		new_node->next = NULL;
		path = new_node;
	}
	else
	{
		while (path->next)
			path = path->next;
		new_node = (t_path*)malloc(sizeof(t_path));
		new_node->room = room;
		new_node->next = NULL;
		path->next = new_node;
	}
	return (path);
}

t_ps	*ft_new_path(t_ps *ps, t_path *path)
{
	t_ps	*new_node;
	t_ps	*head;

	head = ps;
	if (!path)
	{
		new_node = (t_ps*)malloc(sizeof(t_ps));
		new_node->path = path;
		new_node->next = NULL;
		ps = new_node;
	}
	else
	{
		while (ps->next)
			ps = ps->next;
		new_node = (t_ps*)malloc(sizeof(t_ps));
		new_node->path = path;
		new_node->next = NULL;
		ps->next = new_node;
	}
	return (ps);
}

t_path	*ft_copy_path(t_path *path)
{
	t_path	*new_path;
	t_path	*head;

	head = path;
	new_path = NULL;
	while (path)
	{
		new_path = ft_complete_path(new_path, path->room);
		path = path->next;
		new_path = new_path->next;
	}
	return (head);
}

void	ft_print_path(t_path *path)
{
	while (path)
	{
		printf("%d ", path->room->id);
		path = path->next;
	}
}
