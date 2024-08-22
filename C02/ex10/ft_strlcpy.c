/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:14:42 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/02 10:44:40 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < size - (size > 0))
	{
		dest[i] = src[i];
		++i;
	}
	if (size != 0)
		dest[i] = '\0';
	while (src[i] != '\0')
		++i;
	return (i);
}
