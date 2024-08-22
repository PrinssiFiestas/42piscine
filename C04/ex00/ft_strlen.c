/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:42:31 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/08 16:02:24 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	return (length);
}
/*#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_strlen(""));
	printf("%i\n", ft_strlen("blah"));
}*/
