/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/21 11:23:06 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINT_H
# define LIBFT_PRINT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ft_print_numbers.c */
size_t	ft_print_hex_fd(int fd, unsigned long n, bool uppercase);
size_t	ft_putnbr_fd(int fd, int n);
size_t	ft_putunbr_fd(int fd, unsigned int n);

/* ft_print_text.c */
size_t	ft_putchar_fd(int fd, const char c);
size_t	ft_putstr_fd(int fd, const char *s);
size_t	ft_putstrn_fd(int fd, const char *s, size_t n);
size_t  ft_print_address_fd(int fd, uintptr_t addr);

/* ft_printf.c */
int	ft_printf(const char *str, ...);
int	ft_fprintf(int fd, const char *str, ...);

#endif
