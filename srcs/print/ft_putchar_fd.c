#include "libft_print.h"

size_t	ft_putchar_fd(int fd, const char c)
{
	return (write(fd, &c, 1));
}
