/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:15:38 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/03 18:15:07 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////kmedhurs comment

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define START	-1
# define END	-2

# define ROOM	farm->room->name
# define ANT(i)	farm->ants[i]


typedef struct		s_room
{
	char	*name;
	t_list	*link;
	int		id;
	int		x;
	int		y;
	int		state;//START, END or ant number
	struct s_room	*next;
}					t_room;

typedef struct 		s_path
{
	t_room			*room;
	struct s_path	*next;
}					t_path;


typedef struct		s_farm
{
	size_t	rooms_count;
	t_room	*rooms;
	size_t	ants_count;
	char	**ants;
	int		**link_mtx;
}					t_farm;

typedef struct		s_ant
{
	int		id;
	t_path 	*route;
}					t_ant;

typedef struct		s_move
{
	int first;
	int second;
}					t_move;

typedef struct      s_path_set
{
     t_path          **paths;
     size_t          *lens;
     size_t          *ants;
     size_t          num_of_paths;
}                   t_path_set;


//ffahey part

t_farm				*ft_init_farm(t_farm **farm);

char				**make_cross_matrix(t_path **paths, int l);

void				move_ants(int ants_c, t_path_set *paths);

t_list				*move_ants_v();
//return list of moving ants for each iteration;

void				find_paths(int ants_c, t_path_set *set);

static int num = 1; // Для итоговой нумерации муравьев

#endif
