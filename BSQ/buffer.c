/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:14:22 by gpellech          #+#    #+#             */
/*   Updated: 2024/08/21 12:25:19 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	ft_buff_valid(int fd, char *buffer, size_t buffer_length)
{
	if (buffer_length < 4)
		return (ft_close(fd));
	if (buffer[buffer_length - 3] == buffer[buffer_length - 2])
		return (ft_close(fd));
	if (buffer[buffer_length - 3] == buffer[buffer_length - 1])
		return (ft_close(fd));
	if (buffer[buffer_length - 2] == buffer[buffer_length - 1])
		return (ft_close(fd));
	return (0);
}

int	ft_close(int fd)
{
	if (fd != 0)
		close(fd);
	return (-1);
}
