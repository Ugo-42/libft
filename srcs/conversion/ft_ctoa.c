#include <stdlib.h>

char	*ft_ctoa(char c)
{
	char *result;

	result = malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return (result);
}
