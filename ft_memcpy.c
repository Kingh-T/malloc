#include "libftMalloc.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
    char	*cdst;
    char	*csrc;
    size_t	i;

    i = 0;
    cdst = (char*)dst;
    csrc = (char*)src;
    while (i < n)
    {
        cdst[i] = csrc[i];
        i++;
    }
    return (dst);
}