#include "libft_string.h"
#include "libft_allocation.h"
#include "libft_count.h"

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
