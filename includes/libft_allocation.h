/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/21 11:23:06 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ALLOCATION_H
# define LIBFT_ALLOCATION_H

# include <stdlib.h>
# include <stdint.h>

/* ft_allocation.c */
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
