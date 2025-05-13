/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:09:47 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/05/13 22:13:29 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/mem_manager.h"

void	mm_free(void *ptr)
{
	t_mem_manager	*g_mgr;
	t_mem_block		*prev;
	t_mem_block		*current;
	size_t			index;

	if (!ptr)
		return ;
	g_mgr = internal_manager();
	index = mm_hash(ptr);
	prev = NULL;
	current = g_mgr->buckets[index];
	while (current)
	{
		if (current->base == ((t_mem_header *)ptr - 1))
		{
			if (prev)
				prev->next = current->next;
			else
				g_mgr->buckets[index] = current->next;
			return (free(current->base), free(current));
		}
		prev = current;
		current = current->next;
	}
}
