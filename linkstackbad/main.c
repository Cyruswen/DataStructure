#include"linkstack.h"

void TestLinkStackPush(){
    TestType;
    LinkStack* head;
    LinkStackInit(&head);
    LinkStackPush(&head,'a');
    LinkStackPrint(head,"a入栈");
    LinkStackPush(&head,'b');
    LinkStackPrint(head,"b入栈");
    LinkStackPush(&head,'c');
    LinkStackPrint(head,"c入栈");
    return;
}

void TestLinkStackPop(){
    TestType;
    LinkStack* head;
    LinkStackInit(&head);
    LinkStackPush(&head,'a');
    LinkStackPush(&head,'b');
    LinkStackPush(&head,'c');
    LinkStackPush(&head,'d');
    LinkStackPrint(head,"abcd入栈");
    LinkStackPop(&head);
    LinkStackPrint(head,"d出栈");
    LinkStackPop(&head);
    LinkStackPrint(head,"c出栈");
    LinkStackPop(&head);
    LinkStackPrint(head,"b出栈");
    return;
}

void TestLinkStackGetFront(){
    TestType;
    LinkStack* head;
    int result;
    LinkStackType value;
    LinkStackInit(&head);
    LinkStackPush(&head,'a');
    LinkStackPush(&head,'b');
    LinkStackPush(&head,'c');
    LinkStackPush(&head,'d');
    LinkStackPrint(head,"abcd入栈");
    result = LinkStackGetFront(head,&value);
    printf("expect:1,actual:%d\n",result);
    printf("expect:d,actual:%c\n",value);
    LinkStackPop(&head);
    result = LinkStackGetFront(head,&value);
    printf("expect:1,actual:%d\n",result);
    printf("expect:c,actual:%c\n",value);
}

void TestLinkStackDestroy(){
    TestType;
    LinkStack* head;
    LinkStackInit(&head);
    LinkStackPush(&head,'a');
    LinkStackPush(&head,'b');
    LinkStackPush(&head,'c');
    LinkStackPush(&head,'d');
    LinkStackPrint(head,"abcd入栈");
    LinkStackDestroy(&head);
    LinkStackPrint(head,"销毁栈结构");
    return;
}

int main(){
    TestLinkStackPush();
    TestLinkStackPop();
    TestLinkStackGetFront();
    TestLinkStackDestroy();
    printf("\n\n");
    return 0;
}

