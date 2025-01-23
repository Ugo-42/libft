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
	size_t	len;

	len = 0;
	if (!str)
		ft_exit_error(1, "In 'ft_utf8_strlen': " BAD_ARG, 0);
	while (*str)
	{
		if ((*str & 0xC0) != 0x80)
			len++;
		str++;
	}
	return (len);
}
