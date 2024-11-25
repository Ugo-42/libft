void    ft_segfault(void)
{
	*((int *)0) = '\xD';
}
