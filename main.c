#include <stdio.h>
#include "includes/libft.h"

//tmp get_env_var
char	*get_env_var(char *varname)
{
	char *r = getenv(varname);
	return (r ? r : NULL);
}

char	*get_var_value(char *varname)
{
	char	*value;

	if (!varname)
		return (NULL);
	value = get_env_var(varname);
	if (!value || !*value)
		return (NULL);
	return (ft_strdup(value));
}

char	*expand_env_vars(char *input)
{
	char	*result;
	char	*varname;
	char	*value;
	size_t	var_len;
	size_t	len;
	int		i;

	result = NULL;
	i = 0;
	while (input[i])
	{
		len = ft_strcspn(input + i, "$");
		result = ft_fstrjoin(result, ft_strndup(input + i, len));
		if (!result)
			return (NULL);
		i = i + len + 1;
		var_len = i;
		while (input[i] && (ft_is_alnum(input[i]) || input[i] == '_'))
			i++;
		var_len = i - var_len;
		if (var_len == 0)
			value = ft_strdup("$");
		else
		{
			varname = ft_strndup(input + i - var_len, var_len);
			value = get_var_value(varname);
			free(varname);
			if (!value)
				return (NULL);
		}
		result = ft_fstrjoin(result, value);
	}
	return (result);
}

int main(void)
{
    char *input = "Hello $USER$USER, welcome to $SHELL! Enjoy your $DAY.";
    char *output = expand_env_vars(input);

    if (output)
    {
        printf("Original: %s\n", input);
        printf("Modified: %s\n", output);
        free(output);
    }
    else
    {
        printf("Memory allocation failed\n");
    }
    return (0);
}

