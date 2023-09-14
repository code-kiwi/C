/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:13:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/09/15 00:49:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vigenere.h"

void	flush_buffer(char buffer[BUFFER_SIZE])
{
	unsigned int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

int	append_content(char **file_content, char buffer[BUFFER_SIZE])
{
	char			*temp;
	unsigned int	file_content_len;
	unsigned int	buffer_len;

	file_content_len = 0;
	if (*file_content != NULL)
		file_content_len = ft_strlen(*file_content);
	buffer_len = ft_strlen(buffer);
	temp = (char *)malloc((file_content_len + buffer_len + 1) * sizeof(char));
	if (temp == NULL)
	{
		if (*file_content != NULL)
			free(*file_content);
		*file_content = NULL;
		return (0);
	}
	temp[0] = '\0';
	if (*file_content != NULL)
		ft_strcat(temp, *file_content);
	ft_strcat(temp, buffer);
	if (*file_content != NULL)
		free(*file_content);
	*file_content = temp;
	return (1);
}

int	get_content(int fd, char **file_content)
{
	char	buffer[BUFFER_SIZE];
	int		nb_read;

	nb_read = 1;
	while (nb_read > 0)
	{
		flush_buffer(buffer);
		nb_read = read(fd, buffer, BUFFER_SIZE - 1);
		if (nb_read == -1)
		{
			if (*file_content != NULL)
				free(*file_content);
			*file_content = NULL;
			return (0);
		}
		append_content(file_content, buffer);
		if (*file_content == NULL)
			return (0);
	}
	return (1);
}

char	*read_file(char *file_name)
{
	int		fd;
	char	*file_content;
	int		returned_value;

	file_content = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	get_content(fd, &file_content);
	returned_value = close(fd);
	if (returned_value == -1)
	{
		if (file_content != NULL)
			free(file_content);
		return (NULL);
	}
	return (file_content);
}
