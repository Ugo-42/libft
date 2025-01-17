/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentile_strnb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:54:00 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/06 10:54:37 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_allocation.h"
#include "libft_error.h"
#include "libft_maths.h"
#include "libft_sort.h"
#include "libft_string.h"

static int	ft_cmp(const void *a, const void *b)
{
	return (ft_cmp_strnb(*(char **)a, *(char **)b));
}

static char	*ft_find_percentile(const char **numbers, char **copy,
		size_t nmemb, size_t index)
{
	size_t	i;

	i = 0;
	while (i < nmemb)
	{
		if (ft_cmp_strnb(copy[index], numbers[i]) == 0)
		{
			ft_free_2d_array(&copy);
			return ((char *)numbers[i]);
		}
		i++;
	}
	ft_free_2d_array(&copy);
	ft_exit_error(1, "In 'ft_percentile_strnb': " BAD_BAD, 0);
	return (NULL);
}

char	*ft_percentile_strnb(const char **numbers, size_t nmemb,
		double percentile)
{
	char	**copy;
	size_t	index;

	if (!numbers || nmemb == 0 || percentile < 0 || percentile > 100)
		ft_exit_error(1, "In 'ft_percentile_strnb': " BAD_ARG, 0);
	index = (size_t)((percentile / 100.0) * (nmemb - 1));
	if (!ft_is_sorted(numbers, nmemb, sizeof(char *), ft_cmp))
	{
		copy = ft_strdup_2d(numbers, nmemb);
		if (!copy)
			ft_exit_error(1, "In 'ft_percentile_strnb': " BAD_ALLOC, 0);
		ft_qsort(copy, nmemb, sizeof(char *), ft_cmp);
		return (ft_find_percentile(numbers, copy, nmemb, index));
	}
	return ((char *)numbers[index]);
}
