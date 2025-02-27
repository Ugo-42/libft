/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_allocation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/02/27 11:32:10 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ALLOCATION_H
# define LIBFT_ALLOCATION_H

# include <stdlib.h>

/*┌─────────────┐
  │ allocation/ │
  └─────────────┘*/

void	**ft_malloc_2d(size_t cols, size_t rows, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_free_2d_array(void ***array, size_t n);
void	*ft_free_2d_char_array(char ***array);
void	*ft_free_null(void **pointer);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
