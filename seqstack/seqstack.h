#pragma once
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>

#define TestType printf("\n##################################### %s #######################################\n",__FUNCTION__)

typedef char SeqStackType;

typedef struct SeqStack{
    SeqStackType* data;
    size_t size;
    size_t capacity;  //MAX_SIZE的替代品，data这段元素中能容纳的元素个数
} SeqStack;

void SeqStackInit(SeqStack* stack);

void SeqStackPrint(SeqStack* stack, const char* msg);

void SeqStackReSize(SeqStack* stack);

void SeqStackPush(SeqStack* stack, SeqStackType value);

void SeqStackPop(SeqStack* stack);

void SeqStackDestroy(SeqStack* stack);

int SeqStackGetFront(SeqStack* stack,SeqStackType* value);
