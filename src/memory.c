#include <stdlib.h>

#include "main.h"
#include "memory.h"

void* reallocate(void* pointer, u32 oldSize, u32 newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }
    void* result = realloc(pointer, newSize);
    if (result == NULL) {
        exit(1);
    }
    return result;
}
