#pragma once

#include<stddef.h>
#include<stdio.h>
#define TEST_HEADER printf("\n***********************%s************************\n",__FUNCTION__);

#define SeqListMaxSize 1000

typedef char SeqListType;

typedef struct SeqList {
	SeqListType data[SeqListMaxSize];
	size_t size;
} SeqList;

void SeqListPrintChar(SeqList* seqlist,const char* msg);

void SeqListInit(SeqList* seqlist);

void SeqListPushBack(SeqList* seqlist,SeqListType value);

void SeqListPopBack(SeqList* seqlist);

void SeqListPushFront(SeqList* seqlist,SeqListType value);

void SeqListPopFront(SeqList* seqlist);

void SeqListInsert(SeqList* seqlist, size_t pos, SeqListType value);

void SeqListErase(SeqList* seqlist, size_t pos);

int SeqListGet(SeqList* seqlist, size_t pos, SeqListType* value);

void SeqListSet(SeqList* seqlist, size_t pos, SeqListType value);

size_t SeqListFind(SeqList* seqlist,SeqListType to_find);

void SeqListRemoveAll(SeqList* seqlist,SeqListType to_remove);

void SeqListBubbleSort(SeqList* seqlist);
