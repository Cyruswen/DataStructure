#include"DLinkList.h"

DLinkNode* DLinkListCreateNode(DLinkNodeType value){
    DLinkNode* new_node = (DLinkNode*)malloc(sizeof(DLinkNode));
    new_node->data = value;
    new_node->next = new_node;
    new_node->prev = new_node;
    return new_node;
}

void DLinkListDestroyNode(DLinkNode* to_delete){
    free(to_delete);
}

void DLinkListInit(DLinkNode** phead){
    if(phead == NULL){
        return;
    }
    if(*phead == NULL){
        return;
    }
    *phead = DLinkListCreateNode('0');
    return;
}

void DLinkListPrint(DLinkNode* head,const char* msg){
    if(head == NULL){
        printf("链表不存在！非法输入！\n");
        return;
    }
    printf("[ %s ]:\n",msg);
    DLinkNode* cur = head;
    if(cur->next == head){
        printf("[%c][%p]\n",cur->data,cur);
        return;
    }
    printf("[%c][%p]<=>",cur->data,cur);
    cur = cur->next;
    while(cur != head){
        printf("[%c][%p]<=>",cur->data,cur);
        cur = cur->next;
    }
    printf("[%c][%p]\n",cur->data,cur);
    return;
}

void DLinkListPushBack(DLinkNode* head,DLinkNodeType value){
    if(head == NULL){
        return;
    }
    DLinkNode* new_node = DLinkListCreateNode(value);
    DLinkNode* cur = head->prev;
    cur->next = new_node;
    new_node->prev = cur;
    new_node->next = head;
    head->prev = new_node;
    return;
}

void DLinkListPushFront(DLinkNode* head,DLinkNodeType value){
    if(head == NULL){
        return;
    }
    DLinkNode* new_node = DLinkListCreateNode(value);
    DLinkNode* tmp = head->next;
    head->next = new_node;
    new_node->prev = head;
    new_node->next = tmp;
    tmp->prev = new_node;
    return;
}


void DLinkListPopBack(DLinkNode* head){
    if(head == NULL){
        return;
    }
    if(head->next == head){
        printf("无法删除头结点！\n");
        return;
    }
    DLinkNode* to_delete = head->prev;
    to_delete->prev->next = head;
    head->prev = to_delete->prev;
    DLinkListDestroyNode(to_delete);
}

void DLinkListPopFront(DLinkNode* head){
    if(head == NULL){
        return;
    }
    if(head->next == head){
        printf("无法删除头结点！\n");
        return;
    }
    DLinkNode* to_delete = head->next;
    DLinkNode* to_delete_next = to_delete->next;
    head->next = to_delete_next;
    to_delete_next->prev = head;
    DLinkListDestroyNode(to_delete);
}

DLinkNode* DLinkListFind(DLinkNode* head,DLinkNodeType to_find){
    if(head == NULL){
        return NULL;
    }
    DLinkNode* cur = head->next;
    while(cur != head){
        if(cur->data == to_find){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

//pos之后插入节点
void DLinkListInsert(DLinkNode* head,DLinkNode* pos,DLinkNodeType value){
    if(head == NULL || pos == NULL){
        return;
    }
    DLinkNode* new_node = DLinkListCreateNode(value);
    DLinkNode* pos_next = pos->next;
    pos->next = new_node;
    new_node->prev = pos;
    new_node->next = pos_next;
    pos_next->prev = new_node;
    return;
}

//pos之前插入节点
void DLinkListInsertBefore(DLinkNode* head,DLinkNode* pos,DLinkNodeType value){
    if(head == NULL || pos == NULL){
        return;
    }
    DLinkNode* pos_prev = pos->prev;
    DLinkNode* new_node = DLinkListCreateNode(value);
    pos_prev->next = new_node;
    new_node->prev = pos_prev;
    new_node->next = pos;
    pos->prev = new_node;
    return;
}

//删除指定位置的节点
void DLinkListErasePos(DLinkNode* head,DLinkNode* pos){
    if(head == NULL || pos == NULL){
        return;
    }
    DLinkNode* pos_prev = pos->prev;
    DLinkNode* pos_next = pos->next;
    pos_prev->next = pos_next;
    pos_next->prev = pos_prev;
    DLinkListDestroyNode(pos);
    return;
}

//删除指定值的节点
void DLinkListEraseValue(DLinkNode* head,DLinkNodeType to_delete){
    if(head == NULL){
        return;
    }
    DLinkNode* to_delete_pos = DLinkListFind(head,to_delete);
    DLinkListErasePos(head,to_delete_pos);
    return;
}

//销毁链表
void DestroyDLinkList(DLinkNode** phead){
    if(phead == NULL){
        return;
    }
    if(*phead == NULL){
        return;
    }
    DLinkNode* cur = (*phead)->next;
    while(cur != *phead){
        DLinkListErasePos(*phead,cur);
        cur = (*phead)->next;
    }
    DLinkListDestroyNode(*phead);
    *phead = NULL;
    return;
}

size_t DLinkListSize(DLinkNode* head){
    if(head == NULL){
        return 0;
    }
    DLinkNode* cur = head->next;
    size_t count = 0;
    while(cur != head){
        count++;
        cur = cur->next;
    }
    return count;
}
