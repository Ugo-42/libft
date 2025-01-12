/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:21:39 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/26 09:21:40 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_allocation.h"
#include "libft_string.h"

char	**ft_strdup_2d(const char **array, size_t nmemb)
{
	char	**copy;
	size_t	i;

	if (!array)
		return (NULL);
	copy = malloc((nmemb + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < nmemb)
	{
		copy[i] = ft_strdup(array[i]);
		if (!copy[i])
		{
			ft_free_2d_array(&copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
