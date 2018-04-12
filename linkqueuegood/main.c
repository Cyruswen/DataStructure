#include"linkqueue.h"

void TestLinkQueuePush(){
    TestType;
    LinkQueue q;
    LinkQueueInit(&q);
    LinkQueuePush(&q,'a');
    LinkQueuePush(&q,'b');
    LinkQueuePush(&q,'c');
    LinkQueuePush(&q,'d');
    LinkQueuePush(&q,'e');
    LinkQueuePrint(&q,"abcde入队列");
    return;
}

void TestLinkQueuePop(){
    TestType;
    LinkQueue q;
    LinkQueueInit(&q);
    LinkQueuePush(&q,'a');
    LinkQueuePush(&q,'b');
    LinkQueuePush(&q,'c');
    LinkQueuePush(&q,'d');
    LinkQueuePush(&q,'e');
    LinkQueuePrint(&q,"abcde入队列");
    LinkQueuePop(&q);
    LinkQueuePrint(&q,"a出队列");
    LinkQueuePop(&q);
    LinkQueuePrint(&q,"b出队列");
    return;
}

void TestLinkQueueFront(){
    TestType;
    LinkQueue q;
    LinkQueueType value;
    LinkQueueInit(&q);
    LinkQueuePush(&q,'a');
    LinkQueuePush(&q,'b');
    LinkQueuePush(&q,'c');
    LinkQueuePush(&q,'d');
    LinkQueuePush(&q,'e');
    LinkQueuePrint(&q,"abcde入队列");
    int ret = LinkQueueFront(&q,&value);
    printf("expect: 1, actual: %d\n",ret);
    printf("expext: a, actual: %c\n",value);
    LinkQueuePop(&q);
    ret = LinkQueueFront(&q,&value);
    printf("expect: 1, actual: %d\n",ret);
    printf("expext: b, actual: %c\n",value);
    return;
}

int main(){
    TestLinkQueuePush();
    TestLinkQueuePop();
    TestLinkQueueFront();
    return 0;
}
