#include "libftMalloc.h"

block_meta  *getBlockPtr(void *ptr)
{
    return (block_meta*)ptr - 1;
}