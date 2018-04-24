#include<stdio.h>
#include<stddef.h>


#define TestType printf("\n###################### %s #########################\n",__FUNCTION__)
#define SeqQueueMaxSize 1000
#if 1
struct TreeNode;
typedef struct TreeNode* SeqQueueType;
#else
typedef char SeqQueueType;
#endif
typedef struct SeqQueue{
    SeqQueueType data[SeqQueueMaxSize];
    size_t head;
    size_t tail;
    size_t size;
} SeqQueue;

void SeqQueueInit(SeqQueue* q);

void SeqQueuePush(SeqQueue* q,SeqQueueType value);

void SeqQueuePop(SeqQueue* q);

void SeqQuquqPrint(SeqQueue* q,const char* msg);

int SeqQueueFront(SeqQueue* q,SeqQueueType* value);
