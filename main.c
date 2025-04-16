#include "includes/libft.h"

int	main(void)
{

	char *res = ft_stringf("basic %d%s look: '%>d'\n", 42, "yes", 5, 666);

	ft_printf(res);
	free(res);
	return (0);
}
