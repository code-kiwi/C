/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:53:50 by mhotting          #+#    #+#             */
/*   Updated: 2023/09/14 22:07:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vigenere.h"

int	main(int argc, char **argv)
{
	char	*file_content;

	if (argc != 2)
		return (1);
	file_content = ft_strdup(argv[1]);
	if (file_content == NULL)
		return (1);
	ft_putstr(file_content);
	return (0);
}
