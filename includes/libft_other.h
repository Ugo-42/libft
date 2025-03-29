/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_other.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/29 16:52:13 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_OTHER_H
# define LIBFT_OTHER_H

/*┌────────┐
  │ other/ │
  └────────┘*/

/**
 * @brief This function dereferences a NULL pointer.
 *
 * Known issue: This function can cause a segmentation fault if called.
 */
void	ft_segfault(void);

/**
 * @brief Exits the program once the function is called a specified
 *        number of times.
 *
 * @param max_calls The maximum number of allowed calls before exiting.
 */
void	ft_timeout(int max_calls);

#endif
