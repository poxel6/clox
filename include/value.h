#pragma once

#include "main.h"

typedef f64 Value;

typedef struct {
    u32 capacity;
    u32 count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);
