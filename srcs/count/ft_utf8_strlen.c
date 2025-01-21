/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:22:05 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/21 13:52:05 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_error.h"

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
