/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:37:20 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/20 15:46:19 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Join
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcpy(result + ft_strlen(s1), s2);
	return (result);
}

// Split
static char	**ft_malloc_word(char **result, int r, const char *w, int word_len)
{
	result[r] = malloc((word_len + 1) * sizeof(char));
	if (!result[r])
	{
		while (r >= 0)
			free(result[r--]);
		free(result);
		return (NULL);
	}
	ft_strncpy(result[r], w, word_len);
	return (result);
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		word_len;
	int		i;
	int		r;

	if (!str)
		return (NULL);
	result = ft_calloc((ft_count_words(str, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	r = -1;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		word_len = 0;
		while (str[i + word_len] && str[i + word_len] != c)
			word_len++;
		if (word_len > 0)
			if (!ft_malloc_word(result, ++r, &str[i], word_len))
				return (NULL);
		i += word_len;
	}
	return (result);
}
