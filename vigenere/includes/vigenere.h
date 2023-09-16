/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vigenere.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:06:00 by mhotting          #+#    #+#             */
/*   Updated: 2023/09/16 03:14:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIGENERE_H
# define VIGENERE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 1024

void			ft_putchar(char c);
void			ft_putstr(char *str);
unsigned int	ft_strlen(char *str);
char			*ft_strdup(char *str);
char			*ft_strcat(char *dest, char *src);
char			ft_getchar(void);

char			*read_file(char *file_name);
void			flush_buffer(char buffer[BUFFER_SIZE]);
int				append_content(char **file_content, char buffer[BUFFER_SIZE]);

#endif
