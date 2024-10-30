/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:06:49 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/10/30 11:08:12 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_count_words(const char *str, char c)
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
