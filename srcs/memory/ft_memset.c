#include "libft_memory.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;

	if (!s)
		return (NULL);
	b = s;
	while (n--)
		*b++ = c;
	return (s);
}
