#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "main.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;
    initChunk(&chunk);

    u32 constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_RETURN, 123);
    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}
