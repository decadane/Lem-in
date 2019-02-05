/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:35:46 by marvin            #+#    #+#             */
/*   Updated: 2019/02/05 17:45:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		path = head;
	}
	return (path);
}

t_ps	*ft_new_path(t_ps *ps, t_path *path)
{
	t_ps	*new_node;
	t_ps	*head;

	head = ps;
	if (!ps)
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
		ps = head;
	}
	return (ps);
}

t_path	*ft_copy_path(t_path *path)
{
	t_path	*new_path;

	new_path = NULL;
	while (path)
	{
		new_path = ft_complete_path(new_path, path->room);
		path = path->next;
	}
	return (new_path);
}

void	ft_print_path(t_path *path)
{
	t_path	*head;

	head = path;
	printf("Path: ");
	while (path)
	{
		printf("%d ", path->room->id);
		path = path->next;
	}
	path = head;
}

int		ft_check_path(t_path *path, int id)
{
	t_path	*head;
	int		res;

	res = 1;
	head = path;
	while (path)
	{
		if (path->room->id == id)
			res = 0;
		path = path->next;
	}
	path = head;
	return (res);
}

void	ft_path_destroyer(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path;
		path = path->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void	ft_ps_destroyer(t_ps *ps)
{
	t_ps	*tmp;

	while (ps)
	{
		tmp = ps;
		ps = ps->next;
		tmp->next = NULL;
		free(tmp);
	}
}

size_t	ft_num_paths(t_ps *ps)
{
	t_ps	*tmp;
	size_t	len;

	len = 0;
	tmp = ps;
	while (ps)
	{
		len++;
		ps = ps->next;
	}
	ps = tmp;
	return (len);
}

size_t	ft_path_len(t_path *path)
{
	size_t	len;
	t_path	*head;

	head = path;
	len = 0;
	while (path)
	{
		len++;
		path = path->next;
	}
	path = head;
	return (len);
}
//delete this func!
void	ft_print_farm(t_farm *farm)
{
	int		i;
	int		j;
	t_room	*tmp;

	i = -1;
	tmp = farm->rooms;
	while (++i < (int)farm->rooms_count)
	{
		printf("Degree: %d, ID: %d, State: %d", farm->rooms->degree, farm->rooms->id, farm->rooms->state);
		j = -1;
		while (++j < farm->rooms->degree)
			printf(" Ptr: %d", farm->rooms->links[j]->id);
		printf("\n");
		farm->rooms = farm->rooms->next;
	}
	farm->rooms = tmp;
}
