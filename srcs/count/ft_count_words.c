/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:22:00 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/26 09:22:03 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(const char *str, char c)
{
	int	words;

	if (!str)
		return (0);
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
