/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:04:41 by mhotting          #+#    #+#             */
/*   Updated: 2023/09/15 00:49:29 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vigenere.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	char			*res;
	unsigned int	str_len;
	unsigned int	i;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	res = (char *)malloc((str_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	if (src == NULL)
		return (dest);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
