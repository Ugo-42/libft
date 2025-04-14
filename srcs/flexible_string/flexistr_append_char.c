/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flexistr_append_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:48:40 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/14 13:02:01 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	flexistr_append_char(t_flexistr *fs, const char c)
{
	if (!fs || !c)
		return (1);
	if (fs->len + 1 >= fs->size)
	{
		if (flexistr_resize(fs, ft_next_power_of_2(2 * (fs->len + 1))) != 0)
			return (-1);
	}
	fs->string[fs->len++] = c;
	fs->string[fs->len] = '\0';
	return (0);
}
