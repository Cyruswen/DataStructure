#pragma once
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define HASHMAXSIZE 1000

typedef int KeyType;
typedef int ValType;

typedef size_t (*HashFunc)(KeyType key);

typedef struct HashElem{
    KeyType key;
    ValType value;
    struct HashElem* next;
} HashElem;

typedef struct HashTable{
    HashElem* data[HASHMAXSIZE];
    size_t size;
    HashFunc func;
} HashTable;

void HashInit(HashTable* ht, HashFunc HashFuncDefault);
