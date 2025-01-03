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

// Partition function for quicksort
int partition(t_array *arr, int start, int end, int (*cmp)(const void *, const void *))
{
    char *base = (char *)arr->base;
    void *pivot = base + end * arr->type_size;
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (cmp(base + j * arr->type_size, pivot) <= 0)
        {
            i++;
            ft_swap(base + i * arr->type_size, base + j * arr->type_size, arr->type_size);
        }
    }
    ft_swap(base + (i + 1) * arr->type_size, base + end * arr->type_size, arr->type_size);
    return i + 1;
}

// Iterative quicksort function
void ft_qsort(t_array *arr, int (*cmp)(const void *, const void *))
{
    int *stack = malloc(2 * arr->items_nb * sizeof(int));
    int top = -1;
    int start, end, pivot;

    stack[++top] = 0;
    stack[++top] = arr->items_nb - 1;

    while (top >= 0)
    {
        end = stack[top--];
        start = stack[top--];

        pivot = partition(arr, start, end, cmp);

        // Push right subarray
        if (pivot + 1 < end)
        {
            stack[++top] = pivot + 1;
            stack[++top] = end;
        }

        // Push left subarray
        if (start < pivot - 1)
        {
            stack[++top] = start;
            stack[++top] = pivot - 1;
        }
    }
    free(stack);
}

// Generic ft_is_sorted function
bool ft_is_sorted(const t_array *arr, int (*cmp)(const void *, const void *))
{
    const char *base = (const char *)arr->base;
    size_t i = 0;
    while (i < arr->items_nb - 1)
    {
        if (cmp(base + i * arr->type_size, base + (i + 1) * arr->type_size) > 0)
            return false;
        i++;
    }
    return true;
}

// Comparison function for integers
int int_cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Main function to demonstrate quicksort
int main()
{
    int arr[] = {4, 3, 2, 1};  // Worst-case scenario
    size_t array_size = sizeof(arr) / sizeof(arr[0]);

    t_array array = { arr, array_size, sizeof(int) };

    // Print original array
    printf("Original array: ");
    for (size_t i = 0; i < array_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform quicksort
    ft_qsort(&array, int_cmp);

    // Print sorted array
    printf("Sorted array: ");
    for (size_t i = 0; i < array_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Check if the array is sorted
    if (ft_is_sorted(&array, int_cmp))
        printf("Array is sorted!\n");
    else
        printf("Array is not sorted!\n");

    return 0;
}
