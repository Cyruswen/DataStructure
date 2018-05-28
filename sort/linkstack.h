#pragma once
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define TestType printf("\n################################## %s #################################\n",__FUNCTION__)
#define LinkStackType int

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

int LinkStackTop(LinkStack* q,int64_t* value);
