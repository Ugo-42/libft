#include "libft_print.h"

size_t	ft_putnbr_fd(int fd, int n)
{
	unsigned int	nb;
	char			result[12];
	int				i;

	nb = n;
	if (n < 0)
		nb = -n;
	i = 10;
	while (nb > 0 || i == 10)
	{
		result[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		result[i--] = '-';
	result[11] = '\0';
	return (ft_putstr_fd(fd, &result[++i]));
}
