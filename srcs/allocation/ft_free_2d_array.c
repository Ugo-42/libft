/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:15:51 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/29 16:17:58 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_allocation.h"

void	ft_free_2d_array(char **split)
{
	size_t	i;

	if (split)
	{
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
	}
}
