/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:42:25 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/05 17:42:28 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
//debug defines
# define C(a) printf("Check%d\n", a);

//error defines
# define OUT_OF_MEMORY	-1

//modify commands defines
# define START_ROOM			-1
# define END_ROOM			-2
# define START			"##start"
# define END			"##end"
# define RESTART		"##restart"
# define REEND			"##reend"
# define RENAME			"##rename"
# define EDIT			"##edit"
# define DELETE			"##delete"
# define MODIFER_COUNT	7


//longtype defines
# define ROOM	farm->room->name
# define ANT(i)	farm->ants[i]
# define LINKS	farm->links


typedef struct			s_room
{
	int					id;
	char				*name;
	struct s_room		**links;
	int					degree;
	int					x;
	int					y;
	char				state;//ask kmedhurs)
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

typedef void	(*t_modifer_function)(t_farm *farm, char *command);

void			ft_start_mod(t_farm *farm, char *command);
void			ft_end_mod(t_farm *farm, char *command);
void			ft_restart_mod(t_farm *farm, char *command);
void			ft_reend_mod(t_farm *farm, char *command);
void			ft_rename_mod(t_farm *farm, char *command);
void			ft_edit_mod(t_farm *farm, char *command);
void			ft_delete_mod(t_farm *farm, char *command);

//------------------------ffahey part----------------------------

//allocation_functions
t_room		*ft_create_room(t_farm *farm, char **data);
void		ft_add_room(t_farm *farm, char **data);
t_farm		*ft_create_farm();
void		ft_ants_generator(t_farm *farm);

//free functions
void		ft_room_delete(t_room **rooms, t_room *room);
void		ft_room_destroyer(t_room **room);
void		ft_farm_destroyer(t_farm *farm);

int			ft_is_comment(char	*input_data);
int			ft_is_modifer(char	*input_data, t_farm *farm);
t_farm		*ft_init_farm();
int			ft_read_rooms(t_farm *farm, char **data);
int			ft_read_room(t_farm *farm, char *data);
void		ft_rooms_reverse(t_room **roms);
t_room		*ft_find_room(t_room *rooms, char *name);
void		ft_error_output(t_farm *farm, const char *error_message);
void		ft_print_farm_structure(t_farm *farm);

//kmedhurs part

#endif
