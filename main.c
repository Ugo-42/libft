#include <stdio.h>
#include "includes/libft.h"

int main(void)
{
	t_flexistr fs;
	int ret;

	// Test 1: Normal init
	ret = fs_init(&fs, 32);
	printf("Init return: %d, fs.errno: %d\n", ret, fs.errno);

	// Test 2: Bad input (simulate by passing NULL string to append)
	ret = fs_append(&fs, NULL, false);
	printf("Append return: %d, fs.errno: %d\n", ret, fs.errno);

	// Test 3: Append char
	ret = fs_append_char(&fs, 'A');
	printf("Append char return: %d, fs.errno: %d\n", ret, fs.errno);
	printf("Current string: %s\n", fs.string);

	// Test 4: Append number
	ret = fs_append_nb(&fs, 42, NULL);
	printf("Append number return: %d, fs.errno: %d\n", ret, fs.errno);
	printf("Current string: %s\n", fs.string);

	// Cleanup
	char *result = fs_finalize(&fs);
	if (result)
	{
		printf("Finalized string: %s\n", result);
		free(result);
	}
	else
	{
		printf("Finalization failed, fs.errno: %d\n", fs.errno);
	}

	return 0;
}

