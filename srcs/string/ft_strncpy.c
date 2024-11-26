void	ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	if (!dest || !src)
		return ;
	i = 0;
	while (*src && i < n)
		dest[i++] = *src++;
	while (i < n)
		dest[i++] = '\0';
}
