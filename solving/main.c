/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:56:13 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/03 13:58:58 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room  *create_room(char *name, int state)
{
	t_room *new;

	new = (t_room*)malloc(sizeof(t_room));
	new->name = ft_strdup(name);
	new->state = state;
	return (new);
}

int main()
{
	t_path **all;
	t_path *one;
	t_path *two;
	t_path *three;
	t_path *four;
	t_path *ptr;
	t_room *r2;
	t_room *r3;
	t_room *r6;
	t_room *r7;

	r2 = create_room("2", 0);
	r3 = create_room("3", 0);
	r6 = create_room("6", 0);
	r7 = create_room("7", 0);

	all = (t_path**)malloc(sizeof(t_path*) * 5);
	one = (t_path*)malloc(sizeof(t_path));
	one->room = create_room("1", -1);
	one->ants = 0;
	one->path_len = 3;
	one->next = (t_path*)malloc(sizeof(t_path));
	ptr = one->next;
	ptr->room = r2;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room =  r3;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = create_room("4", -2);
	ptr->next = NULL;


	two = (t_path*)malloc(sizeof(t_path));
	two->room = create_room("1", -1);
	two->ants = 0;
	two->path_len = 4;
	two->next = (t_path*)malloc(sizeof(t_path));
	ptr = two->next;
	ptr->room = create_room("5", 0);
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = r6;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = r7;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = create_room("4", -2);
	ptr->next = NULL;

	three = (t_path*)malloc(sizeof(t_path));
	three->room = create_room("1", -1);
	three->ants = 0;
	three->path_len = 4;
	three->next = (t_path*)malloc(sizeof(t_path));
	ptr = three->next;
	ptr->room = r2;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = r6;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = r7;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = create_room("4", -2);
	ptr->next = NULL;

	four = (t_path*)malloc(sizeof(t_path));
	four->room = create_room("1", -1);
	four->ants = 0;
	four->path_len = 2;
	four->next = (t_path*)malloc(sizeof(t_path));
	ptr = four->next;
	ptr->room = r2;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = create_room("4", -2);
	ptr->next = NULL;

/* 	one = (t_path*)malloc(sizeof(t_path));
	one->room = create_room("1", -1);
	one->ants = 0;
	one->path_len = 3;
	one->next = (t_path*)malloc(sizeof(t_path));
	ptr = one->next;
	ptr->room = r2;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room =  r3;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = create_room("4", -2);
	ptr->next = NULL;

	two = (t_path*)malloc(sizeof(t_path));
	two->room = create_room("1", -1);
	two->ants = 0;
	two->path_len = 4;
	two->next = (t_path*)malloc(sizeof(t_path));
	ptr = two->next;
	ptr->room = create_room("5", 0);
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = create_room("6", 0);
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = r3;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = create_room("4", -2);
	ptr->next = NULL;

	three = (t_path*)malloc(sizeof(t_path));
	three->room = create_room("1", -1);
	three->ants = 0;
	three->path_len = 4;
	three->next = (t_path*)malloc(sizeof(t_path));
	ptr = three->next;
	ptr->room = r2;
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room =  create_room("7", 0);
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = create_room("8", 0);
	ptr->next = (t_path*)malloc(sizeof(t_path));
	ptr = ptr->next;
	ptr->room = create_room("4", -2);
	ptr->next = NULL; */

	all[0] = one;
	all[1] = two;
	all[2] = three;
	all[3] = four;
	all[4] = NULL;


	t_path_set *res;

	res = (t_path_set*)malloc(sizeof(t_path_set));
res->
   t_path          **paths;
     size_t          *lens;
     size_t          *ants;
     size_t          num_of_paths;
}                   t_path_set;


	find_paths(15, all);
	return (0);
}
