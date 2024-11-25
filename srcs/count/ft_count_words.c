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
