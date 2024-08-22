/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:44:02 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 11:24:46 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	size_t	name_length;

	(void)argc;
	name_length = 0;
	while (argv[0][name_length] != '\0')
		++name_length;
	write(1, argv[0], name_length);
	write(1, "\n", 1);
}
