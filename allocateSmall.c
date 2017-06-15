#include "libftMalloc.h"

void    *allocateSmall(block_meta *block,size_t size)
{
    if (!block) 
        requestSpace(block, size);
    else if (size < block->size + META_SIZE){
        splitBlock(block, size);
        return (block->data);
    }
    return NULL;
}