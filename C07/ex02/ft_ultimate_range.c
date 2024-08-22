/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:05:54 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 13:14:26 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc((max - min) * sizeof**range);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = i + min;
		++i;
	}
	return (max - min);
}
/*
#include <stdio.h>

int main(void)
{
    int *arr;
    int result = ft_ultimate_range(&arr, 3, 7);
    printf("%i\n\n", result);
    for (int i = 0; i < 7 - 3; ++i)
        printf("%i", arr[i]);
    free(arr);
}*/
