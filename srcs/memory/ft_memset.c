/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:23:06 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/23 09:55:20 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;
	unsigned long	value;
	const size_t	word_size = sizeof(unsigned long);

	b = (unsigned char *)s;
	value = (unsigned char)c;
	value |= value << 8;
	value |= value << 16;
	value |= value << 32;
	while (n >= word_size)
	{
		*(unsigned long *)b = value;
		b += word_size;
		n -= word_size;
	}
	while (n--)
	{
		*b++ = (unsigned char)c;
	}
	return (s);
}
