/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:12:04 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/04 10:41:13 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ret;
	unsigned int	i;

	ret = dest;
	while (*dest != '\0')
		++dest;
	i = 0;
	while (i < nb && src[i])
	{
		*dest = src[i];
		++dest;
		++i;
	}
	*dest = '\0';
	return (ret);
}
