int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	if (!str)
		return (0);
	while ((*str >= 0x9 && *str <= 0x0D) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	result *= sign;
	return (result);
}
