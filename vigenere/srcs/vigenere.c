/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vigenere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:31:38 by mhotting          #+#    #+#             */
/*   Updated: 2023/09/18 16:08:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vigenere.h"

char	vigenere_char_encrypt(char to_encrypt, char current_key)
{
	int		current_key_index;
	int		to_encrypt_index;
	char	res;

	current_key_index = char_index(current_key);
	to_encrypt_index = char_index(to_encrypt);
	res = 'a' + ((to_encrypt_index + current_key_index) % 26);
	if (is_upper(to_encrypt))
		res -= 32;
	return (res);
}

char	*encrypt(char *message, char *key)
{
	char			*res;
	unsigned int	key_len;
	unsigned int	i;
	unsigned int	skip;

	if (key == NULL || message == NULL)
		return (NULL);
	res = ft_strdup(message);
	if (res == NULL)
		return (NULL);
	key_len = ft_strlen(key);
	if (key_len == 0)
		return (NULL);
	i = 0;
	skip = 0;
	while (res[i] != '\0')
	{
		if (is_lower(res[i]) || is_upper(res[i]))
			res[i] = vigenere_char_encrypt(res[i], key[(i - skip) % key_len]);
		else
			skip++;
		i++;
	}
	return (res);
}
