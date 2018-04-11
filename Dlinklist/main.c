#include"DLinkList.h"

void TestDLinkListInit(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPrint(head,"初始化链表");
    return;
}

void TestDLinkListPushBack(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插abcd");
    return;
}

void TestDLinkListPushFront(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插abcd");
}

void TestDLinkListPopBack(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPopBack(head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插abcd");
    DLinkListPopBack(head);
    DLinkListPrint(head,"尾删d");
    return;
}

void TestDLinkListPopFront(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPopFront(head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插abcd");
    DLinkListPopFront(head);
    DLinkListPrint(head,"头删a");
    return;
}

void TestDLinkListInsert(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插abcd");
    DLinkNode* pos = DLinkListFind(head,'c');
    DLinkListInsert(head,pos,'x');
    DLinkListPrint(head,"c后插入x");
    DLinkNode* pos2 = DLinkListFind(head,'d');
    DLinkListInsert(head,pos2,'y');
    DLinkListPrint(head,"d后插入y");
    return;
}

void TestDLinkListInsertBefore(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插abcd");
    DLinkNode* pos_c = DLinkListFind(head,'c');
    DLinkListInsertBefore(head,pos_c,'x');
    DLinkListPrint(head,"c前插入x");
    DLinkNode* pos_a = DLinkListFind(head,'a');
    DLinkListInsertBefore(head,pos_a,'y');
    DLinkListPrint(head,"a前插入y");
    return;
}

void TestDLinkListErasePos(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插abcd");
    DLinkNode* pos_c = DLinkListFind(head,'c');
    DLinkListInsert(head,pos_c,'x');
    DLinkListPrint(head,"c后插入x");
    DLinkNode* pos_x = DLinkListFind(head,'x');
    DLinkListErasePos(head,pos_x);
    DLinkListPrint(head,"删除x");
    DLinkNode* pos_d = DLinkListFind(head,'d');
    DLinkListInsert(head,pos_d,'y');
    DLinkListPrint(head,"d后插入y");
    DLinkNode* pos_y = DLinkListFind(head,'y');
    DLinkListErasePos(head,pos_y);
    DLinkListPrint(head,"删除y");
    return;
}

void TestDLinkListEraseValue(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插abcd");
    DLinkNode* pos_c = DLinkListFind(head,'c');
    DLinkListInsert(head,pos_c,'x');
    DLinkListPrint(head,"c后插入x");
    DLinkListEraseValue(head,'x');
    DLinkListPrint(head,"删除x");
    return;
}

void TestDestroyDLinkList(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插abcd");
    DestroyDLinkList(&head);
    DLinkListPrint(head,"销毁链表");
    return;
}

void TestDLinkListSize(){
    TestType;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPushBack(head,'e');
    DLinkListPushBack(head,'f');
    size_t size = DLinkListSize(head);
    printf("expect:6,actual:%zu\n",size);
}

int main(){
    TestDLinkListInit();
    TestDLinkListPushBack();
    TestDLinkListPushFront();
    TestDLinkListPopBack();
    TestDLinkListPopFront();
    TestDLinkListInsert();
    TestDLinkListInsertBefore();
    TestDLinkListErasePos();
    TestDLinkListEraseValue();
    TestDestroyDLinkList();
    TestDLinkListSize();
    printf("\n\n\n");
    return 0;
}
