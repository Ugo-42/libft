#include "libft_memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem;
	unsigned char		byte;

	if (s)
	{
		byte = c;
		mem = s;
		while (n--)
		{
			if (*mem == byte)
				return ((void *)mem);
			mem++;
		}
	}
	return (NULL);
}
