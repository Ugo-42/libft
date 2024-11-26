#include "libft_string.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	chr;

	if (s)
	{
		str = (unsigned char *)s;
		chr = c;
		while (*str)
		{
			if (*str == chr)
				return ((char *)str);
			str++;
		}
		if (!chr)
			return ((char *)str);
	}
	return (NULL);
}
