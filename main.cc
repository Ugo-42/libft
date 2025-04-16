#include "includes/libft.h"
#include <stdio.h>

void	print(const char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{
	char *res = ft_stringf("%s\n", NULL);

	print(res);
	free(res);

	res = ft_stringf("%p\n", NULL);

	print(res);
	free(res);
	return (0);
}
