/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:23:38 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/16 12:17:58 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include "libft_error.h"

size_t	ft_putnchar_fd(int fd, const char c, size_t n)
{
	char	*buffer;

	buffer = malloc(n);
	if (!buffer)
	{
		ft_exit_error(1, "In 'ft_putnspaces_fd': malloc failed :/", 0);
	}
	ft_memset(buffer, c, n);
	return (write(fd, buffer, n));
}
