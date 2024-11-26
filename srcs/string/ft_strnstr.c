#include "libft_string.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (big && little)
	{
		if (*little == '\0')
			return ((char *)big);
		i = 0;
		while (big[i] && i < len)
		{
			j = i;
			k = 0;
			while (big[j] == little[k] && j < len)
			{
				if (little[++k] == '\0')
					return ((char *)&big[i]);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
