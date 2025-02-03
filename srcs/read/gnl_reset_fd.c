#include "libft.h"

void	gnl_reset_fd(int fd)
{
	t_buffer *buffer;

	buffer = get_buffer(fd);
	if (!buffer)
		return ;
	buffer[fd].offset = 0;
	buffer[fd].bytes_read = 0;
}
