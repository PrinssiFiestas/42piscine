/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:39:18 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/08 08:54:16 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;

	if (to_find[0] == '\0')
		return (str);
	while (*str != '\0')
	{
		i = 0;
		while (str[i] == to_find[i] && to_find[i] != '\0')
		{
			++i;
			if (to_find[i] == '\0')
				return (str);
		}
		++str;
	}
	return (NULL);
}
