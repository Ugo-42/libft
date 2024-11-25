/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:51:07 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/25 10:54:11 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include "libft_count.h"

size_t	ft_print_address_fd(int fd, uintptr_t addr)
{
	if (!addr)
		return (write(fd, "(nil)", 5));
	return (ft_putstrn_fd(fd, "0x", 2) + ft_print_hex_fd(fd, addr, false));
}

size_t	ft_putchar_fd(int fd, const char c)
{
	return (write(fd, &c, 1));
}

size_t	ft_putstr_fd(int fd, const char *s)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

size_t	ft_putstrn_fd(int fd, const char *s, size_t n)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, n));
}
