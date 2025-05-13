/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:23:42 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/05/13 23:27:24 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/mem_manager.h"

void	mm_destroy(void)
{
	t_mem_manager	*g_mgr;
	t_mem_block		*current;
	t_mem_block		*next;
	size_t			index;

	g_mgr = internal_manager();
	index = 0;
	while (index < MM_BUCKET_COUNT)
	{
		current = g_mgr->buckets[index];
		while (current)
		{
			next = current->next;
			free(current->base);
			free(current);
			current = next;
		}
		g_mgr->buckets[index++] = NULL;
	}
}
