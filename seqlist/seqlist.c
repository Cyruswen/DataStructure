#include"seqlist.h"

void SeqListPrintChar(SeqList* seqlist,const char* msg){
	if(seqlist == NULL){
		printf("非法输入\n");
		return;
	}
	printf("[%s]\n",msg);
	size_t i = 0;
	for(;i < seqlist->size; ++i){
		printf("[%c]",seqlist->data[i]);
	}
	printf("\n");
}

void SeqListInit(SeqList* seqlist){
	if(seqlist == NULL){
		return;
	}	
	seqlist->size = 0;
}

void SeqListPushBack(SeqList* seqlist,SeqListType value){
	//非法输入
	if( seqlist == NULL){
		return;
	}
	//满顺序表
	if(seqlist->size == SeqListMaxSize){
		return;
	}
	seqlist->data[seqlist -> size] = value;
	++seqlist->size;
	return;
}

void SeqListPopBack(SeqList* seqlist){
	//非法输入
	if(seqlist == NULL){
		return;
	}
	//空顺序表
	if(seqlist->size == 0){
		return;
	}
	--seqlist->size;
	return;
}


void SeqListPushFront(SeqList* seqlist,SeqListType value){
	//非法输入
	if(seqlist == NULL){
		return;
	}
	//满顺序表
	if(seqlist->size == SeqListMaxSize){
		return;
	}
	
	++seqlist->size;
	size_t i = seqlist->size - 1;
	for(; i > 0; --i){
		seqlist->data[i] = seqlist->data[i-1];
	}
	seqlist -> data[0] = value;
	return;
}

void SeqListPopFront(SeqList* seqlist){
	
	size_t i = 0;
	if(seqlist == NULL){
		return;
	}
	if(seqlist == 0){
		return;
	}
	for(; i < seqlist->size - 1; i++){
		seqlist->data[i] = seqlist->data[i+1];
	}
	--seqlist->size;
	return;
}


void SeqListInsert(SeqList* seqlist,size_t pos,SeqListType value){
	if(seqlist == NULL){
		return;
	}
	if(seqlist->size == SeqListMaxSize){
		return;
	}
	if(pos >= seqlist->size){
		return;
	}

	++seqlist->size;
	size_t i = seqlist->size - 1;
	for(;i-1 >= pos; --i){
		seqlist->data[i] = seqlist->data[i-1];
	}
	seqlist->data[pos] = value;
	return;
}

void SeqListErase(SeqList* seqlist,size_t pos){
	if(seqlist == NULL){
		return;
	}
	if(seqlist->size == 0){
		return;
	}
	if(pos >= seqlist->size){
		return;
	}
	size_t i = pos;
	for(; i < seqlist->size - 1; ++i){
		seqlist->data[i] = seqlist->data[i+1];
	}
	--seqlist->size;
	return;
}

int SeqListGet(SeqList* seqlist,size_t pos,SeqListType* value){
	if(seqlist == NULL){
		return 0;
	}
	
	if(pos >= seqlist->size){
		return 0;
	}
	*value = seqlist->data[pos];
	return 1;
}

void SeqListSet(SeqList* seqlist, size_t pos, SeqListType value){
	
	if (seqlist == NULL){
		return;
	}

	if(pos >= seqlist->size){
		return;
	}
	
	seqlist->data[pos] = value;
	return;
}

size_t SeqListFind(SeqList* seqlist,SeqListType to_find){

	if(seqlist == NULL){
		return;
	}

	size_t pos = 0;
	for(;pos < seqlist->size;++pos){
		if(seqlist->data[pos] == to_find){
			return pos;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList* seqlist,SeqListType to_remove){
	if(seqlist == NULL){
		return;
	}
	size_t pos = 0;

	do{
		pos = SeqListFind(seqlist,to_remove);
		SeqListErase(seqlist,pos);
	}while(pos < seqlist->size - 1);
}

void Swap(SeqListType* a,SeqListType* b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void SeqListBubbleSort(SeqList* seqlist){
	if(seqlist == NULL){
		return;
	}
	
	size_t count = 0;
	for(;count < seqlist->size;++count){
		size_t cur = 0;
		for(;cur < seqlist->size - 1 - count;++cur){
			if(seqlist->data[cur] > seqlist->data[cur + 1]){
				Swap(&seqlist->data[cur],&seqlist->data[cur + 1]);
			}
		}
	}
	return;
}
