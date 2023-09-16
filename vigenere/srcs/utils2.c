/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:04:41 by mhotting          #+#    #+#             */
/*   Updated: 2023/09/16 03:14:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vigenere.h"

char	ft_getchar(void)
{
	char	buffer[BUFFER_SIZE];
	int		nb_read;
	char	*read_content;
	char	res;

	read_content = NULL;
	nb_read = 1;
	while (nb_read > 0)
	{
		flush_buffer(buffer);
		nb_read = read(0, buffer, BUFFER_SIZE - 1);
		if (nb_read == -1 || !append_content(&read_content, buffer))
		{
			if (read_content != NULL)
				free(read_content);
			return (-1);
		}
		if (buffer[0] == '\n' || buffer[0] == 0)
			break ;
	}
	res = read_content[0];
	free(read_content);
	return (res);
}
