void    *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void    *result;
 
    if (!ptr)
        return (malloc(new_size));
    if (!new_size)
        return (free(ptr), NULL);
    result = malloc(new_size);
    if (!result)
        return (NULL);
    if (old_size < new_size)
        new_size = old_size;
    ft_memcpy(result, ptr, new_size);
    free(ptr);
    return (result);
}
