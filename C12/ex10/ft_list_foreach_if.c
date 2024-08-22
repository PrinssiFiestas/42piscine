/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:45:51 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 17:49:43 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_list_foreach_if(t_list *list, void (*f)(void *), void
	*data_ref, int (*cmp)())
{
	if (list == NULL)
		return ;
	if (cmp(list->data, data_ref) == 0)
		f(list->data);
	ft_list_foreach_if(list->next, f, data_ref, cmp);
}
