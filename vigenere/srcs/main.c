/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:53:50 by mhotting          #+#    #+#             */
/*   Updated: 2023/09/18 16:18:00 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vigenere.h"

void	display_result(char *file_content, char *result)
{
	ft_putstr("*****************************\n");
	ft_putstr("*    VIGENERE ENCRYPTION    *\n");
	ft_putstr("*****************************\n\n");
	ft_putstr("-> CONTENT BEFORE ENCRYPTION:\n");
	ft_putstr(file_content);
	ft_putstr("\n----------------------------\n\n");
	ft_putstr("-> CONTENT AFTER ENCRYPTION:\n");
	ft_putstr(result);
}

int	main(int argc, char **argv)
{
	char	*file_content;
	char	*file_name;
	char	*key;
	char	*result;

	if (argc == 3)
	{
		file_name = argv[1];
		key = argv[2];
		file_content = read_file(file_name);
		if (file_content == NULL)
		{
			ft_putstr("ERROR - The file cannot be read\n");
			return (1);
		}
		result = encrypt(file_content, key);
		if (result != NULL)
		{
			display_result(file_content, result);
			free(result);
		}
		free(file_content);
	}
	return (0);
}
