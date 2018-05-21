#pragma once
#include <stdint.h>

typedef struct Bitmap{
    uint64_t* data;
    uint64_t capacity;
} Bitmap;

int BitmapTest(Bitmap* bm, uint64_t index);

void BitmapInit(Bitmap* bm, uint64_t capacity);

void BitmapDestroy(Bitmap* bm);

void BitmapSet(Bitmap* bm, uint64_t index);

void BitmapUnset(Bitmap* bm, uint64_t index);

void BitmapFill(Bitmap* bm);

void BitmapClear(Bitmap* bm);
