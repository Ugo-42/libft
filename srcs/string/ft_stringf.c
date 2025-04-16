/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:43:32 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/16 10:42:26 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "internal/ft_stringf.h"

static void	handle_alignment(t_flexistr *fs, va_list args, const char align)
{
	size_t	padding;
	size_t	to_add;
	char	*pad_str;

	padding = va_arg(args, size_t);
	if (fs->last_append_len >= padding)
		return;
	to_add = padding - fs->last_append_len;
	pad_str = ft_calloc(to_add + 1, sizeof(char));
	if (!pad_str)
	{
		fs->errno = -1;
		return;
	}
	ft_memset(pad_str, ' ', to_add);
	if (align == '<')
		fs_add(fs, pad_str, fs->len); // right pad
	else if (align == '>')
		fs_add(fs, pad_str, fs->len - fs->last_append_len); // left pad
	else if (align == '^')
	{
		fs_add(fs, pad_str, fs->len - fs->last_append_len); // left pad
		fs_add(fs, pad_str, fs->len); // right pad
	}
	free(pad_str);
}

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
			handle_alignment(&fs, args, *(++str));
		handle_format(&fs, args, *(str + 1));
		if (!fs.string)
			return (NULL);
		str += 2;
	}
	va_end(args);
	return (fs_finalize(&fs));
}
