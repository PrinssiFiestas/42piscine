/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:52:40 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 13:18:53 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	if (*begin_list == NULL)
		*begin_list = ft_create_elem(data);
	else
		ft_create_elem(data)->next = *begin_list;
}
