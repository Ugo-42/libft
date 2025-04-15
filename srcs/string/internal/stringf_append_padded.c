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

void	stringf_append_padded(t_flexistr *fs, char *s, const char direction)
{
	if (!s)
		fs_append(fs, "(null)", false);
	else
		fs_append(fs, s, false);
}
