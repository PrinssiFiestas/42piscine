/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:48:59 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 13:51:17 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_list_clear(t_list *elem, void (*free_fct)(void *))
{
	t_list	*next;

	if (elem == NULL)
		return ;
	next = elem->next;
	free_fct(elem);
	ft_list_clear(next, free_fct);
}
