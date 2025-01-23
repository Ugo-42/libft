/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:08:04 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/23 09:56:15 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
'*  Algorithm:
'*  {
'*      1. Define a static buffer structure to keep data of each FDs
'*      2. To retrieve the next line:
'*      {
'*          a. Allocate memory for the line with an initial size.
'*          b. While (reading characters):
'*          {
'*              I.   If the line len will pass the allocated size, realloc with
'*                   the size doubled.
'*              II.  Read from the file descriptor into the static buffer if
'*                   it is empty or exhausted. Then copy from the buffer.
'*              III. Break if read failed, or EOF or ('\n') is encountered.
'*          }
'*      }
'*      3. Finalize the line:
'*      {
'*          b. If the line is empty and no characters were read, free memory
'*             and return NULL.
'*          c. Otherwise, add a null terminator and return the constructed line.
'*      }
'*  }
*/

#include "libft.h"

static int	read_and_copy(int fd, t_buffer *buf, char **line, size_t *line_len)
{
	if (buf->offset >= (size_t)buf->bytes_read)
	{
		buf->bytes_read = read(fd, buf->buffer, BUFFER_SIZE);
		buf->offset = 0;
		if (buf->bytes_read <= 0)
			return (buf->bytes_read);
	}
	(*line)[(*line_len)++] = buf->buffer[buf->offset++];
	return (1);
}

static char	*finalize_line(char *line, size_t line_len)
{
	if (line_len == 0)
	{
		free(line);
		return (NULL);
	}
	line[line_len] = '\0';
	return (line);
}

static char	*read_line(int fd, t_buffer *s_buffer)
{
	char	*line;
	size_t	alloc_size;
	size_t	line_len;

	alloc_size = 64;
	line = malloc(alloc_size);
	if (!line)
		return (NULL);
	line_len = 0;
	while (1)
	{
		if (line_len + 1 >= alloc_size)
		{
			line = ft_realloc(line, alloc_size, alloc_size * 2);
			if (!line)
				return (NULL);
			alloc_size *= 2;
		}
		if (read_and_copy(fd, s_buffer, &line, &line_len) <= 0)
			break ;
		if (line[line_len - 1] == '\n')
			break ;
	}
	return (finalize_line(line, line_len));
}

char	*get_next_line(int fd)
{
	static t_buffer	s_buffer[MAX_FD];

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	return (read_line(fd, &s_buffer[fd]));
}
