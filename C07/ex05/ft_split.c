/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:09:51 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/11 10:20:53 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	char_in_string(char *haystack, char needle)
{
	while (*haystack != '\0')
	{
		if (*haystack == needle)
			return (true);
		++haystack;
	}
	return (false);
}

char	*find_first_of(char *str, char *charset)
{
	while (*str != '\0')
	{
		if (char_in_string(charset, *str))
			return (str);
		++str;
	}
	return (str);
}

char	*find_first_not_of(char *str, char *charset)
{
	while (*str != '\0')
	{
		if (!char_in_string(charset, *str))
			return (str);
		++str;
	}
	return (str);
}

size_t	count_fields(char *str, char *charset)
{
	size_t	strs_length;
	char	*ptr;

	strs_length = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		ptr = find_first_not_of(ptr, charset);
		if (*ptr == '\0')
			break ;
		++strs_length;
		ptr = find_first_of(ptr, charset);
	}
	return (strs_length);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	size_t	strs_length;
	char	*ptr;

	strs_length = count_fields(str, charset);
	strs = malloc((strs_length + 1) * sizeof * strs);
	strs_length = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		ptr = find_first_not_of(ptr, charset);
		if (*ptr == '\0')
			break ;
		strs[strs_length++] = ptr;
		ptr = find_first_of(ptr, charset);
	}
	strs[strs_length] = NULL;
	return (strs);
}
/*
#include <stdio.h>

int main(void)
{
    char** strs = ft_split(" _ asdf __skiibel diibel___", " _");
    for (size_t i = 0; strs[i] != NULL; ++i)
        printf("%s\n", strs[i]);
    free(strs);
    strs = ft_split("", " _");
    for (size_t i = 0; strs[i] != NULL; ++i)
        printf("%s\n", strs[i]);
    free(strs);
}*/
