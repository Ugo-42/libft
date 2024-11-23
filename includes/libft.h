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

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

/* ft_other_functions.c */
void	ft_segfault(void);

/* ft_print_numbers.c */
size_t	ft_print_hex_fd(int fd, unsigned long n, bool uppercase);
size_t	ft_putnbr_fd(int fd, int n);
size_t	ft_putunbr_fd(int fd, unsigned int n);

/* ft_print_text.c */
size_t	ft_putchar_fd(int fd, const char c);
size_t	ft_putstr_fd(int fd, const char *s);
size_t	ft_putstrn_fd(int fd, const char *s, size_t n);
size_t  ft_print_address_fd(int fd, uintptr_t addr);

/* ft_split_join.c */
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);

/* ft_is_functions.c */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/* ft_string_functions.c */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);

/* ft_string_copy_functions.c */
void	ft_strcpy(char *dest, const char *src);
void	ft_strncpy(char *dest, const char *src, int n);

/* ft_conversions.c */
int		ft_atoi(const char *str);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);

/* ft_printf.c */
int	ft_printf(const char *str, ...);
int	ft_fprintf(int fd, const char *str, ...);

#endif
