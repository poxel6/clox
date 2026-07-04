#pragma once

#include "chunk.h"
#include "main.h"

void disassembleChunk(Chunk* chunk, const char* name);
i32 disassembleInstruction(Chunk* chunk, i32 offset);
