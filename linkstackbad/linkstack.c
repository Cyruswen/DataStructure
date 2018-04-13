#include"linkstack.h"

void LinkStackInit(LinkStack** phead){
    if(phead == NULL){
        return;
    }
    *phead = NULL;
}

void DestroyNode(LinkStack* to_delete){
    free(to_delete);
}

void LinkStackPrint(LinkStack* head,const char* msg){
    printf("[ %s ]:\n",msg);
    if(head == NULL){
        return;
    }
    LinkStack* cur = head;
    while(cur != NULL){
        printf("[%c][%p]->",cur->data,cur);
        cur = cur->next;
    }
    printf("NULL\n");
    return;
}

LinkStack* LinkStackCreateNode(LinkStackType value){
    LinkStack* new_node = (LinkStack*)malloc(sizeof(LinkStack));
    if(new_node == NULL){
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void LinkStackPush(LinkStack** phead,LinkStackType value){
    if(phead == NULL){
        return;
    }
    if(*phead == NULL){
        *phead = LinkStackCreateNode(value);
        (*phead)->tail = *phead;
        return;
    }
    (*phead)->tail->next = LinkStackCreateNode(value);
    (*phead)->tail = (*phead)->tail->next;
    return;
}

void LinkStackPop(LinkStack** phead){
    if(phead == NULL){
        return;
    }
    if(*phead == NULL){
        return;
    }
    LinkStack* cur = *phead;
    while(cur->next != (*phead)->tail){
        cur = cur->next;
    }
    DestroyNode((*phead)->tail);
    cur->next = NULL;
    (*phead)->tail = cur;
}

int LinkStackGetFront(LinkStack* head,LinkStackType* value){
    if(head == NULL){
        return 0;
    }
    *value = head->tail->data;
    return 1;
}

void LinkStackDestroy(LinkStack** phead){
    if(phead == NULL){
        return;
    }
    LinkStack* cur = *phead;
    while(cur != NULL){
        LinkStack* tmp = cur;
        cur = cur->next;
        DestroyNode(tmp);
    }
    *phead = NULL;
    return;
}
