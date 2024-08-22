/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:56:34 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 11:58:36 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

int	ft_list_size(t_list *list)
{
	int	result;

	result = 0;
	while (list != NULL)
	{
		list = list->next;
		++result;
	}
	return (result);
}
