/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:15:38 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/31 19:03:02 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
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
# define ROOM	farm->room->name
# define ANT(i)	farm->ants[i]
# define LINKS	farm->links


typedef struct			s_room
{
	char				*name;
	struct				s_links
	{
		struct s_room	*room;
		struct s_list	*next;
	}					links;
	int					x;
	int					y;
	char				state;//START, END or ant number
	struct s_room		*next_room;
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

//------------------------ffahey part----------------------------

//allocation_functions
t_farm		*ft_create_farm();
char		**ft_ants_generator(size_t size);

//free functions
void		ft_room_destroyer(t_room **room);
void		ft_farm_destroyer(t_farm **farm);

t_farm				*ft_init_farm();
void	ft_error_output(t_farm **farm);

//kmedhurs part

#endif
