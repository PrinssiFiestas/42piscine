/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:52:18 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 14:42:18 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

t_list	*ft_list_at(t_list *list, unsigned int n)
{
	if (n == 0 || list == NULL)
		return (list);
	return (ft_list_at(list->next, n - 1));
}
