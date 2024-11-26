#include "libft_print.h"

size_t	ft_putstrn_fd(int fd, const char *s, size_t n)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, n));
}
