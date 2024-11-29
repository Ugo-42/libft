/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:59:16 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/29 12:45:21 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_allocation.h"
#include "libft_string.h"
#include "libft_count.h"

static int	ft_malloc_word(char **result, size_t r, size_t word_len)
{
	result[r] = malloc((word_len + 1) * sizeof(char));
	if (!result[r])
	{
		while (r > 0)
			free(result[r--]);
		free(result[r]);
		free(result);
		return (0);
	}
	return (1);
}

static int	ft_split_words(char **result, const char *str, const char c)
{
	size_t	word_len;
	size_t	r;
	size_t	i;

	r = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		word_len = 0;
		while (str[i + word_len] && str[i + word_len] != c)
			word_len++;
		if (word_len > 0)
		{
			if (!ft_malloc_word(result, r, word_len))
				return (0);
			ft_strncpy(result[r], &str[i], word_len);
			r++;
		}
		i += word_len;
	}
	return (1);
}

char	**ft_split(const char *str, const char c)
{
	char	**result;
	int		words;

	if (!str)
		return (NULL);
	words = ft_count_words(str, c);
	if (!words)
		return (NULL);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!ft_split_words(result, str, c))
		return (NULL);
	result[words] = NULL;
	return (result);
}
