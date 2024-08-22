/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:14:42 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/12 13:36:10 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	str_length(char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	return (length);
}

void	concat(char *dest, const char *src)
{
	while (*dest != '\0')
		++dest;
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	size_t	sep_length;
	size_t	strs_total_length;
	size_t	i;
	char	*out;

	sep_length = str_length(sep);
	strs_total_length = 0;
	i = 0;
	while (i < (size_t)size)
	{
		strs_total_length += str_length(strs[i]);
		++i;
	}
	out = malloc(strs_total_length + size * sep_length + sizeof"");
	out[0] = '\0';
	i = 0;
	while (i < (size_t)size - (size != 0))
	{
		concat(out, strs[i]);
		concat(out, sep);
		++i;
	}
	if (size != 0)
		concat(out, strs[i]);
	return (out);
}
/*
#include <stdio.h>

int main(int argc, char** argv)
{
    char* str = ft_strjoin(argc - 1, argv + 1, "__");
    puts(str);
    free(str);
    str = ft_strjoin(0, NULL, "__");
    puts(str);
    free(str);
}*/
