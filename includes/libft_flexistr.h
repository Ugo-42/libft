/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_flexistr.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:48:40 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/03/31 16:39:52 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FLEXISTR_H
# define LIBFT_FLEXISTR_H

typedef struct s_flexible_string
{
	char	*string;
	size_t	len;
	size_t	size;
}	t_flexible_string;

int		flexistr_init(t_flexible_string *fs, size_t initial_size);
int		flexistr_resize(t_flexible_string *fs, size_t new_size);
void	flexistr_append(t_flexible_string *fs, char *s, bool free);
void	flexistr_free(t_flexible_string *fs);

#endif
