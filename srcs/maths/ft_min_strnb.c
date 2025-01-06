/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_strnb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:24:37 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/06 10:57:04 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_maths.h"

char	*ft_min_strnb(char **numbers)
{
	char	*min_nb;
	size_t	nb;

	if (!numbers)
		return (NULL);
	nb = 0;
	min_nb = numbers[nb];
	while (numbers[nb])
	{
		if (ft_cmp_strnb(numbers[nb], min_nb) < 0)
			min_nb = numbers[nb];
		nb++;
	}
	return (min_nb);
}
