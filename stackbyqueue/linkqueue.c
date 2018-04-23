#include"linkqueue.h"

void LinkQueueInit(LinkQueue* q){
    if(q == NULL){
        return;
    }
    q->head = NULL;
    q->tail = NULL;
    return;
}

LinkNode* LinkQueueCreateNode(LinkQueueType value){
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    if(new_node == 0){
        return NULL;
    }
    new_node->next = NULL;
    new_node->data = value;
    return new_node;
}

void DestroyNode(LinkNode* to_delete){
    if(to_delete == NULL){
        return;
    }
    free(to_delete);
    return;
}

void LinkQueuePush(LinkQueue* q,LinkQueueType value){
    if(q == NULL){
        return;
    }
    LinkNode* new_node = LinkQueueCreateNode(value);
    if(q->head == NULL){
        q->head = new_node;
        q->tail = new_node;
        return;
    }
    q->tail->next = new_node;
    q->tail = q->tail->next;
    return;
}

void LinkQueuePrint(LinkQueue* q,const char* msg){
    if(q == NULL){
        return;
    }
    printf("[ %s ]:\n",msg);
    LinkNode* cur = q->head;
    while(cur != NULL){
        printf("[%c][%p]->",cur->data,cur);
        cur = cur->next;
    }
    printf("NULL\n\n");
    return;
}

void LinkQueuePop(LinkQueue* q){
    if(q == NULL){
        return;
    }
    if(q->head == NULL){
        return;
    }
    LinkNode* temp = q->head;
    q->head = q->head->next;
    DestroyNode(temp);
    return;
}

int LinkQueueFront(LinkQueue* q,LinkQueueType* value){
    if(q == NULL){
        return 0;
    }
    *value = q->head->data;
    return 1;
}

//#######################################################################################################
//############################# 两个队列实现一个栈 ######################################################
//#######################################################################################################

LinkQueue* MvStackByQueue(LinkQueue* from, LinkQueue* to){
    if(from == NULL || to == NULL){
        return NULL;
    }
    LinkQueueType value;
    while(from->head != from->tail){
       value =  from->head->data;
       LinkQueuePop(from);
       LinkQueuePush(to,value);
    }
    return from;
}

void StackByQueuePush(LinkQueue* from, LinkQueue* to, LinkQueueType value){
    if(from == NULL || to == NULL){
        return;
    }
    if(from->head == NULL && to->head != NULL){
        LinkQueuePush(to, value);
        return;
    }else{
        LinkQueuePush(from, value);
    }
    return;
}

int StackByQueuePop(LinkQueue* from, LinkQueue* to, LinkQueueType* value){
    if(from == NULL || to == NULL || value == NULL){
        return 1;
    }
    if(from->head == NULL && to->tail != NULL){
        LinkQueue* top = MvStackByQueue(to, from);
        *value = top->head->data;
        LinkQueuePop(to);
    }else{
        LinkQueue* top = MvStackByQueue(from, to);
        *value = top->head->data;
        LinkQueuePop(from);
    }
    return 1;
}
