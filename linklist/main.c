#include"linklist.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

void TestInit(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	printf("phead = %p\n",phead);
}


void TestPushBack(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'d');
	LinkListPrintChar(phead," 尾部插入");
	LinkListPopBack(&phead);
	LinkListPrintChar(phead," 尾部删除 ");
}

void TestLinkListPushFront(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'d');
	LinkListPrintChar(phead," 尾部插入 ");
	LinkListPushFront(&phead,'x');
	LinkListPrintChar(phead," 头部插入 ");
	LinkListPopFront(&phead);
	LinkListPrintChar(phead," 头部删除 ");
}

void TestLinkListFind(){
	TestType;
	LinkNode* phead;
	LinkNode* cur;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'d');
	LinkListPushBack(&phead,'e');
	LinkListPrintChar(phead," 插入五个元素 ");
	cur = LinkListFind(phead,'d');
	printf("要查找的元素位于[%p]\n",cur);
}

void TestLinkListInsert(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListInsert(&phead,phead,'x');
	LinkListPrintChar(phead," 对空链表插入 ");
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'d');
	LinkListPushBack(&phead,'e');
	LinkListPrintChar(phead," 尾部插入五个元素 ");
	LinkListInsert(&phead,NULL,'y');
	LinkListPrintChar(phead," pos = NULL ");
	LinkListInsert(&phead,phead,'z');
	LinkListPrintChar(phead," pos = phead ");
	LinkNode* pos = LinkListFind(phead,'c');
	LinkListInsert(&phead,pos,'m');
	LinkListPrintChar(phead," c位置插入m ");
}

void TestLinkListInsertAfter(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListInsertAfter(&phead,phead,'x');
	LinkListPrintChar(phead," 对空链表插入 ");
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'d');
	LinkListPushBack(&phead,'e');
	LinkListPrintChar(phead," 尾部插入五个元素 ");
	LinkListInsertAfter(&phead,NULL,'y');
	LinkListInsertAfter(&phead,phead,'z');
	LinkListPrintChar(phead," pos = phead ");
	LinkNode* pos = LinkListFind(phead,'c');
	LinkListInsertAfter(&phead,pos,'m');
	LinkListPrintChar(phead," c位置插入m ");
}

void TestLinkListErase1(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'d');
	LinkNode* pos = LinkListFind(phead,'d');
	LinkListErase1(&phead,phead);
	LinkListPrintChar(phead," 删除头节点 ");
	LinkListErase1(&phead,pos);
	LinkListPrintChar(phead," 删除d元素 ");
}

void TestLinkListErase2(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'d');
	LinkListPrintChar(phead," 尾插四个元素 ");
	LinkNode* posa = LinkListFind(phead,'a');
	LinkNode* posd = LinkListFind(phead,'d');
	LinkListErase2(&phead,&posa);
	LinkListPrintChar(phead," 删除a元素 ");
	LinkListErase2(&phead,&posd);
	LinkListPrintChar(phead," 删除d元素 ");
}

void TestLinkListRemove(){
	TestType;
	LinkNode* phead;
	int empty;
	size_t count;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'d');
	LinkListPrintChar(phead," 尾插四个元素 ");
	empty = LinkListEmpty(phead);
	printf("empty = [%d]\n",empty);
	count = LinkListSize(phead);
	printf("数组长度为：%zu\n\n",count);
	LinkListRemove(&phead,'c');
	LinkListPrintChar(phead," 删除元素c ");
}

void TestLinkListRemoveAll(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'b');
	LinkListPrintChar(phead," 尾部插入元素 ");
	LinkListRemoveAll(&phead,'b');
	LinkListPrintChar(phead," 删除所有的b ");
}

void TestLinkListPrintReverse(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'d');
	LinkListPrintChar(phead," 尾部插入元素 ");
	LinkListPrintReverse(phead);
	printf("\n");
}

void TestLinkListErase3(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'c');
	LinkListPushBack(&phead,'d');
    LinkNode* pos = LinkListFind(phead,'a');
    LinkListErase3(&phead,&pos);
    LinkListPrintChar(phead,"删除元素a");
    LinkNode* pos2 = LinkListFind(phead,'d');
    LinkListErase3(&phead,&pos2);
    LinkListPrintChar(phead,"删除元素d");
}

void TestLinkListInsertSp(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    LinkNode* pos = LinkListFind(phead,'a');
    LinkListInsertSp(&phead,pos,'e');
    LinkListPrintChar(phead,"a元素前插入e");
}

void TestJoseCycle(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    LinkListPushBack(&phead,'e');
    LinkListPushBack(&phead,'f');
    LinkListPushBack(&phead,'g');
    LinkListPushBack(&phead,'h');
    LinkNode* cur = phead;    
    while( cur->next != NULL ){
        cur = cur->next;
    }
    cur->next = phead;
    LinkNode* pos = JoseCycle(phead,5);
    printf("运行结果：%c\t预期结果:c\n",pos->data);
}

void TestLinkListReverse(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    LinkListPushBack(&phead,'e');
    LinkListReverse(&phead);
    LinkListPrintChar(phead,"逆置链表");
}

void TestLinkListBubble(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'d');
	LinkListPushBack(&phead,'e');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'b');
	LinkListPushBack(&phead,'f');
    LinkListPushBack(&phead,'a');
    LinkListBubble(phead);
    LinkListPrintChar(phead,"链表排序");
}

void TestLinkListMerge(){
	TestType;
	LinkNode* phead1;
    LinkNode* phead2;
	LinkListInit(&phead1);
    LinkListInit(&phead2);
	LinkListPushBack(&phead1,'b');
	LinkListPushBack(&phead1,'d');
    LinkListPushBack(&phead1,'f');
    LinkListPushBack(&phead1,'h');
	LinkListPushBack(&phead1,'j');
    LinkListPushBack(&phead1,'l');
	LinkListPushBack(&phead2,'a');
	LinkListPushBack(&phead2,'c');
    LinkListPushBack(&phead2,'e');
    LinkListPushBack(&phead2,'g');
	LinkListPushBack(&phead2,'i');
    LinkListPushBack(&phead2,'k');
    LinkListPrintChar(phead1,"链表一");
    LinkListPrintChar(phead2,"链表二");
    LinkNode* phead = LinkListMerge(phead1,phead2);
    LinkListPrintChar(phead,"合并后的链表");
}

void TestLinkListFindMid(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'d');
	LinkListPushBack(&phead,'e');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'m');
    LinkNode* pos = LinkListFindMid(phead);
    printf("expect:c  actual:%c\n",pos->data);
}

void TestLinkListFindKth(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'d');
	LinkListPushBack(&phead,'e');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'m');
    LinkNode* pos = LinkListFindKth(phead,4);
    printf("expect:e  actual:%c\n",pos->data);
}

void TestLinkListEraseKth(){
	TestType;
	LinkNode* phead;
	LinkListInit(&phead);
	LinkListPushBack(&phead,'a');
	LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    LinkListPushBack(&phead,'e');
	LinkListPushBack(&phead,'f');
	LinkListPushBack(&phead,'g');
    LinkListPushBack(&phead,'h');
    LinkListPushBack(&phead,'i');
    LinkListPrintChar(phead,"初始链表");
    LinkListEraseKth(&phead,1);
    LinkListPrintChar(phead,"删除元素i");
    LinkListEraseKth(&phead,4);
    LinkListPrintChar(phead,"删除元素e");
    LinkListEraseKth(&phead,7);
    LinkListPrintChar(phead,"删除元素a");
    LinkListEraseKth(&phead,15);
}

void TestLinkListHasCycle(){
	TestType;
	LinkNode* phead1;
    LinkNode* phead2;
    LinkNode* a;
    LinkNode* b;
	LinkListInit(&phead1);
    LinkListInit(&phead2);
	LinkListPushBack(&phead1,'a');
	LinkListPushBack(&phead1,'b');
    LinkListPushBack(&phead1,'c');
    LinkListPushBack(&phead1,'d');
	LinkListPushBack(&phead1,'e');
    LinkListPushBack(&phead1,'f');
    LinkNode* cur = phead1;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = phead1;
	LinkListPushBack(&phead2,'a');
	LinkListPushBack(&phead2,'b');
    LinkListPushBack(&phead2,'c');
    LinkListPushBack(&phead2,'d');
	LinkListPushBack(&phead2,'e');
    LinkListPushBack(&phead2,'f');
    a = LinkListHasCycle(phead1);
    b = LinkListHasCycle(phead2);
    printf("actual:%p\n\n",a);
    printf("actual:%p\n",b);
}

void TestLinkListCycleSize(){
	TestType;
	LinkNode* phead1;
    LinkNode* phead2;
    size_t size1 = 0;
    size_t size2 = 0;
	LinkListInit(&phead1);
    LinkListInit(&phead2);
	LinkListPushBack(&phead1,'a');
	LinkListPushBack(&phead1,'b');
    LinkListPushBack(&phead1,'c');
    LinkListPushBack(&phead1,'d');
	LinkListPushBack(&phead1,'e');
    LinkListPushBack(&phead1,'f');
    LinkNode* cur = phead1;
    while(cur->next != NULL){
        cur = cur->next;
    }
    LinkNode* pos_c =  LinkListFind(phead1,'c');
    cur->next = pos_c;
	LinkListPushBack(&phead2,'a');
	LinkListPushBack(&phead2,'b');
    LinkListPushBack(&phead2,'c');
    LinkListPushBack(&phead2,'d');
	LinkListPushBack(&phead2,'e');
    LinkListPushBack(&phead2,'f');
    size1 = LinkListCycleSize(phead1);
    size2 = LinkListCycleSize(phead2);
    printf("%zu\n",size1);
    printf("%zu\n",size2);
}

void TestLinkListCycleEntryPos(){
	TestType;
	LinkNode* phead1;
    LinkNode* phead2;
	LinkListInit(&phead1);
    LinkListInit(&phead2);
	LinkListPushBack(&phead1,'a');
	LinkListPushBack(&phead1,'b');
    LinkListPushBack(&phead1,'c');
    LinkListPushBack(&phead1,'d');
	LinkListPushBack(&phead1,'e');
    LinkListPushBack(&phead1,'f');
    LinkNode* cur = phead1;
    while(cur->next != NULL){
        cur = cur->next;
    }
    LinkNode* pos_c =  LinkListFind(phead1,'c');
    cur->next = pos_c;
    LinkNode* Entry = LinkListCycleEntryPos(phead1);
    printf("expect:%p actual:%p\n",pos_c,Entry);
}

void TestLinkListHasCyclePos(){
	TestType;
	LinkNode* phead1;
    LinkNode* phead2;
	LinkListInit(&phead1);
    LinkListInit(&phead2);
	LinkListPushBack(&phead1,'a');
	LinkListPushBack(&phead1,'b');
    LinkListPushBack(&phead1,'c');
    LinkListPushBack(&phead1,'d');
	LinkListPushBack(&phead1,'e');
    LinkListPushBack(&phead1,'f');
    LinkNode* cur1 = phead1;
    while(cur1->next != NULL){
        cur1 = cur1->next;
    }
    LinkNode* pos_c =  LinkListFind(phead1,'c');
    cur1->next = pos_c;
    LinkListPushBack(&phead2,'g');
    LinkListPushBack(&phead2,'h');
    LinkListPushBack(&phead2,'i');
    LinkNode* cur2 = phead2;
    while(cur2->next != NULL){
        cur2 = cur2->next;
    }
    LinkNode* pos_b = LinkListFind(phead1,'b');
    cur2->next = pos_b;
    LinkNode* pos_x = LinkListHasCyclePos(phead1,phead2);
    printf("\n           ******************* 交点在环外 ***********************\n");
    printf("expect:%p actual:%p\n",pos_b,pos_x);
    LinkNode* pos_d = LinkListFind(phead1,'d');
    cur2->next = pos_d;
    LinkNode* pos_y = LinkListHasCyclePos(phead1,phead2);
    LinkNode* Entry = LinkListCycleEntryPos(phead1);
    printf("\n           ******************* 交点在环内 ***********************\n");
    printf("expect:%p actual:%p\n",Entry,pos_y);
    cur1->next = NULL;
    cur2->next = NULL;
    LinkNode* pos_z = LinkListHasCyclePos(phead1,phead2);
    printf("\n           ******************* 两个无环交点不相交 ***********************\n");
    printf("expect：NULL actual:%p\n",pos_z);
    LinkNode* pos_e = LinkListFind(phead1,'e');
    cur2->next = pos_e;
    LinkNode* pos_m = LinkListHasCyclePos(phead1,phead2);
    printf("\n           ******************* 两个无环交点相交 ***********************\n");
    printf("expect：%p actual:%p\n",pos_e,pos_m);
}

void TestUnionSet(){
	TestType;
	LinkNode* phead1;
    LinkNode* phead2;
	LinkListInit(&phead1);
    LinkListInit(&phead2);
	LinkListPushBack(&phead1,'a');
	LinkListPushBack(&phead1,'b');
    LinkListPushBack(&phead1,'c');
    LinkListPushBack(&phead1,'d');
	LinkListPushBack(&phead1,'e');
    LinkListPushBack(&phead1,'f');
	LinkListPushBack(&phead2,'d');
	LinkListPushBack(&phead2,'e');
    LinkListPushBack(&phead2,'f');
    LinkListPushBack(&phead2,'g');
	LinkListPushBack(&phead2,'h');
    LinkNode* new_head = UnionSet(phead1,phead2);
    LinkListPrintChar(new_head,"查找相同数据");
}

int main(){
	TestInit();
	TestPushBack();
	TestLinkListPushFront();
	TestLinkListFind();
	TestLinkListInsert();
	TestLinkListInsertAfter();
	TestLinkListErase1();
	TestLinkListErase2();
	TestLinkListRemove();
	TestLinkListRemoveAll();
	TestLinkListPrintReverse();
    TestLinkListErase3();
    TestLinkListInsertSp();
    TestJoseCycle();
    TestLinkListReverse();
    TestLinkListBubble();
    TestLinkListMerge();
    TestLinkListFindMid();
    TestLinkListFindKth();
    TestLinkListEraseKth();
    TestLinkListHasCycle();
    TestLinkListCycleSize();
    TestLinkListCycleEntryPos();
    TestLinkListHasCyclePos();
    TestUnionSet();
    printf("\n\n\n");
	return 0;
}
