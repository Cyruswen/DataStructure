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

int main(){
    TestSeqQueuePush();
    return 0;
}
