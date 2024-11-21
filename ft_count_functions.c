/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:30:20 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/21 10:30:50 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (*str != c)
		{
			words++;
			while (*str && *str != c)
				str++;
		}
		if (*str)
			str++;
	}
	return (words);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
