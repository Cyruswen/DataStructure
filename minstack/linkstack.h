#pragma once
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define TestType printf("\n################################## %s #################################\n",__FUNCTION__)
#define LinkStackType char

typedef struct LinkNode{
    struct LinkNode* next;
    LinkStackType data;
} LinkNode;

typedef struct LinkStack{
    struct LinkNode* head;
    struct LinkNode* tail;
} LinkStack;

void LinkStackInit(LinkStack* q);

void LinkStackPush(LinkStack* q,LinkStackType value);

void LinkStackPrint(LinkStack* q,const char* msg);

void LinkStackPop(LinkStack* q);

int LinkStackFront(LinkStack* q,LinkStackType* value);

int MinStack(LinkStack* q,LinkStackType* value);

void MinStackPush(LinkStack* q,LinkStackType value);

//void MinStackPop(LinkStack* q);
