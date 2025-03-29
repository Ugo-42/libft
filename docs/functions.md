# libft Functions

This document provides an overview of all the functions available in the `libft` library, organized by category.

---

## Allocation (`libft_allocation.h`)

- **`ft_calloc`**: Allocates memory for an array of elements and initializes it to zero.
- **`ft_calloc_2d`**: Allocates memory for a 2D array and initializes it to zero.
- **`ft_free_2d_char_array`**: Frees a 2D array of characters and sets the pointer to `NULL`.
- **`ft_free_null`**: Frees a pointer and sets it to `NULL`.

---

## Cleanup (`libft_cleanup.h`)

- **`ft_cexit`**: Exits the program after performing a cleanup operation.

---

## Color (`libft_color.h`)

- **`ft_loop_color_value`**: Cycles through a set of predefined colors and returns the next color value.
- **`ft_change_color`**: Changes the terminal text color to the specified color.

---

## Conversion (`libft_conversion.h`)

- **`ft_atoi`**: Converts a string to an integer.
- **`ft_tolower`**: Converts an uppercase character to lowercase.
- **`ft_toupper`**: Converts a lowercase character to uppercase.
- **`ft_itoa`**: Converts an integer to a string.

---

## Count (`libft_count.h`)

- **`ft_count_words`**: Counts the number of words in a string separated by a given delimiter.
- **`ft_strlen`**: Calculates the length of a string.
- **`ft_utf8_strlen`**: Calculates the length of a UTF-8 encoded string.

---

## Error (`libft_error.h`)

- **`ft_fwarning`**: Prints a formatted warning message to the standard error stream.
- **`ft_exit_error`**: Exits the program with an error message.

---

## Is (`libft_is.h`)

- **`ft_is_cjk`**: Checks if a character is a CJK (Chinese, Japanese, Korean) character.
- **`ft_is_emoji`**: Checks if a character is an emoji.

---

## List (`libft_list.h`)

- **`ft_lstsize`**: Counts the number of nodes in a linked list.
- **`ft_lstadd_back`**: Adds a new node to the end of a linked list.

---

## Maths (`libft_maths.h`)

- **`ft_next_power_of_2`**: Calculates the next power of 2 greater than the given number.

---

## Memory (`libft_memory.h`)

- **`ft_memcmp`**: Compares two memory blocks.
- **`ft_memcpy`**: Copies memory from one location to another.

---

## Print (`libft_print.h`)

- **`ft_printf`**: Prints a formatted string to standard output.
- **`ft_putchar_fd`**: Writes a character to a file descriptor.

---

## Skip (`libft_skip.h`)

- **`ft_skip_quoted`**: Skips over a quoted section in a string.
- **`ft_skip_spaces`**: Skips over whitespace characters in a string.

---

## String (`libft_string.h`)

- **`ft_strcpy`**: Copies a string from source to destination.
- **`ft_strjoin`**: Joins two strings into a single string.
- **`ft_utf8_visual_strncpy`**: Copies a UTF-8 string into a destination buffer, respecting visual width.

---

## Sorting (`libft_sort.h`)

- **`ft_is_sorted`**: Checks if an array is sorted.
- **`ft_qsort`**: Sorts an array using the quicksort algorithm.

---

## Other (`libft_other.h`)

- **`ft_segfault`**: Triggers a segmentation fault for debugging purposes.
- **`ft_timeout`**: Simulates a timeout by limiting the number of calls to a function.
