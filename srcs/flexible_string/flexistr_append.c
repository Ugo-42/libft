/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flexistr_append.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:48:40 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/03/31 16:31:44 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_if(char *ptr, bool should_free)
{
	if (should_free)
	{
		free(ptr);
	}
}

int	flexistr_append(t_flexistr *fs, char *s, bool free_input)
{
	size_t	new_len;

	if (!fs || !s)
	{
		free_if(s, free_input);
		return (1);
	}
	new_len = fs->len + ft_strlen(s);
	if (new_len >= fs->size)
	{
		if (flexistr_resize(fs, ft_next_power_of_2(2 * new_len)) != 0)
		{
			free_if(s, free_input);
			return (-1);
		}
	}
	ft_strcpy(fs->string + fs->len, s);
	fs->len = new_len;
	free_if(s, free_input);
	return (0);
}
