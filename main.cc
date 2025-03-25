#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/libft.h"

char *get_env_var(const char *varname)
{
    char *env = getenv(varname);
    return env ? ft_strdup(env) : ft_strdup("UNKNOWN");
}

char	*replace_env_vars(const char *input)
{
	char	*result;
	char	*new_result;
	char	*varname;
	char	*replacement;
	size_t	i;
	size_t	len;
	size_t	start;

	if (!input)
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (input[i])
	{
		new_result = NULL;
		start = i;
		while (input[i] && input[i] != '$')
			i++;
		if (i > start)
		{
			varname = ft_strndup(input + start, i - start);
			new_result = ft_strjoin(result, varname);
			free(varname);
			free(result);
			result = new_result;
		}
		if (input[i] == '$')
		{
			i++;
			if (ft_is_alpha(input[i]) || input[i] == '_')
			{
				len = ft_strspn(input + i, "abcdefghijklmnopqrstuvwxyz"
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_");
				varname = ft_strndup(input + i, len);
				replacement = get_env_var(varname);
				free(varname);
				if (replacement)
				{
					new_result = ft_strjoin(result, replacement);
					free(replacement);
				}
				else
					new_result = ft_strjoin(result, "$");
				free(result);
				result = new_result;
				i += len;
			}
			else
			{
				new_result = ft_strjoin(result, "$");
				free(result);
				result = new_result;
			}
		}
	}
	return (result);
}

int	main(void)
{
	char	*input;
	char	*output;

	input = "Hello $USER$USER, welcome to $SHELL! Enjoy your $DAY.";
	output = replace_env_vars(input);
	if (output)
	{
		printf("Original: %s\n", input);
		printf("Modified: %s\n", output);
		free(output);
	}
	else
		printf("Memory allocation failed\n");
	return (0);
}

