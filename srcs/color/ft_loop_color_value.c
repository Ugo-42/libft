/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:38:08 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/03/14 15:08:19 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_loop_color_value(void)
{
	static uint8_t	r = 255;
	static uint8_t	g = 0;
	static uint8_t	b = 0;
	static int32_t	step = 1;

	if (step == 1)
		g += 15;
	if (step == 2)
		r -= 15;
	if (step == 3)
		b += 15;
	if (step == 4)
		g -= 15;
	if (step == 5)
		r += 15;
	if (step == 6)
		b -= 15;
	if ((step == 1 && g >= 255) || (step == 2 && r <= 0)
		|| (step == 3 && b >= 255) || (step == 4 && g <= 0)
		|| (step == 5 && r >= 255) || (step == 6 && b <= 0))
		step = (step % 6) + 1;
	return ((r << 16) | (g << 8) | b);
}
