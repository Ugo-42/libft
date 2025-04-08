/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flexistr2d_njoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieffel <lrieffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:23:55 by lrieffel          #+#    #+#             */
/*   Updated: 2025/04/08 10:55:38 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flexistr2d_joinflexn(t_flexistr2d *arstr1, t_flexistr2d *arstr2, int n)
{
	if (arstr1 == NULL || arstr2 == NULL)
		return ;
	ft_normalize(&n, 0, arstr1->len - 1);
	while (arstr2->len > 0)
	{
		flexistr2d_fadd(arstr1, flexistr2d_npop(arstr2, 0), n);
		n++;
	}
	flexistr2d_close(arstr2);
}

void	flexistr2d_joinstrn(t_flexistr2d *arstr, char **str, int n)
{
	if (arstr == NULL || str == NULL)
		return ;
	ft_normalize(&n, 0, arstr->len - 1);
	while (*str != NULL)
	{
		flexistr2d_add(arstr, *str, n++);
		str++;
	}
}

void	flexistr2d_fjoinstrn(t_flexistr2d *arstr, char **str, int n)
{
	int	i;

	if (arstr == NULL || str == NULL)
		return ;
	ft_normalize(&n, 0, arstr->len - 1);
	i = 0;
	while (str[i])
		flexistr2d_fadd(arstr, str[i++], n++);
}
