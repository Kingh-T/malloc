#include "libftMalloc.h"

block_meta *requestSpace(block_meta *last, size_t size)
{
    int         fd;
    int         flags;
    off_t       offset;
    int         protections;
    void        *request;
    block_meta  *block;

    fd = -1;
    offset = 0;
    flags = MAP_SHARED | MAP_ANONYMOUS;
    protections = PROT_READ | PROT_WRITE;
    block = mmap(0, size, protections, flags, fd, offset);
    request = mmap(0, size + META_SIZE, protections, flags, fd, offset);
    if (request == MAP_FAILED) {
        return NULL;
    }

    if (last) {
        last->next = block;
    }
    block->size = size;
    block->next = NULL;
    block->free = 0;
    return block;
}