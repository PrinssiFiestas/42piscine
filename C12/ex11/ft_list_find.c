/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:50:58 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 18:21:45 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

t_list	*ft_list_find(t_list *list, void *data_ref, int (*cmp)())
{
	if (list == NULL)
		return (NULL);
	if (cmp(list->data, data_ref) == 0)
		return list;
	return ft_list_find(list->next, data_ref, cmp);
}
