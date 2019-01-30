/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:15:38 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/30 19:32:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define START	-1
# define END	-2

# define ROOM	farm->room->name
# define ANT(i)	farm->ants[i]

typedef struct		s_room
{
	char	*name;
	int		id;
	int		x;
	int		y;
	char	state;//START, END or ant number
	t_room	*next;
}					t_room;

typedef struct		s_farm
{
	size_t	rooms_count;
	t_room	*rooms;
	size_t	ants_count;
//ffahey part

	char	**ants;
}					t_farm;

t_farm				*ft_init_farm(t_farm **farm);


#endif
