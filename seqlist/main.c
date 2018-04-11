#include"seqlist.h"

void TestPushBack(){
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');
	SeqListPrintChar(&seqlist,"尾插元素");
}

void TestSeqListErase(){
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');
	SeqListErase(&seqlist,2);
	SeqListPrintChar(&seqlist,"删除c元素");
}

void TestSeqListGet(){
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');
	//SeqListSet测试函数
	SeqListSet(&seqlist, 1,'x');

	SeqListType value;
	int ret = SeqListGet(&seqlist, 1 ,&value);
	printf("ret expected 1,actual %d\n",ret);
	printf("value expected b,actual %c\n",value);
}

size_t TestSeqListFind(){
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');
	size_t pos = SeqListFind(&seqlist,'c');
	printf("c号元素是:%d\n",pos);
}

void TestSeqListRemoveAll(){
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'r');
	SeqListRemoveAll(&seqlist,'a');
	SeqListPrintChar(&seqlist,"删除所有a");
}

void TestSeqListBubbleSort(){
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'d');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListBubbleSort(&seqlist);
	SeqListPrintChar(&seqlist,"冒泡排序");
}

int main(){
	TestPushBack();
	TestSeqListErase();
	TestSeqListGet();
	TestSeqListFind();
	TestSeqListRemoveAll();
	TestSeqListBubbleSort();
	return 0;
}
