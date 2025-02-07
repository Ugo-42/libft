/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:22:05 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/23 09:53:04 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_utf8_strlen(const char *str)
{
	size_t len;

	if (!str)
		ft_exit_error(1, "In 'ft_utf8_strlen': " BAD_ARG, 0);
	len = 0;
	while (*str)
	{
		if ((*str & 0xC0) != 0x80)
		{
			len++;
			if ((*str & 0xF0) == 0xF0)
				str += 4;
			else if ((*str & 0xE0) == 0xE0)
				str += 3;
			else if ((*str & 0xC0) == 0xC0)
				str += 2;
			else
				str++;
		}
		else
		{
			str++;
		}
	}
	return (len);
}
