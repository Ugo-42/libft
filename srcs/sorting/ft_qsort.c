/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:22:07 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/26 09:22:08 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
'*  Algorithm:
'*  {
'*      1. We allocate a stack to store the start and end indices of subarrays.
'*      2. The stack is initialized with the entire array as indices.
'*      3. While (the stack is not empty)
'*      {
'*          a. Pop the current subarray boundaries
'*          b. Partition the subarray around a pivot element,
'*             rearranging elements such that:
'*               - All elements <= to the pivot are on the left.
'*               - All elements > than the pivot are on the right.
'*          c. If the right subarray (pivot + 1 to end) > than one element
'*                 push its boundaries onto the stack.
'*          d. If the left subarray (start to pivot - 1) > than one element
'*                 push its boundaries onto the stack.
'*      }
'*      4. when the stack is empty, all subarrays have been sorted.
'*  }
*/

#include <stdlib.h>

#include "libft_allocation.h"
#include "libft_memory.h"
#include "libft_error.h"
#include "struct.h"

static int	partition(t_array *arr, int left, int right,
		int (*cmp)(const void *, const void *))
{
	void	*pivot;
	char	*base;
	int		i;
	int		j;

	base = arr->base;
	pivot = base + right * arr->type_size;
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (cmp(base + j * arr->type_size, pivot) <= 0)
		{
			i++;
			ft_swap_content(base + i * arr->type_size,
					base + j * arr->type_size, arr->type_size);
		}
		j++;
	}
	ft_swap_content(base + (i + 1) * arr->type_size,
			base + right * arr->type_size, arr->type_size);
	return (i + 1);
}

static void	ft_push_stack(t_stack *stack, int start, int end)
{
	size_t total_size;

	if (stack->top + 2 >= (int)stack->size)
	{
		total_size = stack->size * stack->type_size;
		stack->base = ft_realloc(stack->base, total_size, total_size * 2);
		if (!stack->base)
		{
			ft_exit_error(1, "In 'ft_qsort': realloc failed.", 0);
		}
		stack->size *= 2;
	}
	((int *)stack->base)[++stack->top] = start;
	((int *)stack->base)[++stack->top] = end;
}

static void	ft_pop_stack(t_stack *stack, int *start, int *end)
{
	*end = ((int *)stack->base)[stack->top--];
	*start = ((int *)stack->base)[stack->top--];
}

void	ft_qsort(t_array *arr, int (*cmp)(const void *, const void *))
{
	t_stack	stack;
	int		start;
	int		end;
	int		pivot;

	stack.size = 64;
	stack.type_size = sizeof(int);
	stack.base = malloc(stack.size * stack.type_size);
	if (!stack.base)
		ft_exit_error(1, "In 'ft_qsort': malloc failed.", 0);
	stack.top = -1;
	ft_push_stack(&stack, 0, arr->items_nb - 1);
	while (stack.top >= 0)
	{
		ft_pop_stack(&stack, &start, &end);
		pivot = partition(arr, start, end, cmp);
		if (pivot + 1 < end)
			ft_push_stack(&stack, pivot + 1, end);
		if (start < pivot - 1)
			ft_push_stack(&stack, start, pivot - 1);
	}
	free(stack.base);
}
