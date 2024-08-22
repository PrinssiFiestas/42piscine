/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:35:58 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/11 08:41:25 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	size_t	length;
	char	*out;

	length = 0;
	while (src[length] != '\0')
		++length;
	out = malloc(length + sizeof"");
	if (out == NULL)
		return (NULL);
	length = 0;
	while (src[length] != '\0')
	{
		out[length] = src[length];
		++length;
	}
	out[length] = '\0';
	return (out);
}
/*
#include <stdio.h>

int main(void)
{
    char* str = ft_strdup("blah");
    puts(str);
    free(str);
}*/
