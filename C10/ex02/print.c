/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:56:55 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/19 09:31:43 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>

size_t	string_length(const char *str);

int	print_file_error(const char *bin, const char *file_name)
{
	const char	*msg;

	write(2, bin, string_length(bin));
	msg = ": cannot open '";
	write(2, msg, string_length(msg));
	write(2, file_name, string_length(file_name));
	msg = "' for reading: ";
	write(2, msg, string_length(msg));
	write(2, strerror(errno), string_length(strerror(errno)));
	write(2, "\n", 1);
	return (1);
}
