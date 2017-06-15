#include "libftMalloc.h"

void    *malloc(size_t size)
{
    block_meta *block;
    if (size <= 0) {
        return NULL;
    }

    if (!global_base) {
        block = requestSpace(NULL, size);
        if (!block){
            return NULL;
        }
        global_base = block;
    }
    else {
        block_meta *last = global_base;
        block = findFreeBlock(&last, size);
        if (!block) {
            block = requestSpace(last, size);
            if (!block) {
                return NULL;
            }
        }
        else {
            block->free = 0;
        }
    }

    return (block->data);
}
