/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_other.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/08 09:40:36 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_COMPARISON_H
# define LIBFT_COMPARISON_H

/*┌─────────────┐
  │ comparison/ │
  └─────────────┘*/

#include <stdbool.h>

/**
 * @brief return the true/false value depending on `condition`.
 *
 * @param condition The maximum number of allowed calls before exiting.
 * @param true_value The value returned if condtion == true.
 * @param false_value The value returned if condition == false.
 */
void	*ft_ternary(bool condition, void *true_value, void *false_value);

/**
 * @brief return the true/false value depending on `condition`.
 *
 * @param condition The maximum number of allowed calls before exiting.
 * @param true_value The value returned if condtion == true.
 * @param false_value The value returned if condition == false.
 */
int		ft_iternary(bool condition, int true_value, int false_value);

#endif
