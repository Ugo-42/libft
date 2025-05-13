/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manager_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:53:59 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/05/10 17:57:41 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/mem_manager.h"

#define GOLDEN_RATIO 0x9E3779B97F4A7C15ULL

#define MULT1 0xBF58476D1CE4E5B9ULL
#define MULT2 0x94D049BB133111EBULL
#define MULT3 0xA3C9A207F6A1BC33ULL

size_t	mm_hash(void *ptr)
{
	size_t	x;

	x = (size_t)ptr ^ GOLDEN_RATIO;
	x = (x ^ (x >> 27)) * MULT1;
	x = (x ^ (x >> 32)) * MULT2;
	x = (x ^ (x >> 24)) * MULT3;
	return (x & (MM_BUCKET_COUNT - 1));
}

t_mem_manager	*internal_manager(void)
{
	static t_mem_manager	g_mem_mgr;

	return (&g_mem_mgr);
}
