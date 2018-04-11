#include"seqqueue.h"

void SeqQueueInit(SeqQueue* q){
    if(q == NULL){
        return;
    }
    q->tail = 0;
    q->head = 0;
    q->size = 0;
    return;
}

void SeqQueuePush(SeqQueue* q,SeqQueueType value){
    if(q == NULL){
        return;
    }
    if(q->size >= SeqQueueMaxSize){
        return;
    }
    q->data[q->tail++] = value;
    if(q->tail >= SeqQueueMaxSize){
        q->tail = 0;
    }
    q->size++;
}

void SeqQueuePop(SeqQueue* q){
    if(q == NULL){
        return;
    }
    if(q->size == 0){
        return;
    }
    q->head++;
    if(q->head >= SeqQueueMaxSize){
        q->head = 0;
    }
    q->size--;
}

void SeqQuquqPrint(SeqQueue* q,const char* msg){
    if(q == NULL){
        return;
    }
    printf("[ %s ]:\n",msg);
    int i = q->tail - 1;
    int count = q->size - 1;
    while(count--){
        if(i >= 0){
            printf("%c->",q->data[i--]);
        }else{
            i = SeqQueueMaxSize - 1;
            printf("%c->",q->data[i--]);
        }
    }
    printf("%c\n",q->data[q->head]);
    return;
}

int SeqQueueFront(SeqQueue* q,SeqQueueType* value){
    if(q == NULL){
        return 0;
    }
    if(q->size == 0){
        return 0;
    }
    *value = q->data[q->head];
    return 1;
}
