/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:01:03 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/10/15 17:51:08 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = i;
		k = 0;
		while (big[j] == little[k] && j < len)
		{
			if (little[++k] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hey, hhhow are you? howru az";
	char	to_find[] = "how";
	char	*result;
	int		n = 9;
	int		i = 0;

	result = ft_strnstr(str, to_find, n);
	if (!result)
	{
		printf("\"%s\" not found in \"", to_find);
		while (i < n)
			printf("%c", str[i++]);
		printf("\"");
		return (0);
	}
	printf("\"%s\" found in \"", to_find);
	while (i < n)
		printf("%c", str[i++]);
	printf("\"");
	return (0);
}
*/
