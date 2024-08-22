/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:54:18 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/02 10:11:31 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;
	bool			last_was_alphanumeric;

	i = 0;
	last_was_alphanumeric = false;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z' && last_was_alphanumeric)
			str[i] += 'a' - 'A';
		else if ('a' <= str[i] && str[i] <= 'z' && !last_was_alphanumeric)
			str[i] -= 'a' - 'A';
		if ('A' <= str[i] && str[i] <= 'Z')
			last_was_alphanumeric = true;
		else if ('a' <= str[i] && str[i] <= 'z')
			last_was_alphanumeric = true;
		else if ('0' <= str[i] && str[i] <= '9')
			last_was_alphanumeric = true;
		else
			last_was_alphanumeric = false;
		++i;
	}
	return (str);
}
