/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:23:38 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/17 10:54:41 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft_print.h"
#include "libft_error.h"
#include "libft_memory.h"

size_t	ft_putnchar_fd(int fd, const char c, size_t n)
{
	char	*buffer;

	buffer = malloc(n);
	if (!buffer)
	{
		ft_exit_error(1, "In 'ft_putnspaces_fd': " BAD_ALLOC, 0);
	}
	ft_memset(buffer, c, n);
	return (write(fd, buffer, n));
}
