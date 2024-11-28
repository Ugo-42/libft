/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ultimate_join.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:40:25 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/28 16:01:40 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_allocation.h"
#include "libft_string.h"
#include "libft_count.h"
#include <stdarg.h>

static size_t	ft_total_string_len(const char *first, va_list args)
{
	size_t		len;
	const char	*str;

	len = 0;
	str = first;
	while (str != NULL)
	{
		len += ft_strlen(str);
		str = va_arg(args, const char *);
	}
	return (len);
}

char	*ft_str_ultimate_join(const char *first, ...)
{
	va_list		args;
	va_list		args_copy;
	size_t		i;
	const char	*str;
	char		*result;

	if (!first)
		return (NULL);
	va_start(args, first);
	va_copy(args_copy, args);
	result = malloc((ft_total_string_len(first, args_copy) + 1) * sizeof(char));
	va_end(args_copy);
	if (!result)
		return (NULL);
	i = 0;
	str = first;
	while (str != NULL)
	{
		ft_strcpy(&result[i], str);
		i += ft_strlen(str);
		str = va_arg(args, const char *);
	}
	va_end(args);
	return (result);
}
