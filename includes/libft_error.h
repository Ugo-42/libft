/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/21 13:39:39 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ERROR_H
# define LIBFT_ERROR_H

# include <stdbool.h>

/*┌────────┐
  │ error/ │
  └────────┘*/

# define BAD_ARG	"invalid argument(s)."
# define BAD_ALLOC	"allocation failed."
# define BAD_BAD	"unexpected error."

void	ft_exit_error(int exit_code, char *error_msg, bool is_allocated_msg);

#endif
