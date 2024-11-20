/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocation_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:33:23 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/20 15:36:29 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*b;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	b = malloc(nmemb * size);
	if (!b)
		return (NULL);
	ft_bzero(b, nmemb * size);
	return (b);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*result;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	result = malloc(new_size);
	if (!result)
		return (NULL);
	if (old_size < new_size)
		new_size = old_size;
	ft_memcpy(result, ptr, new_size);
	free(ptr);
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*start;
	char	*copy;

	copy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	start = copy;
	while (*s)
		*copy++ = *s++;
	*copy = '\0';
	return (start);
}
