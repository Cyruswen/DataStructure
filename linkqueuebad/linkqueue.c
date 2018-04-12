#include"linkqueue.h"

void DestroyNode(LinkQueue* to_delete){
    free(to_delete);
    return;
}

void LinkQueueInit(LinkQueue** phead){
    if(phead == NULL){
        return;
    }
    *phead = NULL;
}

LinkQueue* LinkQueueCreateNode(LinkQueueType value){
    LinkQueue* new_node = (LinkQueue*)malloc(sizeof(LinkQueue));
    new_node->next = NULL;
    new_node->data = value;
    return new_node;
}

void LinkQueuePush(LinkQueue** phead,LinkQueueType value){
    if(phead == NULL){
        return; 
    }
    if(*phead == NULL){
        *phead = LinkQueueCreateNode(value);
        (*phead)->tail = *phead;
        return;
    }
    (*phead)->tail->next = LinkQueueCreateNode(value);
    (*phead)->tail = (*phead)->tail->next;
    return;
}

void LinkQueuePrint(LinkQueue* head, const char* msg){
    if(head == NULL){
        printf("空队列！\n");
        return;
    }
    printf("[ %s ]:\n",msg);
    LinkQueue* cur = head;
    while(cur != NULL){
        printf("[%c][%p]<-",cur->data,cur);
        cur = cur->next;
    }
    printf("NULL\n\n");
    return;
}

void LinkQueuePop(LinkQueue** phead){
    if(phead == NULL){
        return;
    }
    if(*phead == NULL){
        return;
    }
    LinkQueue* tmp = (*phead);
    *phead = (*phead)->next;
    DestroyNode(tmp);
    tmp = NULL;
    return;
}

int LinkQueueFront(LinkQueue* head,LinkQueueType* value){
    if(head == NULL){
        return 0;
    }
    *value = head->data;
    return 1;
}
