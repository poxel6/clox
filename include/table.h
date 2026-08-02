#pragma once

#include "main.h"
#include "value.h"

typedef struct {
    ObjString* key;
    Value value;
} Entry;

typedef struct {
    u32 count;
    u32 capacity;
    Entry* entries;
} Table;

void initTable(Table* table);

void freeTable(Table* table);

bool tableGet(Table* table, ObjString* key, Value* value);

bool tableSet(Table* table, ObjString* key, Value value);

bool tableDelete(Table* table, ObjString* key);

void tableAddAll(Table* from, Table* to);

ObjString* tableFindString(Table* table, const char* chars, u32 length, u32 hash);
