/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:46:48 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/05/12 23:50:30 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*mm_alloc(size_t size)
{
	t_mem_header	*header;
	t_mem_block		*block;
	t_mem_manager	*mgr;
	size_t			index;

	header = malloc(sizeof(t_mem_header) + size);
	if (!header)
		return (NULL);
	header->size = size;
	block = malloc(sizeof(t_mem_block));
	if (!block)
	{
		free(header);
		return (NULL);
	}
	mgr = internal_manager();
	index = mm_hash(header + 1);
	block->base = header;
	block->next = mgr->buckets[index];
	mgr->buckets[index] = block;
	return (header + 1);
}
