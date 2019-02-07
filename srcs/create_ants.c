/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants_graf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:33:20 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/07 17:57:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	**create_ants(size_t num)
{
	t_ant	**res;
	size_t	i;

	i = 1;
	res = (t_ant**)malloc(sizeof(t_ant*) * (num + 1));
	while (i <= num)
	{
		res[i - 1] = (t_ant*)malloc(sizeof(t_ant));
		res[i - 1]->id = 0;
		i++;
	}
	res[i - 1] = NULL;
	return (res);
}
