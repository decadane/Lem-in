/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:15:38 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/31 20:49:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
//debug defines
# define C(a) printf("Check%d\n", a);

//error defines
# define OUT_OF_MEMORY	-1

//
# define START			-1
# define END			-2
# define START_STR		"##start"
# define END_STR		"##end"

//longtype defines
# define ROOM	farm->rooms
# define ANT(i)	farm->ants[i]
# define LINKS	farm->links


typedef struct			s_room
{
	int					id;
	char				*name;
	int					degree;
	struct s_room		**links;
	int					x;
	int					y;
	char				state;//START, END or ant number
	struct s_room		*next;
}						t_room;

typedef struct		s_farm
{
	size_t			rooms_count;
	t_room			*rooms;
	char			*start;
	char			*end;
	size_t			ants_count;
	char			**ants;
}					t_farm;

typedef struct		s_path
{
	t_room			*room;
	struct s_path	*next;
}					t_path;

typedef struct			s_path_list
{
	t_path				*path;
	struct s_path_list	*next;
}						t_ps;

//------------------------ffahey part----------------------------

//kmedhurs part

t_farm				*ft_init_farm(void);
void				ft_print_farm(t_farm *farm);
t_room				*ft_init_room(t_room *room, char *name, char state, int id);
t_room				*ft_search_node(t_room *room, int id);
t_path				*ft_complete_path(t_path *path, t_room *ptr);
t_ps				*ft_new_path(t_ps *ps, t_path *path);
t_path				*ft_copy_path(t_path *path);
void				ft_print_path(t_path *path);
t_ps				*ft_start_bfs(t_farm *farm);

#endif
