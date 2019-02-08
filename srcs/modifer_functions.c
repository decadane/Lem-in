/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifer_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:09:35 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/08 13:23:08 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_init_modifer_string(char **mod_str)
{
	mod_str[0] = START;
	mod_str[1] = END;
	mod_str[2] = RESTART;
	mod_str[3] = REEND;
	mod_str[4] = RENAME;
	mod_str[5] = EDIT;
	mod_str[6] = DELETE;
	mod_str[MODIFER_COUNT] = NULL;
}

static void		ft_init_modifer_functions(t_modifer_function *mod_func)
{
	mod_func[0] = ft_start_mod;
	mod_func[1] = ft_end_mod;
	mod_func[2] = ft_restart_mod;
	mod_func[3] = ft_reend_mod;
	mod_func[4] = ft_rename_mod;
	mod_func[5] = ft_edit_mod;
	mod_func[6] = ft_delete_mod;
	mod_func[MODIFER_COUNT] = NULL;
}

static int		ft_find_index(char *mod, char **mod_str)
{
	int		i;

	i = 0;
	while (mod_str[i])
	{
		if (ft_strcmp(mod_str[i], mod) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_is_modifer(char *mod, t_farm *farm)
{
	static char					*mod_str[MODIFER_COUNT + 1];
	static t_modifer_function	mod_func[MODIFER_COUNT + 1];
	int							mod_index;

	if (*mod_str == NULL)
		ft_init_modifer_string(mod_str);
	if (*mod_func == NULL)
		ft_init_modifer_functions(mod_func);
	mod_index = ft_find_index(mod, mod_str);
	ft_lst_add(&(farm->output), mod);
	if (mod_index < 0)
		return (0);
	else
		mod_func[mod_index](farm);
	return (1);
}
