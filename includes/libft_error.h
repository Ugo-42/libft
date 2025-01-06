/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/06 09:47:11 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ERROR_H
# define LIBFT_ERROR_H

# include <stdbool.h>

/* error/ */

void	ft_exit_error(int exit_code, char *error_msg, bool is_allocated_msg);

#endif
