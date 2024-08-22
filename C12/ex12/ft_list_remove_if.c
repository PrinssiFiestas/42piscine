/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:23:13 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/16 08:59:31 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	remove_if(t_list *elem, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*next;

	if (elem->next == NULL)
		return ;
	if (cmp(elem->next->data, data_ref) == 0)
	{
		free_fct(elem->next->data);
		next = elem->next->next;
		free(elem->next);
		elem->next = next;
	}
	remove_if(elem->next, data_ref, cmp, free_fct);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*next;

	if (*begin_list == NULL)
		return ;
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		next = (*begin_list)->next;
		free_fct(*begin_list);
		*begin_list = next;
		return ;
	}
	remove_if(*begin_list, data_ref, cmp, free_fct);
}
