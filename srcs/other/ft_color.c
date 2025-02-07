/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:38:08 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/01/29 16:54:54 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	change_color(uint32_t color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	ft_printf("\033[38;2;%d;%d;%dm", r, g, b);
}

void	reset_color(void)
{
	ft_printf("\033[0m");
}

void	ft_print_colored(uint32_t color, const char *str)
{
	change_color(color);
	ft_putstr(str);
	reset_color();
}

void	ft_print_colored_nl(uint32_t color, const char *str)
{
	change_color(color);
	ft_putstr_nl(str);
	reset_color();
}
