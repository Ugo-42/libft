/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flexistr_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:48:40 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/03/31 16:31:27 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	flexistr_init(t_flexistr *fs, size_t initial_size)
{
	if (!fs || !initial_size)
		return (1);
	fs->len = 0;
	fs->string = malloc(initial_size);
	if (!fs->string)
	{
		fs->size = 0;
		return (-1);
	}
	fs->size = initial_size;
	fs->string[0] = '\0';
	return (0);
}
