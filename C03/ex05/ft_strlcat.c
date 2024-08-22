/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:36:27 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/08 08:54:25 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	length = 0;
	while (dest[length] != '\0')
		++length;
	i = 0;
	while (src[i] != '\0' && length + i < size - (size > 0))
	{
		dest[length + i] = src[i];
		++i;
	}
	if (length + i < size - 1)
		dest[length + i] = '\0';
	else if (size != 0 && length < size)
		dest[size - 1] = '\0';
	while (src[i] != '\0')
		++i;
	if (length < size)
		return (length + i);
	else
		return (i + size);
}
