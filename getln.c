#include <stdio.h>
#include "byte.h"
#include "getln.h"

int
getln (buffer *ss, stralloc *sa, int *match, int sep)
{
    char *cont = NULL;
    unsigned int clen = 0;

    if (getln2 (ss, sa, &cont, &clen, sep) == -1)
        return -1;
    if (!clen)
    {
        *match = 0;
        return 0;
    }
    if (!stralloc_catb (sa, cont, clen))
        return -1;

    *match = 1;
    return 0;
}
