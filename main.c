#include "includes/libft.h"

int	main(void)
{

	char *res = ft_stringf("look: '%^s'\n", "HELLO", 20);

	ft_printf(res);
	free(res);
	return (0);
}
