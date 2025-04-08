/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flexistr_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:45:43 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/08 16:30:15 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	flexistr_remove(t_flexistr *fs, size_t start, size_t end)
{
	size_t	remove_len;
	size_t	new_size;

	if (!fs || !fs->string)
		return (1);
	if (start >= fs->len || end <= start)
		return (0);
	if (end > fs->len)
		end = fs->len;
	new_size = fs->len - (end - start);
	remove_len = end - start;
	ft_memmove(fs->string + start, fs->string + end, fs->len - end + 1);
	fs->len = new_size;
	if (fs->len < fs->size / 4)
	{
		new_size = ft_next_power_of_2(fs->len + 1);
		if (new_size < fs->size)
			flexistr_resize(fs, new_size);
	}
	return (0);
}
