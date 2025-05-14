/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:37:00 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/05/14 15:38:39 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/internal/mem_manager.h"

static void	fill_mem(void)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		mm_alloc(rand() % 128);
		i++;
	}
}

#ifdef DEBUG

static void	debug_analyze(void)
{
	mm_analyze_collisions();
}
#endif

int	main(void)
{
	fill_mem();
#ifdef DEBUG
	debug_analyze();
#endif
	mm_destroy();
	return (0);
}
