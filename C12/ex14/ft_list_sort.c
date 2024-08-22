/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:10:50 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/19 13:08:51 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>
#include <stdbool.h>

t_list	*swap(t_list *elem, t_list *next)
{
	t_list	*temp;

	temp = next->next;
	next->next = elem;
	elem->next = temp;
	return next;
}

size_t	list_size(t_list *list)
{
	size_t	result;

	result = 0;
	while (list != NULL)
	{
		list = list->next;
		++result;
	}
	return (result);
}
void ft_list_sort(t_list **start, int (*cmp)())
{
	t_list	**head;
	t_list	*elem;
	t_list	*next;
	int		i;
	int		j;
	bool	swapped;
	size_t	length;

	length = list_size(*start);
	i = 0;
	while ((size_t)i < length)
	{
		head = start;
		swapped = false;
		j = 0;
		while ((size_t)j < length - i - 1)
		{
			elem = *head;
			next = elem->next;
			if (cmp(elem->data, next->data) > 0)
			{
				*head = swap(elem, next);
				swapped = true;
			}
			head = &(*head)->next;
			++j;
		}
		++i;
	}
}

