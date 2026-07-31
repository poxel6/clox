#pragma once

#include "main.h"

typedef enum {
    VAL_BOOL,
    VAL_NUMBER,
    VAL_NIL
} ValueType;

typedef struct {
    ValueType type;
    union {
        bool boolean;
        f64 number;
    } as;
} Value;

// clang-format off
#define IS_BOOL(value)    ((value).type == VAL_BOOL)
#define IS_NIL(value)     ((value).type == VAL_NIL)
#define IS_NUMBER(value)  ((value).type == VAL_NUMBER)

#define AS_BOOL(value)    ((value).as.boolean)
#define AS_NUMBER(value)  ((value).as.number)

#define BOOL_VAL(value)   ((Value){VAL_BOOL,   {.boolean = value}})
#define NIL_VAL           ((Value){VAL_NIL,    {.number = 0}})
#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})
// clang-format on

typedef struct {
    u32 capacity;
    u32 count;
    Value* values;
} ValueArray;

bool valuesEqual(Value a, Value b);
void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);
