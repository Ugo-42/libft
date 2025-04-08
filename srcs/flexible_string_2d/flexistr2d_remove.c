/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flexistr2d_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieffel <lrieffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:37:52 by lrieffel          #+#    #+#             */
/*   Updated: 2025/04/08 10:55:46 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flexistr2d_remove(t_flexistr2d *arstr, int n)
{
	size_t	i;

	if (!arstr)
		return ;
	ft_normalize(&n, 0, arstr->len - 1);
	ft_free_null(&arstr->str[n]);
	i = n;
	while (i < arstr->len - 1)
	{
		arstr->str[i] = arstr->str[i + 1];
		i++;
	}
	arstr->str[arstr->len - 1] = NULL;
	arstr->len--;
}
