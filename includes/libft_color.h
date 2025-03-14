/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:18 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/02/26 14:41:53 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_COLOR_H
# define LIBFT_COLOR_H

/*┌────────┐
  │ color/ │
  └────────┘*/

# include <stdint.h>

uint32_t	ft_loop_color_value(void);

void		ft_change_color(uint32_t color);
void		ft_loop_color(void);
void		ft_print_rainbow(const char *str);
void		ft_print_colored(const char *str, uint32_t color);
void		ft_print_nl_colored(const char *str, uint32_t color);
void		ft_reset_color(void);

#endif
