/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_mgr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:53:59 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/05/14 11:45:24 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/mem_manager.h"
#include "libft.h"

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

#ifdef DEBUG

void	_print_collisions_result(t_debug_collisions c)
{
	ft_change_color(0xC4422C);
	ft_printf(
		"╔══════════════════════════════════════╗\n"
		"║    Memory Manager Collision Info     ║\n"
		"╠══════════════════════════════════════╣\n"
		"║ Total Buckets:             %>u   ║\n"
		"║ Buckets with Collisions:   %>u   ║\n"
		"║ Max Bucket Depth:          %>u   ║\n"
		"╚══════════════════════════════════════╝\n",
		7, MM_BUCKET_COUNT, 7, c.total_collisions, 7, c.max_depth);
	ft_reset_color();
}

void	mm_analyze_collisions(void)
{
	const t_mem_manager	*g_mgr = internal_manager();
	t_mem_block			*current;
	t_debug_collisions	c;

	c = (t_debug_collisions){0};
	while (c.index < MM_BUCKET_COUNT)
	{
		current = g_mgr->buckets[c.index];
		if (current && current->next)
			c.total_collisions++;
		c.depth = 0;
		while (current)
		{
			c.depth++;
			current = current->next;
		}
		if (c.depth > c.max_depth)
			c.max_depth = c.depth;
		c.index++;
	}
	_print_collisions_result(c);
}

#endif
