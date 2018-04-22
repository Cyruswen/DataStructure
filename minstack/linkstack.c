#include"linkstack.h"

void LinkStackInit(LinkStack* q){
    if(q == NULL){
        return;
    }
    q->head = NULL;
    q->tail = NULL;
    return;
}

LinkNode* LinkStackCreateNode(LinkStackType value){
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

void LinkStackPush(LinkStack* q,LinkStackType value){
    if(q == NULL){
        return;
    }
    LinkNode* new_node = LinkStackCreateNode(value);
    if(q->head == NULL){
        q->head = new_node;
        q->tail = new_node;
        return;
    }
    q->tail->next = new_node;
    q->tail = q->tail->next;
    return;
}

void LinkStackPrint(LinkStack* q,const char* msg){
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

void LinkStackPop(LinkStack* q){
    if(q == NULL){
        return;
    }
    if(q->head == NULL){
        return;
    }
    LinkNode* temp = q->tail;
    LinkNode* cur = q->head;
    while(cur->next != q->tail){
        cur = cur->next;
    }
    q->tail = cur;
    q->tail->next = NULL;
    DestroyNode(temp);
    return;
}

int LinkStackFront(LinkStack* q,LinkStackType* value){
    if(q == NULL){
        return 0;
    }
    *value = q->tail->data;
    return 1;
}


//#######################################################################
//############################# 关于栈的面试题 ##########################
//#######################################################################
//#######################################################################
//这都四个了，真的是自己能力不行吗吗吗吗，唉唉，苦逼好好敲代码吧
//最小栈


void MinStackPush(LinkStack* q,LinkStackType value){
    if(q == NULL){
        return;
    }
    if(q->head == NULL){
        LinkNode* new_node1 = LinkStackCreateNode(value);
        LinkNode* new_node2 = LinkStackCreateNode(value);
        q->head = new_node1;
        q->tail = new_node2;
        return;
    }
    LinkStack* cur = q;
    if(cur->tail->data > value){
        LinkNode* new_node1 = LinkStackCreateNode(value);
        LinkNode* new_node2 = LinkStackCreateNode(value);
        cur->tail->next = new_node1;
        cur->tail = cur->tail->next;
        cur->tail->next = new_node2;
        cur->tail = cur->tail->next;
        return;
    }else{
        LinkNode* new_node1 = LinkStackCreateNode(value);
        LinkNode* new_node2 = LinkStackCreateNode(cur->tail->data);
        cur->tail->next = new_node1;
        cur->tail = cur->tail->next;
        cur->tail->next = new_node2;
        cur->tail = cur->tail->next;
        return;
    }
    return;
}

void MinStackPop(LinkStack* q){

}

int MinStack(LinkStack* q,LinkStackType* value){
    if(q == NULL || value == NULL){
        return 0;
    }
    printf("栈顶元素是：%c\n",q->tail->data);
    return 1;
}
