#include"seqqueue.h"

void TestSeqQueuePush(){
    TestType;
    SeqQueue q;
    SeqQueueInit(&q);
    SeqQueuePush(&q,'a');
    SeqQueuePush(&q,'b');
    SeqQueuePush(&q,'c');
    SeqQueuePush(&q,'d');
   // SeqQueuePush(&q,'e');
    SeqQuquqPrint(&q,"abcde入队列");
    SeqQueuePop(&q);
    SeqQuquqPrint(&q,"a出队列");
    SeqQueuePop(&q);
    SeqQuquqPrint(&q,"b出队列");
    SeqQueuePush(&q,'e');
    SeqQuquqPrint(&q,"e入队列");
    return;
}

void TestSeqQueueFront(){
    TestType;
    SeqQueueType value;
    SeqQueue q;
    SeqQueueInit(&q);
    SeqQueuePush(&q,'a');
    SeqQueuePush(&q,'b');
    SeqQueuePush(&q,'c');
    SeqQueuePush(&q,'d');
    int ret = SeqQueueFront(&q,&value);
    printf("expect: 1 , actual:%d\n",ret);
    printf("expect: a , actual:%c\n",value);
    SeqQueuePop(&q);
    SeqQueuePop(&q);
    SeqQueuePush(&q,'e');
    SeqQuquqPrint(&q,"ab出队列,e入队列");
    ret = SeqQueueFront(&q,&value);
    printf("expect: 1 , actual:%d\n",ret);
    printf("expect: c , actual:%c\n",value);
    return;
}

int main(){
    TestSeqQueuePush();
    TestSeqQueueFront();
    return 0;
}
