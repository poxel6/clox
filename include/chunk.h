#pragma once
#include "main.h"
#include "value.h"

typedef enum { OP_RETURN, OP_CONSTANT } OpCode;

typedef struct {
    u32 count;
    u32 capacity;
    u8* code;
    u32* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, u8 byte, u32 line);
void freeChunk(Chunk* chunk);
u32 addConstant(Chunk* chunk, Value value);
