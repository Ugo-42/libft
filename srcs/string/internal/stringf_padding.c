/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringf_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:08:19 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/17 11:06:05 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_kalloc(size_t size, int c)
{
	void	*ptr;
}

void	stringf_pad(t_flexistr *fs, size_t pad_len, size_t index)
{
	char	*pad_str;

}

void	stringf_pad_middle(t_flexistr *fs, size_t pad_len, size_t index)
{
	char	*left_pad;
	char	*right_pad;
	size_t	left_pad;
	size_t	right_pad;

	left_pad = pad_len / 2;
	right_pad = pad_len - left_pad;
}
