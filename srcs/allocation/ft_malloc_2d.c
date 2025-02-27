/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:25:13 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/02/27 11:29:06 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_malloc_2d(size_t cols, size_t rows, size_t size)
{
	void	**array;
	size_t	i;

	array = malloc(cols * sizeof(void *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < cols)
	{
		array[i] = malloc(rows * size);
		if (!array[i])
		{
			while (i > 0)
				free(array[--i]);
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}
