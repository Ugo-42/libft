/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/06 09:46:56 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_SORT_H
# define LIBFT_SORT_H

/* sorting/ */

# include "struct.h"

bool	ft_is_sorted(const t_array *ar, int (*cmp)(const void *, const void *));

void	ft_qsort(t_array *arr, int (*cmp)(const void *, const void *));

#endif
