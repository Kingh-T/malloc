#include "libftMalloc.h"

void *realloc(void *ptr, size_t size)
{
    block_meta *block_ptr;
    void       *new_ptr;

    if (!ptr) {
        return malloc(size);
    }

    block_ptr = getBlockPtr(ptr);
    if (block_ptr->size >= size) {
        return ptr;
    }

    new_ptr = malloc(size);
    if (!new_ptr) {
        return NULL;
    }
    ft_memcpy(new_ptr, ptr, block_ptr->size);
    free(ptr);
    return new_ptr;
}
