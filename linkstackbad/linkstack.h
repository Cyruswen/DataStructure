pragma once
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define TestType printf("\n############################# %s #############################\n",__FUNCTION__);

typedef char LinkStackType;

typedef struct LinkStack{
    struct LinkStack* next;
    struct LinkStack* tail;
    LinkStackType data;
} LinkStack;

void LinkStackInit(LinkStack** phead);

void LinkStackPrint(LinkStack* head, const char* msg);

void LinkStackPush(LinkStack** phead,LinkStackType value);

void LinkStackPop(LinkStack** phead);

int LinkStackGetFront(LinkStack* head,LinkStackType* value);

void LinkStackDestroy(LinkStack** phead);
