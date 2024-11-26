#include "libft_string.h"
#include "libft_count.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	chr;
	int				i;

	if (s)
	{
		str = (unsigned char *)s;
		chr = c;
		i = ft_strlen(s);
		if (!chr)
			return ((char *)str + i);
		while (i--)
			if (str[i] == chr)
				return ((char *)str + i);
	}
	return (NULL);
}
