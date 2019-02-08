/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:33:14 by ffahey            #+#    #+#             */
/*   Updated: 2019/02/08 13:29:34 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add(t_list **head, char *str)
{
	t_list	*list;

	if (head)
	{
		if (!(list = (t_list*)malloc(sizeof(t_list))))
			exit(-1);
		if (*head)
			(*head)->prev = list;
		list->str = ft_strdup(str);
		list->prev = NULL;
		list->next = *head;
		*head = list;
	}
}

void	ft_lst_free(t_list **head)
{
	t_list	*tmp;

	tmp = NULL;
	if (head)
	{
		while (*head)
		{
			free((*head)->str);
			tmp = *head;
			*head = (*head)->next;
			free(tmp);
		}
	}
}

void	ft_lst_print(t_list *head)
{
	while (head)
	{
		ft_putstr(head->str);
		ft_putchar('\n');
		head = head->next;
	}
}

void	ft_lst_rev(t_list **head)
{
	t_list	*tmp;

	if (head)
	{
		while (*head)
		{
			tmp = (*head)->next;
			(*head)->next = (*head)->prev;
			(*head)->prev = tmp;
			if ((*head)->prev == NULL)
				break ;
			*head = (*head)->prev;
		}
	}
}

void	ft_lst_del(t_list *list)
{
	if (list)
	{
		if (list->prev)
			list->prev->next = list->next;
		if (list->next)
			list->next->prev = list->prev;
		free(list->str);
		free(list);
	}
}
