/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:26:47 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/08 09:50:31 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_random(void)
{
	static unsigned int	counter = 42;
	uintptr_t			seed;
	void				*ptr;

	ptr = malloc(42);
	seed = (uintptr_t)ptr;
	free(ptr);
	counter += 42;
	seed ^= counter * seed + 42;
	return ((seed * 42 * (seed / 42)) & LONG_MAX);
}
