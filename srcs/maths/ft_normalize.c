/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:08:34 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/04 11:13:55 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_normalize(int *nb, int min, int max)
{
	if (!nb)
		return ;
	if (*nb < min)
	{
		*nb = min;
	}
	else if (*nb > max)
	{
		*nb = max;
	}
}
