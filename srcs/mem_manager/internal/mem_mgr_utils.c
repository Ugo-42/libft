/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_mgr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:53:59 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/05/14 15:32:44 by ugwentzi         ###   ########.fr       */
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

# define TITLE "\033[1;38;2;117;85;170m"
# define TBL   "\033[38;2;136;32;160m"
# define TXT   "\033[38;2;80;191;191m"
# define BTXT  "\033[1;38;2;80;191;191m"

/*
void	_print_collisions_result(t_debug_collisions c)
{
	ft_printf(
		TBL "╭──────────────────────────────────────╮\n"
		TBL "│" TITLE "    Memory Manager Collision Info     " TBL "│\n"
		TBL "├──────────────────────────────────────┤\n"
		TBL "│" TXT " Total Buckets:             " BTXT "%>u%R   " TBL "│\n"
		TBL "│" TXT " Total Pointers:            " BTXT "%>u%R   " TBL "│\n"
		TBL "│" TXT " Buckets with Collisions:   " BTXT "%>u%R   " TBL "│\n"
		TBL "│" TXT " Max Bucket Depth:          " BTXT "%>u%R   " TBL "│\n"
		TBL "│" TXT " Collision Percentage:      " BTXT "%>u%R   " TBL "│\n"
		TBL "╰──────────────────────────────────────╯%R\n",
		7, MM_BUCKET_COUNT,
		7, c.total_pointers,
		7, c.total_pointers,
		7, c.total_pointers,
		7, c.total_pointers);
}
*/
void	_print_collisions_result(t_debug_collisions c)
{
	(void)c;
	ft_printf(
		TBL "╭──────────────────────────────────────╮\n"
		TBL "│" TITLE "    Memory Manager Collision Info     " TBL "│\n"
		TBL "├──────────────────────────────────────┤\n"
		TBL "│" TXT " Total Buckets:             " BTXT "%>u%R   " TBL "│\n"
		TBL "│" TXT " Total Pointers:            " BTXT "%>u%R   " TBL "│\n"
		TBL "│" TXT " Buckets with Collisions:   " BTXT "%>u%R   " TBL "│\n"
		TBL "│" TXT " Buckets with Collisions:   " BTXT "%>u%R   " TBL "│\n"
		, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7);
	/*
		TBL "│" TXT " Collision Percentage:      " BTXT "%>u%R   " TBL "│\n"
		TBL "│" TXT " Max Bucket Depth:          " BTXT "%>u%R   " TBL "│\n" \
		TBL "╰──────────────────────────────────────╯%R\n",
		7, MM_BUCKET_COUNT,
		7, 0,
		7, 0,
		7, 0,
		7, 0);
		*/
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
			c.total_pointers++;
			c.depth++;
			current = current->next;
		}
		if (c.depth > c.max_depth)
			c.max_depth = c.depth;
		c.index++;
	}
	c.collision_percentage = ft_iternary(c.total_pointers > 0,
			((float)c.total_collisions / c.total_pointers) * 100, 0);
	_print_collisions_result(c);
}

#endif
