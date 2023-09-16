/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:53:50 by mhotting          #+#    #+#             */
/*   Updated: 2023/09/16 03:16:05 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vigenere.h"

int	main(int argc, char **argv)
{
	char	*file_content;
	char	*file_name;
	char	*key;

	if (argc != 3)
	{
		ft_putstr("ERROR - Two parameters expected: valid file name and key\n");
		return (1);
	}
	file_name = argv[1];
	key = argv[2];
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
