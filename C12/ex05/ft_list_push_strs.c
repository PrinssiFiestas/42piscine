/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:37:27 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 13:46:48 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*list;
	t_list	*elem;

	if (size <= 0)
		return (NULL);
	list = ft_create_elem(strs[0]);
	elem = list;
	i = 1;
	while (i < size)
	{
		elem->next = ft_create_elem(strs[i]);
		elem = elem->next;
		++i;
	}
	return (list);
}
