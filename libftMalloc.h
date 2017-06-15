#ifndef MALLOC_LIBFTMALLOC_H
#define MALLOC_LIBFTMALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

typedef struct  block_meta {
    size_t              size;
    struct block_meta   *next;
    int                 free;
    char                data[1];
}               block_meta;

#define META_SIZE 12
#define TINY_BIG_BLOCK 10000
#define TINY_MAX 100
#define SMALL_BIG_BLOCK 372500
#define SMALL_MAX 3725
#define LARGE_MAX 48847
void *global_base = NULL;

void        *malloc(size_t size);
void        free(void *ptr);
void        *realloc(void *ptr, size_t size);
void        *allocateSmall(block_meta *block,size_t size);
void        *ft_memcpy(void *dst, const void *src, size_t n);
void        splitBlock(block_meta *block, size_t size);
block_meta  *findFreeBlock(block_meta **last, size_t size);
block_meta  *requestSpace(block_meta *last, size_t size);
block_meta  *getBlockPtr(void *ptr);

#endif
