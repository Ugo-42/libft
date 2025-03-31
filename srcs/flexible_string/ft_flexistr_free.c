/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flexistr_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:48:40 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/03/31 16:32:00 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	flexistr_free(t_flexible_string *fs)
{
	if (!fs)
		return ;
	free(fs->string);
	bzero(fs, sizeof(t_flexible_string));
}
