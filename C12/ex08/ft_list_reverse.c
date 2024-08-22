/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:40:01 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 17:25:55 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h" // TODO REMOVE THE HEADER FILE
#include <stddef.h>

void	reverse_elements(t_list *prev, t_list *elem, t_list **begin_list)
{
	if (elem->next == NULL)
	{
		elem->next = prev;
		*begin_list = elem;
		return ;
	}
	reverse_elements(elem, elem->next, begin_list);
	elem->next = prev;
}

void	ft_list_reverse(t_list **begin_list)
{
	if (*begin_list == NULL)
		return ;
	reverse_elements(NULL, *begin_list, begin_list);
}
