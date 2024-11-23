/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:33:38 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/21 11:27:55 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_segfault(void)
{
	int	*error;

	error = (int *)42;
	*error = -42;
}

void	ft_bzero(void *s, size_t n)
{
	if (s)
		ft_memset(s, 0, n);
}
