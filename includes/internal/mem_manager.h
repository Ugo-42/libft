/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:48:40 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/05/14 15:40:08 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_MANAGER_H
# define MEM_MANAGER_H

# include <stddef.h>
# include <stdlib.h>

/* MUST be power of two !! */
# define MM_BUCKET_COUNT 1024

/* Internal Structs */

typedef struct s_mem_block		t_mem_block;
typedef struct s_mem_header		t_mem_header;
typedef struct s_mem_manager	t_mem_manager;

/* --- */

struct s_mem_header
{
	size_t	size;
};

struct s_mem_block
{
	t_mem_header	*base;
	t_mem_block		*next;
};

struct s_mem_manager
{
	t_mem_block	*buckets[MM_BUCKET_COUNT];
};

/* Internal Functions */
size_t			mm_hash(void *ptr);
t_mem_manager	*internal_manager(void);

# ifdef DEBUG

typedef struct s_debug_collisions
{
	unsigned int	depth;
	unsigned int	empty_buckets;
	unsigned int	index;
	unsigned int	max_depth;
	unsigned int	total_collisions;
	unsigned int	total_pointers;
}	t_debug_collisions;

void			mm_analyze_collisions(void);

# endif

#endif
