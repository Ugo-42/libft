/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:22:07 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/26 09:22:08 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libft_error.h"
#include "struct.h"

bool	ft_is_sorted(const t_array *arr, int (*cmp)(const void *, const void *))
{
    const char *base;
    size_t i;
	
	if (!arr || !cmp)
		ft_exit_error(1, "In 'ft_is_sorted': invalid argument address.", 0);
	base = arr->base;
    i = 0;
    while (i < arr->items_nb - 1)
    {
        if (cmp(base + i * arr->type_size, base + (i + 1) * arr->type_size) > 0)
            return (false);
        i++;
    }
    return (true);
}
