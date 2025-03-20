/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_skip.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/03/20 09:42:00 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_SKIP_H
# define LIBFT_SKIP_H

/*┌───────┐
  │ skip/ │
  └───────┘*/

int		ft_skip_quoted(const char **str);

void	ft_skip_chars(const char **str, const char c);
void	ft_skip_chars_in_set(const char **str, const char *set);
void	ft_skip_not_chars(const char **str, const char c);
void	ft_skip_spaces(const char **str);
void	ft_skip_word(const char **str);

#endif
