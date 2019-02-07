/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:15:38 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/07 21:03:09 by ffahey           ###   ########.fr       */
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
# define DELTA_PATHS	3


//longtype defines
# define ROOM	farm->rooms
# define ANT(i)	farm->ants[i]
# define LINKS	farm->links

# define MIN(x, y) x < y ? x : y

typedef struct			s_room
{
	int					id;
	char				*name;
	struct s_room		**links;
	int					degree;
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

typedef struct		s_ant
{
	int				id;
	t_path			*route;
}					t_ant;

typedef struct		s_move
{
	int				first;
	int				second;
}					t_move;

typedef struct			s_path_list
{
	t_path				*path;
	struct s_path_list	*next;
}						t_ps;

typedef struct		s_path_set
{
	t_path			**paths;
	size_t			*lens;
	size_t			*ants;
	size_t			num_of_paths;
	int				ants_count;
}					t_path_set;

//------------------------ffahey part----------------------------

typedef void	(*t_modifer_function)(t_farm *farm);

void			ft_start_mod(t_farm *farm);
void			ft_end_mod(t_farm *farm);
void			ft_restart_mod(t_farm *farm);
void			ft_reend_mod(t_farm *farm);
void			ft_rename_mod(t_farm *farm);
void			ft_edit_mod(t_farm *farm);
void			ft_delete_mod(t_farm *farm);

typedef void	(*t_modifer_function)(t_farm *farm);

void			ft_start_mod(t_farm *farm);
void			ft_end_mod(t_farm *farm);

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

//t_farm				*ft_init_farm(void);
void				ft_print_farm(t_farm *farm);
t_room				*ft_init_room(t_room *room, char *name, char state, int id);
t_room				*ft_search_node(t_room *room, int id);
t_path				*ft_complete_path(t_path *path, t_room *ptr);
t_ps				*ft_new_path(t_ps *ps, t_path *path);
t_path				*ft_copy_path(t_path *path);
t_room				*ft_pop_path(t_path **path);
t_path				*ft_pop_path_line(t_ps **line);

void				ft_print_path(t_path *path);
void				ft_ps_destroyer(t_ps *ps);

t_path_set			*ft_start_bfs(t_farm *farm, int num_of_paths);
int					ft_check_path(t_path *path, int id);
void				ft_path_destroyer(t_path *path);

size_t				ft_path_len(t_path *path);
size_t				ft_num_paths(t_ps *ps);

//kcarrot part

unsigned char		**make_cross_matrix(t_path **paths, int l);
void				move_ants(int ants_c, t_path_set *paths);
t_list				*move_ants_v();
//return list of moving ants for each iteration;
t_path_set			*find_paths(int ants_c, t_path_set *set, int nop);
int					*find_best_path(size_t ants, t_path_set *set,
		unsigned char **cross_m);
t_ant				**create_ants(size_t num);
int					no_crosses(unsigned char **cross_m, int *res, int j, int mv);
void				print_matrix(unsigned char **cross_m, int l);
static int num = 1; // Для итоговой нумерации муравьев

#endif
