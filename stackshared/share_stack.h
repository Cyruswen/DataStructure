#pragma once

#include <stdio.h>
#include <stddef.h>

//共享栈1 [0,top1)
//共享栈2 [top2, ShareStackMaxSize)

#define ShareStackMaxSize 1000

typedef char ShareStackType;

typedef struct ShareStack{
    ShareStackType data[ShareStackMaxSize];
    size_t top1;
    size_t top2;
} ShareStack;

void ShareStackInit(ShareStack* stack);

void ShareStackPush1(ShareStack* stack, ShareStackType value);

void ShareStackPop1(ShareStack* stack);

void ShareStackPop2(ShareStack* stack);

int ShareStackTop1(ShareStack* stack, ShareStackType* value);

int ShareStackTop2(ShareStack* stack, ShareStackType* value);
