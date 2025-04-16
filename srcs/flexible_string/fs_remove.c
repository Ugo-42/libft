/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:45:43 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/16 11:35:06 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fs_remove(t_flexistr *fs, size_t start, size_t end)
{
	size_t	new_size;

	if (!fs || !fs->string)
	{
		if (fs)
			fs->errno = 1;
		return (1);
	}
	if (start >= fs->len || end < start)
		return (fs->errno = 0);
	if (end >= fs->len)
		end = fs->len - 1;
	new_size = fs->len - (end + 1 - start);
	ft_memmove(fs->string + start, fs->string + end + 1, fs->len - end);
	fs->len = new_size;
	if (fs->len < fs->size / 4)
	{
		new_size = ft_next_power_of_2(fs->len + 1);
		if (new_size < fs->size)
			fs_resize(fs, new_size);
	}
	return (fs->errno = 0);
}
