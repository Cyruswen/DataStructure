#pragma once
#include <stdio.h>
#include <stddef.h>

#define TestType printf("\n######################### %s ############################\n",__FUNCTION__)

//我们存放的是键值对
#define HashMaxSize 1000

typedef enum{
    Empty, //空状态
    Deleted, //被删除状态
    Valid, //有效状态
} Stat;

typedef int KeyType;
typedef int ValType;

typedef size_t (*HashFunc)(KeyType key);

//这个结构体表示哈希表中的一个元素
typedef struct HashElem{
   KeyType key;
   ValType value;
   Stat stat;
} HashElem;

//[0, size)不能表示有效元素
typedef struct HashTable{
    HashElem data[HashMaxSize];
    size_t size;
    HashFunc func;
} HashTable;

void HashInit(HashTable* ht, HashFunc hash_func);

void HashDestroy(HashTable* ht);

void HashInsert(HashTable* ht, KeyType key, ValType value);

int HashFind(HashTable* ht, KeyType key, ValType* value);

void HashRemove(HashTable* ht, KeyType key);

void HashPrnit(HashTable* ht, const char* message);
