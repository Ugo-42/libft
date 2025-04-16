/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_n_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:48:40 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/16 11:32:41 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fs_n_append(t_flexistr *fs, const char *s, size_t n)
{
	size_t	new_len;

	if (!fs || !s || !n)
	{
		if (fs)
			fs->errno = 1;
		return (1);
	}
	new_len = fs->len + ft_strnlen(s, n);
	if (new_len >= fs->size)
	{
		if (fs_resize(fs, ft_next_power_of_2(2 * new_len)) != 0)
			return (fs->errno = -1);
	}
	ft_strncpy(fs->string + fs->len, s, n);
	fs->len = new_len;
	return (fs->errno = 0);
}
