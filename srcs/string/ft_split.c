#include "libft_allocation.h"
#include "libft_string.h"
#include "libft_count.h"

static void	ft_free_result(char **result, int r)
{
	while (r >= 0)
		free(result[r--]);
	free(result);
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
		result[r] = malloc((word_len + 1) * sizeof(char));
		if (!result[r])
		{
			ft_free_result(result, r);
			return (0);
		}
		ft_strncpy(result[r], &str[i], word_len);
		i += word_len;
		r++;
	}
	return (1);
}

char    **ft_split(const char *str, const char c)
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
