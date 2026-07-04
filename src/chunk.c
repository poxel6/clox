#include "chunk.h"
#include "memory.h"
#include "value.h"

void initChunk(Chunk* chunk) {
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

void writeChunk(Chunk* chunk, u8 byte, u32 line) {
    if (chunk->capacity < chunk->count + 1) {
        u32 oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(u8, chunk->code, oldCapacity, chunk->capacity);
        chunk->lines =
            GROW_ARRAY(u32, chunk->lines, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
}

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(u8, chunk->code, chunk->capacity);
    FREE_ARRAY(u32, chunk->lines, chunk->capacity);
    initChunk(chunk);
}

u32 addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}
