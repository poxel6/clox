#pragma once
#include "main.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_POP,
    OP_GET_GLOBAL,
    OP_DEFINE_GLOBAL,
    OP_SET_GLOBAL,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DEVIDE,
    OP_NOT,
    OP_NEGATE,
    OP_PRINT,
    OP_RETURN
} OpCode;

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
