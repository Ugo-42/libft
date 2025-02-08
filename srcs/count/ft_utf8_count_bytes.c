/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_count_bytes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:00:00 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/02/08 12:00:00 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_utf8_count_bytes(const char *s, size_t n)
{
	size_t	i;
	size_t	byte_count;
	size_t	char_count;

	byte_count = 0;
	char_count = 0;
	if (!s)
		ft_exit_error(1, "In 'ft_utf8_count_bytes': " BAD_ARG, false);
	i = 0;
	while (s[i] && char_count < n)
	{
		if ((s[i] & 0x80) == 0)
			i += 1;
		else if ((s[i] & 0xE0) == 0xC0)
			i += 2;
		else if ((s[i] & 0xF0) == 0xE0)
			i += 3;
		else if ((s[i] & 0xF8) == 0xF0)
			i += 4;
		else
			i++;
		byte_count += (i - byte_count);
		char_count++;
	}
	return (byte_count);
}
