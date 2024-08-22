/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:03:07 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/16 09:08:34 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void append(t_list *list1, t_list *list2)
{
	if (list1->next == NULL)
	{
		list1->next = list2;
		return ;
	}
	append(list1->next, list2);
}

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	append(*begin_list1, begin_list2);
}
