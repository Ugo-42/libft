#include "libft_allocation.h"
#include "libft_count.h"

char	*ft_strdup(const char *s)
{
	char	*start;
	char	*copy;

	copy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	start = copy;
	while (*s)
		*copy++ = *s++;
	*copy = '\0';
	return (start);
}
