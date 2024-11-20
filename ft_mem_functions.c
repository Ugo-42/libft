/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:45:41 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/20 10:51:43 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem;
	unsigned char		byte;

	if (!s)
		return (NULL);
	byte = c;
	mem = s;
	while (n--)
	{
		if (*mem == byte)
			return ((void *)mem);
		mem++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*b1;
	unsigned const char	*b2;
	size_t				i;

	if (!s1 || !s2 || n == 0)
		return (0);
	b1 = s1;
	b2 = s2;
	i = 0;
	while (i < n - 1 && b1[i] == b2[i])
		i++;
	return (b1[i] - b2[i]);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (!dest || !src)
		return (NULL);
	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest || !src)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		d = dest + n;
		s = src + n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;

	if (!s)
		return (NULL);
	b = s;
	while (n--)
		*b++ = c;
	return (s);
}
