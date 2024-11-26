#include "libft_print.h"

size_t	ft_putunbr_fd(int fd, unsigned int n)
{
	char	result[11];
	int		i;

	i = 9;
	while (n > 0 || i == 9)
	{
		result[i--] = (n % 10) + '0';
		n /= 10;
	}
	result[10] = '\0';
	return (ft_putstr_fd(fd, &result[++i]));
}
