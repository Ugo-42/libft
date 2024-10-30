/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:01:03 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/10/24 11:16:09 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	chr;
	int				i;

	str = (unsigned char *)s;
	chr = c;
	i = ft_strlen(s);
	if (!chr)
		return ((char *)str + i);
	while (i--)
		if (str[i] == chr)
			return ((char *)str + i);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hey, hhhow are you? howru az";
	int		c = '\0';
	char	*result = NULL;

	result = ft_strrchr(str, c);
	printf("%p: \"%s\"\n", result, result);
	return (0);
}
*/
