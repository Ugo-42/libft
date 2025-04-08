/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:26:47 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/08 10:43:08 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define UNIFORM_MASK 0xA5A5A5A5A5A5A5A5ULL
#define GOLDEN_RATIO 0x9E3779B97F4A7C15ULL

#define MULT1 0xBF58476D1CE4E5B9ULL
#define MULT2 0x94D049BB133111EBULL

unsigned long	ft_random(void)
{
	static uint64_t	seed = 0;
	static bool		init = 0;
	void			*ptr;
	uint64_t		addr;
	uint64_t		z;

	if (!init)
	{
		ptr = malloc(1);
		addr = (uintptr_t)ptr;
		free(ptr);
		seed = addr ^ UNIFORM_MASK;
		init = 1;
	}
	seed += GOLDEN_RATIO;
	z = seed;
	z = (z ^ (z >> 30)) * MULT1;
	z = (z ^ (z >> 27)) * MULT2;
	z = z ^ (z >> 31);
	return (z & LONG_MAX);
}
