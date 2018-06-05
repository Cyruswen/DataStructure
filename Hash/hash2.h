#pragma once
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define HASHMAXSIZE 1000

#define TestType printf("\n############################## %s ###############################\n", __FUNCTION__)

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

void HashDestroy(HashTable* ht);

HashElem* HashBucketFind(HashElem* Elem, KeyType to_find);

void HashInsert(HashTable* ht, KeyType key, ValType value);

int HashFind(HashTable* ht, KeyType key, ValType* value);

int HashSize(HashTable* ht);

void HashPrint(HashTable* ht,const char* msg);

void HashRemove(HashTable* ht, KeyType key);

size_t HashFuncDefault(KeyType key);
