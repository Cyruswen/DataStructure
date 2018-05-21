#pragma once
#include "bitmap.h"
#define BloomHashCount 2
typedef uint64_t (*BloomHash)(const char*);

typedef struct BloomFilter{
    Bitmap bm;
    BloomHash bloom_hash[BloomHashCount];
} BloomFilter;

void BloomFilterInit(BloomFilter* bf);

void BloomFilterDestroy(BloomFilter* bf);

void BloomFilterrInsert(BloomFilter* bf, const char* str);

int BloomFilterIsExist(BloomFilter* bf, const char* str);
