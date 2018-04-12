#include"linkqueue.h"

void TestLinkQueuePush(){
    TestType;
    LinkQueue* head;
    LinkQueueInit(&head);
    LinkQueuePush(&head,'a');
    LinkQueuePush(&head,'b');
    LinkQueuePush(&head,'c');
    LinkQueuePush(&head,'d');
    LinkQueuePush(&head,'e');
    LinkQueuePrint(head,"abcde入队列");
    return;
}

void TestLinkQueuePop(){
    TestType;
    LinkQueue* head;
    LinkQueueInit(&head);
    LinkQueuePush(&head,'a');
    LinkQueuePush(&head,'b');
    LinkQueuePush(&head,'c');
    LinkQueuePush(&head,'d');
    LinkQueuePush(&head,'e');
    LinkQueuePrint(head,"abcde入队列");
    LinkQueuePop(&head);
    LinkQueuePrint(head,"a出队列");
    return;
}

void TestLinkQueueFront(){
    TestType;
    LinkQueue* head;
    int ret;
    LinkQueueType value;
    LinkQueueInit(&head);
    LinkQueuePush(&head,'a');
    LinkQueuePush(&head,'b');
    LinkQueuePush(&head,'c');
    LinkQueuePush(&head,'d');
    LinkQueuePush(&head,'e');
    ret =  LinkQueueFront(head,&value);
    printf("expect:1, actual: %d\n",ret);
    printf("expect:a, actual: %c\n",value);
    LinkQueuePop(&head);
    ret =  LinkQueueFront(head,&value);
    printf("expect:1, actual: %d\n",ret);
    printf("expect:b, actual: %c\n",value);
    return;
}
int main(){
    TestLinkQueuePush();
    TestLinkQueuePop();
    TestLinkQueueFront();
    return 0;
}
