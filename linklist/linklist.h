#pragma once

#include<stddef.h>

#define TestType printf("\n*************************%s*****************************\n",__FUNCTION__);

typedef char LinkNodeType;

typedef struct LinkNode{
	LinkNodeType data;
	struct LinkNode* next;
}LinkNode;


void LinkListInit(LinkNode** node);

LinkNode* CreateNode(LinkNodeType value);


void LinkListPrintChar(LinkNode* phead,const char* msg);

void LinkListDestroy(LinkNode** phead);

void LinkListPushBack(LinkNode** phead, LinkNodeType value);

void LinkListPopBack(LinkNode** phead);

void LinkListPushFront(LinkNode** phead,LinkNodeType value);

void LinkListPopFront(LinkNode** phead);

LinkNode* LinkListFind(LinkNode* phead,LinkNodeType to_find);

void LinkListInsert(LinkNode** phead,LinkNode* pos,LinkNodeType value);

void LinkListInsertAfter(LinkNode** phead,LinkNode* pos,LinkNodeType value);

void LinkListErase1(LinkNode** phead,LinkNode* pos);

void LinkListErase2(LinkNode** phead,LinkNode** pos);

void LinkListRemove(LinkNode** phead,LinkNodeType value);

void LinkListRemoveAll(LinkNode** phead,LinkNodeType value);

int LinkListEmpty(LinkNode* phead);

size_t LinkListSize(LinkNode* phead);

//面试题

void LinkListPrintReverse(LinkNode* phead);

void LinkListErase3(LinkNode** phead,LinkNode** pos);

void LinkListInsertSp(LinkNode** phead, LinkNode* pos, LinkNodeType value);

LinkNode* JoseCycle(LinkNode* phead,size_t food);

void LinkListReverse(LinkNode** phead);

void LinkListBubble(LinkNode* phead);

LinkNode* LinkListMerge(LinkNode* phead1,LinkNode* phead2);

LinkNode* LinkListFindMid(LinkNode* phead);

LinkNode* LinkListFindKth(LinkNode* phead,size_t k);

LinkNode* LinkListHasCycle(LinkNode* phead);

size_t LinkListCycleSize(LinkNode* phead);

LinkNode* LinkListCycleEntryPos(LinkNode* phead);

LinkNode* LinkListHasCyclePos(LinkNode* phead1,LinkNode* phead2);

LinkNode* LinkListHasCyclePos(LinkNode* phead1,LinkNode* phead2);

LinkNode* UnionSet(LinkNode* phead1,LinkNode* phead2);
