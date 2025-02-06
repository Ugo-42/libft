/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_is.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/21 13:40:35 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IS_H
# define LIBFT_IS_H

/*┌───────┐
  │  is/  │
  └───────┘*/

bool	ft_is_emoji(const char *wide_c);

int	ft_is_alnum(int c);
int	ft_is_alpha(int c);
int	ft_is_ascii(int c);
int	ft_is_digit(int c);
int	ft_is_print(int c);
int	ft_is_quote(int c);
int	ft_is_space(int c);

#endif
