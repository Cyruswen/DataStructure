#pragma once
#include<stdio.h>
#include<unistd.h>
#include<stddef.h>
#include<stdlib.h>

#define TestType printf("\n###################################### %s ########################################\n",__FUNCTION__)

#define DLinkNodeType char

typedef struct DLinkNode{
    DLinkNodeType data;
    struct DLinkNode* prev;
    struct DLinkNode* next;
}DLinkNode;

void DLinkListInit(DLinkNode** phead);

DLinkNode* DLinkListCreateNode(DLinkNodeType value);

void DLinkListPrint(DLinkNode* head,const char* msg);

void DLinkListPushBack(DLinkNode* head,DLinkNodeType value);

void DLinkListPushFront(DLinkNode* head,DLinkNodeType value);

void DLinkListPopBack(DLinkNode* head);

void DLinkListPopFront(DLinkNode* head);

void DLinkListInsert(DLinkNode* head,DLinkNode* pos,DLinkNodeType value);

DLinkNode* DLinkListFind(DLinkNode* head,DLinkNodeType to_find);

void DLinkListErasePos(DLinkNode* head,DLinkNode* pos);

void DLinkListEraseValue(DLinkNode* head,DLinkNodeType to_delete);

void DestroyDLinkList(DLinkNode** phead);

size_t DLinkListSize(DLinkNode* head);

void DLinkListInsertBefore(DLinkNode* head,DLinkNode* pos,DLinkNodeType value);
