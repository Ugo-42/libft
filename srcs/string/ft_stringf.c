/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:43:32 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/17 14:26:12 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "internal/ft_stringf.h"

static void	handle_format(t_flexistr *fs, va_list args, const char format)
{
	if (format == '%')
		fs_append_char(fs, '%');
	else if (format == 'c')
		fs_append_char(fs, va_arg(args, int));
	else if (format == 's')
		stringf_append_str(fs, va_arg(args, char *));
	else if (format == 'p')
		stringf_append_ptr(fs, va_arg(args, uintptr_t));
	else if (format == 'i' || format == 'd')
		fs_append_nb(fs, va_arg(args, int), NULL);
	else if (format == 'l')
		fs_append_nb(fs, va_arg(args, long), NULL);
	else if (format == 'u')
		fs_append_nb(fs, va_arg(args, unsigned int), NULL);
	else if (format == 'x')
		fs_append_nb(fs, va_arg(args, unsigned long), "0123456789abcdef");
	else if (format == 'X')
		fs_append_nb(fs, va_arg(args, unsigned long), "0123456789ABCDEF");
}

static void	handle_alignment(t_flexistr *fs, va_list args, const char *str)
{
	size_t	padding;
	size_t	pad_len;

	handle_format(fs, args, *(str + 1));
	padding = va_arg(args, size_t);
	if (fs->last_append_len >= padding)
		return ;
	pad_len = padding - fs->last_append_len;
	if (*str == '<')
		stringf_pad(fs, pad_len, fs->len);
	else if (*str == '>')
		stringf_pad(fs, pad_len, fs->len - fs->last_append_len);
	else if (*str == '^')
	{
		stringf_pad_middle(fs, pad_len, fs->len - fs->last_append_len);
	}
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
		if (*(str + 1) == '<' || *(str + 1) == '>' || *(str + 1) == '^')
			handle_alignment(&fs, args, ++str);
		else
			handle_format(&fs, args, *(str + 1));
		if (!fs.string)
			return (NULL);
		str += 2;
	}
	va_end(args);
	return (fs_finalize(&fs));
}
