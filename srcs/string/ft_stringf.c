/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:43:32 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/14 11:54:42 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_handle_alignment(va_list args, char type)
{
	char	*str;
	size_t	padding;

	str = va_arg(args, char *);
	padding = va_arg(args, size_t);
	if (type == '<')
		return (ft_str_left_padded(str, padding));
	if (type == '>')
		return (ft_str_right_padded(str, padding));
	if (type == '^')
		return (ft_str_middle_padded(str, padding));
	return (0);
}

static char	*ft_handle_format(va_list args, const char format)
{
	if (format == '%')
		return (ft_strdup("%"));
	else if (format == 'c')
		return (ft_ctoa(va_arg(args, int)));
	else if (format == 's')
		return (ft_strdup(va_arg(args, char *)));
	else if (format == 'p' || format == 'P')
		return (ft_addrtoa(va_arg(args, uintptr_t), format == 'P'));
	else if (format == 'd' || format == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (format == 'u')
		return (ft_utoa(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_xtoa(va_arg(args, unsigned int), format == 'X'));
	else if (format == '<' || format == '>' || format == '^')
		return (ft_handle_alignment(args, format));
	return (NULL);
}

char	*ft_stringf(const char *str, ...)
{
	t_flexistr	fs;
	va_list		args;
	size_t		len;

	if (!str || flexistr_init(&fs, 256) != 0)
		return (NULL);
	va_start(args, str);
	while (*str)
	{
		len = ft_strcspn(str, "%");
		flexistr_n_append(&fs, str, len);
		str += len;
		if (!*str || !*(str + 1))
			break ;
		flexistr_append(&fs, ft_handle_format(args, *(str + 1)), true);
		str += 2;
	}
	va_end(args);
	return (flexistr_finalize(&fs));
}
