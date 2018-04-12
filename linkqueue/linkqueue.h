#pragma once
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define TestType printf("\n############################# %s ###################################\n",__FUNCTION__)
#define LinkQueueType char

typedef struct LinkQueue{
    struct LinkQueue* next;
    struct LinkQueue* tail;
    LinkQueueType data;
} LinkQueue;

void LinkQueueInit(LinkQueue** phead);

void LinkQueuePush(LinkQueue** phead, LinkQueueType value);

void LinkQueuePrint(LinkQueue* head, const char* msg);

void LinkQueuePop(LinkQueue** phead);

int LinkQueueFront(LinkQueue* head,LinkQueueType* value);

void LinkQueueDestroy(LinkQueue** phead);
