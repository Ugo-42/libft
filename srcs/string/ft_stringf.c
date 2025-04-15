/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:43:32 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/15 15:09:02 by ugwentzi         ###   ########.fr       */
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

static void	ft_handle_format(t_flexistr *fs, va_list args, const char format)
{
	if (format == '%')
		fs_append_char(fs, '%');
	else if (format == 'c')
		fs_append_char(fs, va_arg(args, int));
	else if (format == 's')
		fs_append(fs, va_arg(args, char *), false);
	else if (format == 'p' || format == 'P')
		;//(va_arg(args, uintptr_t), format == 'P');
	else if (format == 'd' || format == 'i')
		fs_append_nb(fs, va_arg(args, int), NULL);
	else if (format == 'u')
		fs_append_nb(fs, va_arg(args, unsigned int), NULL);
	else if (format == 'x')
		fs_append_nb(fs, va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		fs_append_nb(fs, va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '<' || format == '>' || format == '^')
		(void)ft_handle_alignment(args, format);
}

char	*ft_stringf(const char *str, ...)
{
	t_flexistr	fs;
	va_list		args;
	size_t		len;

	if (!str || fs_init(&fs, 256) != 0)
		return (NULL);
	va_start(args, str);
	while (*str)
	{
		len = ft_strcspn(str, "%");
		fs_n_append(&fs, str, len);
		str += len;
		if (!*str || !*(str + 1))
			break ;
		ft_handle_format(&fs, args, *(str + 1));
		if (!fs.string)
			return (NULL);
		str += 2;
	}
	va_end(args);
	return (fs_finalize(&fs));
}
