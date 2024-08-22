/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:51 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/22 09:17:51 by lfiestas         ###   ########.fr       */
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

size_t	count_substrs(char *str, char *charset)
{
	size_t	count;
	char	*ptr;

	count = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		ptr = find_first_not_of(ptr, charset);
		if (*ptr == '\0')
			break ;
		++count;
		ptr = find_first_of(ptr, charset);
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	size_t	strs_length;
	char	*ptr;
	char	*ptr_end;
	size_t	i;

	strs_length = count_substrs(str, charset);
	strs = malloc((strs_length + 1) * sizeof * strs);
	strs_length = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		ptr = find_first_not_of(ptr, charset);
		if (*ptr == '\0')
			break ;
		ptr_end = find_first_of(ptr, charset);
		strs[strs_length] = malloc(ptr_end - ptr + sizeof"");
		i = 0;
		while (ptr + i++ < ptr_end)
			strs[strs_length][i - 1] = ptr[i - 1];
		strs[strs_length++][i - 1] = '\0';
		ptr = ptr_end;
	}
	strs[strs_length] = NULL;
	return (strs);
}

#include <stdio.h>

int main(void)
{
    char** strs = ft_split("", " _");
    for (size_t i = 0; strs[i] != NULL; ++i)
        printf("%s\n", strs[i]);
    for (size_t i = 0; strs[i] != NULL; ++i)
        free(strs[i]);
    free(strs);
}
