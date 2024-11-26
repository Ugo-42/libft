void	ft_strcpy(char *dest, const char *src)
{
	if (!dest || !src)
		return ;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}
