/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:54:00 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/12/12 11:54:02 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_count.h"

int	ft_strnbcmp(const char *nb1, const char *nb2)
{
	size_t	len_nb1;
	size_t	len_nb2;

	len_nb1 = ft_strlen(nb1);
	len_nb2 = ft_strlen(nb2);
	if (nb1[0] == '-' && nb2[0] != '-')
		return (-1);
	if (nb1[0] != '-' && nb2[0] == '-')
		return (1);
	if (nb1[0] == '-' && nb2[0] == '-')
	{
		if (len_nb1 > len_nb2)
			return (-1);
		if (len_nb1 < len_nb2)
			return (1);
		return (ft_strcmp(nb2 + 1, nb1 + 1));
	}
	else
	{
		if (len_nb1 > len_nb2)
			return (1);
		if (len_nb1 < len_nb2)
			return (-1);
		return (ft_strcmp(nb1, nb2));
	}
}
