/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_copy_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:42:14 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/20 15:45:13 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dest, const char *src)
{
	if (!dest || !src)
		return ;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

void	ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	if (!dest || !src)
		return ;
	i = 0;
	while (*src && i < n)
		dest[i++] = *src++;
	while (i < n)
		dest[i++] = '\0';
}
