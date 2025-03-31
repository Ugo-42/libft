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

void	flexistr_append(t_flexible_string *fs, char *s, bool free)
{
	size_t	new_len;

	if (!fs || !s)
		return ;
	new_len = fs->len + ft_strlen(s);
	if (new_len >= fs->size)
	{
		if (flexistr_resize(ft_next_power_of_2(new_len)) != 0)
			return ;
	}
	ft_strcpy(fs->string, s);
	fs->len = new_len;
}
