#include "libftMalloc.h"

block_meta   *findFreeBlock(block_meta **last, size_t size)
{
    block_meta *current = global_base;

    while (current && !(current->free && current->size >= size))
    {
        *last = current;
        current = current->next;
    }
    return current;
}