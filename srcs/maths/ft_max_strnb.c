/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_strnb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:24:37 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/06 10:56:53 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_maths.h"

char	*ft_max_strnb(char **numbers)
{
	char	*max_nb;
	size_t	nb;

	if (!numbers)
		return (NULL);
	nb = 0;
	max_nb = numbers[nb];
	while (numbers[nb])
	{
		if (ft_cmp_strnb(numbers[nb], max_nb) > 0)
			max_nb = numbers[nb];
		nb++;
	}
	return (max_nb);
}
