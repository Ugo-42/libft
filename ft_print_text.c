/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:51:07 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/20 15:56:04 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putchar_fd(const char c, int fd)
{
	return (write(fd, &c, 1));
}

size_t	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

size_t	ft_putstrn_fd(const char *s, size_t n, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, n));
}
