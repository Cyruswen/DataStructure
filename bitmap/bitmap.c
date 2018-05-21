#include "bitmap.h"
#include <stdlib.h>
#include <string.h>

uint64_t GetSize(uint64_t capacity){
    uint64_t size = capacity / (sizeof(uint64_t)*8) + 1;
    return size;
}

void BitmapInit(Bitmap* bm, uint64_t capacity){
    if(bm == NULL){
        return;
    }
    //N/(sizeof(uint64_t)*8)+1
    bm->capacity = capacity;
    uint64_t size = capacity / (sizeof(bm->data[0])*8) + 1;
    bm->data = (uint64_t*)malloc(sizeof(uint64_t)*size);
    memset(bm->data, 0, sizeof(uint64_t)*size);
    return;
}

void BitmapDestroy(Bitmap* bm){
    if(bm == NULL){
        return;
    }
    bm->capacity = 0;
    free(bm->data);
    return;
}

void  GetOffset(uint64_t index, uint64_t* n, uint64_t* offset){
    *n = index / (sizeof(uint64_t)*8);
    *offset = index % (sizeof(uint64_t)*8);
    return;
}

//测试某一位是否为1
int BitmapTest(Bitmap* bm, uint64_t index){
    if(bm == NULL || index >= bm->capacity){
        return 0;
    }
    uint64_t n, offset;
    GetOffset(index, &n, &offset);
    uint64_t ret = bm->data[n] & (0x1ul << offset);
    return ret > 0 ? 1 : 0;
}

//给某一位设置为1
void BitmapSet(Bitmap* bm, uint64_t index){
    if( bm == NULL || index >= bm->capacity ){
        return;
    }
    uint64_t n, offset;
    GetOffset(index, &n, &offset);
    bm->data[n] |= (0x1ul << offset);
    return;
}

//给某一位赋值为0
void BitmapUnset(Bitmap* bm, uint64_t index){
    if( bm == NULL || index >= bm->capacity ){
        return;
    }
    uint64_t n, offset;
    GetOffset(index, &n, &offset);
    bm->data[n] &= ~(0x1ul << offset);
    return;
}

//全1
void BitmapFill(Bitmap* bm){
    if(bm == NULL){
        return;
    }
    uint64_t size = GetSize(bm->capacity);
    memset(bm->data,0xff ,sizeof(uint64_t)*size);
    return;
}

void BitmapClear(Bitmap* bm){
    if(bm == NULL){
        return;
    }
    uint64_t size = GetSize(bm->capacity);
    memset(bm->data,0x0 ,sizeof(uint64_t)*size);
    return;
}
