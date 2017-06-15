#include "libftMalloc.h"

void free(void * ptr)
{
    block_meta *block_ptr;

    if (!ptr) {
        return;
    }

    block_ptr = getBlockPtr(ptr);
    if (block_ptr->free == 0)
        block_ptr->free = 1;

}