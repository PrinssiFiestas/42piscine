/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 08:58:29 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/04 10:40:39 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*dest != '\0')
		++dest;
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = *src;
	return (ret);
}
