#include "libftMalloc.h"

void    splitBlock(block_meta *block, size_t size)
{
    block_meta *new_block;

    new_block = block->data + size;
    new_block->next = block->next;
    new_block->free = 1;
    block->size = size;
    block->next = new_block;
}