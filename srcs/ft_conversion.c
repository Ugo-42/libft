/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:04:36 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/21 11:24:05 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_conversion.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	if (!str)
		return (0);
	while ((*str >= 0x9 && *str <= 0x0D) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	result *= sign;
	return (result);
}

// ft_itoa
static int	ft_total_len(int n)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = n;
	if (n == 0)
		len++;
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*result;
	int				len;
	int				i;

	len = ft_total_len(n);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	nb = n;
	if (n < 0)
		nb = -n;
	i = len;
	result[i--] = '\0';
	while (nb > 0)
	{
		result[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		result[i--] = '-';
	return (result);
}
