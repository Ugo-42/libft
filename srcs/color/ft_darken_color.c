/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darken_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:36:04 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/03 11:00:51 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_darken_color(uint32_t hex_color, int percentage)
{
	const float	factor = (100 - percentage) / 100.0f;
	t_rgb		rgb;

	rgb.r = ((hex_color >> 16) & 0xFF) * factor;
	rgb.g = ((hex_color >> 8) & 0xFF) * factor;
	rgb.b = (hex_color & 0xFF) * factor;
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}
