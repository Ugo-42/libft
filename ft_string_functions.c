/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:52:21 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/21 10:01:34 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)s;
	chr = c;
	while (*str)
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	if (!chr)
		return ((char *)str);
	return (NULL);
}

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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
