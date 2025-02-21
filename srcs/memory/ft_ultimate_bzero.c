/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_bzero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:22:50 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/02/21 14:50:49 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ' initialize every passed variable to zero:
 '   if type[0] == '%'
 '     the the following type will be treated for all passed variables.
 '   else
 '     you need to separate each type with a comma ','.
 ' Exemples:
 '   ("%i", (int)&a, (int)&b, (int)&c)
 '   ("i,c,zu,d", (int)&a, (char)&b, (size_t)&c, (double)&d)
*/

static size_t	ft_type_size(const char *type)
{
	if (type)
	{
		if (ft_strcmp(type, "i") == 0)
			return (sizeof(int));
		if (ft_strcmp(type, "u") == 0)
			return (sizeof(unsigned int));
		if (ft_strcmp(type, "f") == 0)
			return (sizeof(float));
		if (ft_strcmp(type, "d") == 0)
			return (sizeof(double));
		if (ft_strcmp(type, "ld") == 0)
			return (sizeof(long double));
		if (ft_strcmp(type, "lu") == 0)
			return (sizeof(unsigned long));
		if (ft_strcmp(type, "llu") == 0)
			return (sizeof(unsigned long long));
		if (ft_strcmp(type, "ll") == 0)
			return (sizeof(long long));
		if (ft_strcmp(type, "zu") == 0)
			return (sizeof(size_t));
		if (ft_strcmp(type, "p") == 0)
			return (sizeof(void *));
	}
	return (0);
}

static bool	ft_valid_type(const char *type)
{
	static const char	*valid[] = {
		"i", "u", "f", "d", "ld", "lu", "llu", "ll", "zu", "p"
	};
	size_t				i;
	size_t				nmemb;

	nmemb = sizeof(valid) / sizeof(valid[0]);
	i = 0;
	while (i < nmemb)
	{
		if (ft_strcmp(type, valid[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}

static int	process_format(const char *type, va_list *args)
{
	void	*var;

	if (!ft_valid_type(type))
	{
		ft_warning("In 'ft_ultimate_bzero': Invalid Format");
		return (-1);
	}
	var = va_arg(*args, void *);
	if (!var)
	{
		ft_warning("In 'ft_ultimate_bzero': " BAD_ARG);
		return (-1);
	}
	ft_bzero(var, ft_type_size(type));
	return (0);
}

void	ft_ultimate_bzero(const char *formats, ...)
{
	va_list	args;
	char	**types;
	size_t	i;

	types = ft_split(formats, ',');
	if (!types)
		ft_exit_error(1, "In 'ft_ultimate_bzero': " BAD_ALLOC);
	va_start(args, formats);
	i = 0;
	while (types[i])
	{
		if (process_format(types[i], &args) != 0)
			break ;
		i++;
	}
	va_end(args);
	ft_free_2d_char_array(&types);
}
