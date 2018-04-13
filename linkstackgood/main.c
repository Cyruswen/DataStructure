#include"linkstack.h"

void TestLinkStackPush(){
    TestType;
    LinkStack q;
    LinkStackInit(&q);
    LinkStackPush(&q,'a');
    LinkStackPush(&q,'b');
    LinkStackPush(&q,'c');
    LinkStackPush(&q,'d');
    LinkStackPush(&q,'e');
    LinkStackPrint(&q,"abcde入栈");
    return;
}

void TestLinkStackPop(){
    TestType;
    LinkStack q;
    LinkStackInit(&q);
    LinkStackPush(&q,'a');
    LinkStackPush(&q,'b');
    LinkStackPush(&q,'c');
    LinkStackPush(&q,'d');
    LinkStackPush(&q,'e');
    LinkStackPrint(&q,"abcde入栈");
    LinkStackPop(&q);
    LinkStackPrint(&q,"e出栈");
    LinkStackPop(&q);
    LinkStackPrint(&q,"d出栈");
    return;
}

void TestLinkStackFront(){
    TestType;
    LinkStack q;
    LinkStackType value;
    LinkStackInit(&q);
    LinkStackPush(&q,'a');
    LinkStackPush(&q,'b');
    LinkStackPush(&q,'c');
    LinkStackPush(&q,'d');
    LinkStackPush(&q,'e');
    LinkStackPrint(&q,"abcde入栈");
    int ret = LinkStackFront(&q,&value);
    printf("expect: 1, actual: %d\n",ret);
    printf("expext: e, actual: %c\n",value);
    LinkStackPop(&q);
    ret = LinkStackFront(&q,&value);
    printf("expect: 1, actual: %d\n",ret);
    printf("expext: d, actual: %c\n",value);
    return;
}

int main(){
    TestLinkStackPush();
    TestLinkStackPop();
    TestLinkStackFront();
    return 0;
}
