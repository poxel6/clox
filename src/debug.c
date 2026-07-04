
#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "main.h"
#include "value.h"

void disassembleChunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    for (i32 offset = 0; offset < chunk->count;) {
        offset = disassembleInstruction(chunk, offset);
    }
}

static i32 simpleInstruction(const char* name, i32 offset) {
    printf("%s\n", name);
    return offset + 1;
}

static i32 constantInstruciton(const char* name, Chunk* chunk, i32 offset) {
    u8 constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

i32 disassembleInstruction(Chunk* chunk, i32 offset) {
    printf("%04d ", offset);
    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
        printf("	| ");
    } else {
        printf("%4d ", chunk->lines[offset]);
    }
    u8 instruction = chunk->code[offset];
    switch (instruction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        case OP_CONSTANT:
            return constantInstruciton("OP_CONSTANT", chunk, offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}
