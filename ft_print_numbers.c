/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:35:14 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/21 10:52:24 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int fd, int n)
{
	unsigned int	nb;
	char			result[12];
	int				i;

	nb = n;
	if (n < 0)
		nb = -n;
	i = 10;
	while (nb > 0 || i == 10)
	{
		result[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		result[i--] = '-';
	result[11] = '\0';
	return (ft_putstr_fd(fd, &result[++i]));
}

size_t	ft_putunbr_fd(int fd, unsigned int n)
{
	char	result[11];
	int		i;

	i = 9;
	while (n > 0 || i == 9)
	{
		result[i--] = (n % 10) + '0';
		n /= 10;
	}
	result[10] = '\0';
	return (ft_putstr_fd(fd, &result[++i]));
}

size_t	ft_print_hex_fd(int fd, unsigned long n, bool uppercase)
{
	const char	*hex;
	char		result[17];
	int			i;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	i = 15;
	while (n > 0 || i == 15)
	{
		result[i--] = hex[n % 16];
		n /= 16;
	}
	result[16] = '\0';
	return (ft_putstr_fd(fd, &result[++i]));
}
