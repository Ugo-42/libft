/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:43:32 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/12/11 15:44:00 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include "libft_string.h"
#include <stdarg.h>

static char	*ft_handle_format(va_list args, const char *format)
{
	if (*format == '%')
		return (ft_strdup("%"));
	else if (*format == 'c')
		return (ft_ctoa(va_arg(args, int)));
	else if (*format == 's')
		return (ft_strdup(va_arg(args, char *)));
	else if (*format == 'p' || *format == 'P')
		return (ft_addrtoa(va_arg(args, uintptr_t), *format == 'P'));
	else if (*format == 'd' || *format == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_utoa(va_arg(args, unsigned int)));
	else if (*format == 'x' || *format == 'X')
		return (ft_xtoa(1, va_arg(args, unsigned int), *format == 'X'));
	else
		return (NULL);
}

static void	ft_append(char **dest, char *src, size_t len)
{
	char	*result;
	size_t	old_len;
	
	old_len = ft_strlen(*dest);
	result = ft_realloc(*dest, old_len, old_len + len + 1);
	if (!result)
	    return;
	ft_memcpy(result + old_len, src, len);
	result[old_len + len] = '\0';
	*dest = result;
}

char	*ft_stringf(const char *str, ...)
{
	const char	*next_format;
	char		*result;
	char		*tmp;
	va_list		args;

	if (!str || (str[0] == '%' && !str[1]))
		return (-1);
	va_start(args, str);
	result = NULL;
	while (*str)
	{
		next_format = ft_strchr(str, '%');
		if (!next_format)
		{
			ft_append(&result, str, ft_strlen(str));
			break ;
		}
		ft_append(&result, str, next_format - str);
		tmp = ft_handle_format(args, ++next_format);
		if (!tmp)
			return (free(result), NULL);
		ft_append(&result, tmp, ft_strlen(tmp));
		free(tmp);
		if (*str == '%' && !*(str + 1))
			return (result);
		str = next_format + 1;
	}
	va_end(args);
	return (result);
}
