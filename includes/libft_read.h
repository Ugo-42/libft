/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_read.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieffel <lrieffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:09:23 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/30 15:35:58 by lrieffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_READ_H
# define LIBFT_READ_H

/*┌───────┐
  │ read/ │
  └───────┘*/

/*┌─────────────────┐
  │ get_next_line.c │
  └─────────────────┘*/
# include <unistd.h>

# define BUFFER_SIZE 4096
# define MAX_FD 1024

void	gnl_reset_fd(int fd);
char	*get_next_line(int fd);

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE];
	size_t	offset;
	ssize_t	bytes_read;
}	t_buffer;

t_buffer	*get_buffer(int fd);

#endif
