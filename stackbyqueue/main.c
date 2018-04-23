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

void TestStackByQueuePush(){
    TestType;
    LinkQueue from;
    LinkQueue to;
    LinkQueueInit(&from);
    LinkQueueInit(&to);
    StackByQueuePush(&from, &to, 'a');
    StackByQueuePush(&from, &to, 'b');
    StackByQueuePush(&from, &to, 'c');
    StackByQueuePush(&from, &to, 'd');
    LinkQueuePrint(&from,"队列from");
    LinkQueuePrint(&to,"队列to");
    return;
}

void TestStackByQueuePop(){
    TestType;
    LinkQueue from;
    LinkQueue to;
    LinkQueueType value;
    LinkQueueInit(&from);
    LinkQueueInit(&to);
    StackByQueuePush(&from, &to, 'a');
    LinkQueuePrint(&from, "from队列");
    LinkQueuePrint(&to,"to 队列");
    StackByQueuePush(&from, &to, 'b');
    LinkQueuePrint(&from, "from队列");
    LinkQueuePrint(&to,"to 队列");
    int ret =  StackByQueuePop(&from, &to, &value);
    printf("ret expect:1, actual:%d\n",ret);
    printf("value expect b, actual:%c\n", value);
    LinkQueuePrint(&from, "from队列");
    LinkQueuePrint(&to,"to 队列");
    StackByQueuePush(&from, &to, 'c');
    LinkQueuePrint(&from, "from队列");
    LinkQueuePrint(&to,"to 队列");
    ret =  StackByQueuePop(&from, &to, &value);
    printf("ret expect:1, actual:%d\n",ret);
    printf("value expect c, actual:%c\n", value);
    LinkQueuePrint(&from, "from队列");
    LinkQueuePrint(&to,"to 队列");
    StackByQueuePush(&from, &to, 'd');
    LinkQueuePrint(&from, "from队列");
    LinkQueuePrint(&to,"to 队列");
}

int main(){
   // TestLinkQueuePush();
   // TestLinkQueuePop();
   // TestLinkQueueFront();
    TestStackByQueuePush();
    TestStackByQueuePop();
    return 0;
}
