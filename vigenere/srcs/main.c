/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:53:50 by mhotting          #+#    #+#             */
/*   Updated: 2023/09/15 00:52:59 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vigenere.h"

int	main(int argc, char **argv)
{
	char	*file_content;
	char	*file_name;

	if (argc != 2)
	{
		ft_putstr("ERROR - One parameter is expected (valid file name)\n");
		return (1);
	}
	file_name = argv[1];
	file_content = read_file(file_name);
	if (file_content == NULL)
	{
		ft_putstr("ERROR - The file cannot be read\n");
		return (1);
	}
	ft_putstr(file_content);
	free(file_content);
	return (0);
}
