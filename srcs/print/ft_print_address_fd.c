#include "libft_print.h"

size_t	ft_print_address_fd(int fd, uintptr_t addr)
{
	if (!addr)
		return (write(fd, "(nil)", 5));
	return (ft_putstrn_fd(fd, "0x", 2) + ft_print_hex_fd(fd, addr, false));
}
