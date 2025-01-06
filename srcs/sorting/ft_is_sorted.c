/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:22:07 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/06 15:02:46 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft_error.h"

bool	ft_is_sorted(const void *base, size_t nmemb, size_t size,
			int (*cmp)(const void *, const void *))
{
	const unsigned char	*arr;
	size_t				i;

	if (!base || !cmp)
		ft_exit_error(1, "In 'ft_is_sorted': invalid argument address.", 0);
	arr = base;
	i = 0;
	while (i < nmemb - 1)
	{
		if (cmp(&arr[i * size], &arr[(i + 1) * size]) > 0)
			return (false);
		i++;
	}
	return (true);
}
