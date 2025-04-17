/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringf_append_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:38:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/15 16:23:42 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stringf_append_ptr(t_flexistr *fs, uintptr_t addr)
{
	if (!addr)
		fs_append(fs, "(nil)", false);
	else
	{
		fs_append(fs, "0x", false);
		fs_append_nb(fs, addr, "0123456789abcdef");
		if (fs->errno == 0)
			fs->last_append_len += 2;
	}
}

void	stringf_append_str(t_flexistr *fs, char *s)
{
	if (!s)
		fs_append(fs, "(null)", false);
	else
		fs_append(fs, s, false);
}
