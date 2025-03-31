/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_flexistr.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:48:40 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/03/31 16:39:52 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FLEXISTR_H
# define LIBFT_FLEXISTR_H

# include <stddef.h>
# include <stdbool.h>

/**
 * @struct s_flexible_string
 * @brief Represents a flexible string.
 *
 * @param string Pointer to the dynamically allocated string.
 * @param len The current length of the string (excluding the null terminator).
 * @param size The total allocated size of the string (including space for the
 *             null terminator).
 */
typedef struct s_flexible_string
{
	char	*string;
	size_t	len;
	size_t	size;
}	t_flexible_string;

/**
 * @brief Finalizes a flexible string and returns the resulting string.
 *
 * This function detaches the string from the flexible string structure,
 * allowing the caller to manage the memory manually. The flexible string
 * structure is reset and freed even on error.
 *
 * @param fs A pointer to the flexible string structure.
 * @return A pointer to the finalized string (malloc-ated) or NULL.
 */
char	*flexistr_finalize(t_flexible_string *fs);

/**
 * @brief Appends a string to a flexible string.
 *
 * This function appends the given string to the flexible string. If the
 * `free_input` parameter is set to `true`, the input string is freed after
 * being appended.
 *
 * @param fs A pointer to the flexible string structure.
 * @param s The string to append.
 * @param free_input Whether to free the input string after appending.
 * @return `0` on success, `1` if bad input, or `-1` if memory allocation fails.
 */
int		flexistr_append(t_flexible_string *fs, char *s, bool free_input);

/**
 * @brief Initializes a flexible string with a specified initial size.
 *
 * This function allocates memory for a flexible string and sets its initial
 * size. The string is initialized as an empty string.
 *
 * @param fs A pointer to the flexible string structure.
 * @param initial_size The initial size of the flexible string.
 * @return `0` on success, `1` if bad input, or `-1` if memory allocation fails.
 */
int		flexistr_init(t_flexible_string *fs, size_t initial_size);

/**
 * @brief Resizes a flexible string to a new size.
 *
 * This function reallocates memory for the flexible string to match the
 * specified new size. If the new size is smaller than the current length,
 * the string is truncated.
 *
 * @param fs A pointer to the flexible string structure.
 * @param new_size The new size of the flexible string.
 * @return `0` on success, `1` if bad input, or `-1` if memory allocation fails.
 */
int		flexistr_resize(t_flexible_string *fs, size_t new_size);

/**
 * @brief Frees the memory allocated for a flexible string.
 *
 * This function frees the memory used by the flexible string and resets
 * the structure to its initial state, [NULL, 0, 0].
 *
 * @param fs A pointer to the flexible string structure.
 */
void	flexistr_free(t_flexible_string *fs);

#endif
