/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:37:57 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/12 13:31:09 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*out;

	if (min >= max)
		return (NULL);
	out = malloc((max - min) * sizeof * out);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		out[i] = i + min;
		++i;
	}
	return (out);
}
/*
#include <stdio.h>

int main(void)
{
    int* arr = ft_range(3, 7);
    for (int i = 0; i < 7 - 3; ++i)
        printf("%i ", arr[i]);
    free(arr);
	puts("");
    arr = ft_range(-3, 4);
    for (int i = 0; i < 4 - -3; ++i)
        printf("%i ", arr[i]);
    free(arr);
	puts("");
    arr = ft_range(-5, -1);
    for (int i = 0; i < -1 - -5; ++i)
        printf("%i ", arr[i]);
    free(arr);
	puts("");
}*/
