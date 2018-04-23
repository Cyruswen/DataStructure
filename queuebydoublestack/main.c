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
    LinkStackPrint(&q,"abc入栈");
    LinkStackPop(&q);
    LinkStackPrint(&q,"c出栈");
    LinkStackPop(&q);
    LinkStackPrint(&q,"b出栈");
    LinkStackPop(&q);
    LinkStackPrint(&q,"a出栈");
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
void TestQueueByStackPush(){
    TestType;
    LinkStack q1;
    LinkStack q2;
    LinkStackInit(&q1);
    LinkStackInit(&q2);
    QueueByStackPush(&q1, &q2, 'a');
    QueueByStackPush(&q1, &q2, 'b');
    QueueByStackPush(&q1, &q2, 'c');
    QueueByStackPush(&q1, &q2, 'd');
    QueueByStackPush(&q1, &q2, 'e');
    LinkStackPrint(&q1,"栈q1");
    LinkStackPrint(&q2,"栈q2");
}

void TestQueueByStackPop(){
    TestType;
    LinkStack q1;
    LinkStack q2;
    LinkStackInit(&q1);
    LinkStackInit(&q2);
    QueueByStackPush(&q1, &q2, 'a');
    QueueByStackPush(&q1, &q2, 'b');
    QueueByStackPush(&q1, &q2, 'c');
    QueueByStackPush(&q1, &q2, 'd');
    LinkStackPrint(&q2,"栈q2");
    QueueByStackPop(&q1, &q2);
    LinkStackPrint(&q2,"栈q2");
    QueueByStackPop(&q1, &q2);
    LinkStackPrint(&q2,"栈q2");
    QueueByStackPop(&q1, &q2);
    LinkStackPrint(&q2,"栈q2");
    return;
}

int main(){
   // TestLinkStackPush();
   // TestLinkStackPop();
   // TestLinkStackFront();
    TestQueueByStackPush();
    TestQueueByStackPop();
   
    return 0;
}
