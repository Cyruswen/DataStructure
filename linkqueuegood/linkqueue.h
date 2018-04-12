#pragma once
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define TestType printf("\n################################## %s #################################\n",__FUNCTION__)
#define LinkQueueType char

typedef struct LinkNode{
    struct LinkNode* next;
    LinkQueueType data;
} LinkNode;

typedef struct LinkQueue{
    struct LinkNode* head;
    struct LinkNode* tail;
} LinkQueue;

void LinkQueueInit(LinkQueue* q);

void LinkQueuePush(LinkQueue* q,LinkQueueType value);

void LinkQueuePrint(LinkQueue* q,const char* msg);

void LinkQueuePop(LinkQueue* q);

int LinkQueueFront(LinkQueue* q,LinkQueueType* value);
