#include"linklist.h"
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>

void LinkListPrintChar(LinkNode* phead,const char* msg){
	printf("[%s]:\n",msg);
	LinkNode* cur = phead;
	for(;cur != NULL;cur = cur->next){
		printf("[%c][%p]->",cur->data,cur);
	}
	printf("[NULL]\n\n");

}

void LinkListInit(LinkNode** node){
	if(node == NULL){
		//非法输
		return;
	}
	*node = NULL;
}


LinkNode* CreateNode(LinkNodeType value){
	LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    if(new_node == NULL){
        printf("申请内存失败！\n");
        exit(1);
    }else{
        new_node->data = value;
        new_node->next = NULL;
        return new_node;
    }
}

void DestroyNode(LinkNode* node){
	free(node);
}

void LinkListDestroy(LinkNode** phead){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		return;
	}
	while((*phead) != NULL){
		LinkNode* pnode = *phead;
		*phead = (*phead)->next;
		free(pnode);
		pnode = NULL;
	}
	return;
}

void LinkListPushBack(LinkNode** phead, LinkNodeType value){
	
	if( phead == NULL){
		//非法输入
		return;
	}

	if(*phead == NULL){
		//空链表，指向结构体的指针都不存在，说明结构体不存在
		*phead = CreateNode(value);
		return;
	}
	LinkNode* cur = *phead;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = CreateNode(value);
	return;
}

void LinkListPopBack(LinkNode** phead){

	if(phead == NULL){
		return;
	}

	if(*phead == NULL){
		printf("链表为空，无法删除.\n");
		return;
	}

	if((*phead)->next == NULL){
		DestroyNode(*phead);
		*phead = NULL;
		return;
	}
	
	LinkNode* cur = *phead;
	while(cur->next->next != NULL){
		cur = cur->next;
	}
	LinkNode* last = cur->next;
	DestroyNode(last);
	cur->next = NULL;
	return;
}

void LinkListPushFront(LinkNode** phead,LinkNodeType value){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		*phead = CreateNode(value);
		return;
	}
	LinkNode* cur = *phead;
	*phead = CreateNode(value);
	(*phead)->next = cur;
	return;
}

void LinkListPopFront(LinkNode** phead){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		printf("链表为空，无法删除.\n");
		return;
	}
	LinkNode* cur = (*phead)->next;
	(*phead)->next = NULL;
	DestroyNode(*phead);
	*phead = cur;
	return;
}

LinkNode* LinkListFind(LinkNode* phead,LinkNodeType to_find){
	if(phead == NULL){
		printf("链表为空，查找不到！\n");
		return NULL;
	}
	LinkNode* cur = phead;
	for(;cur != NULL; cur = cur->next){
		if(cur->data == to_find){
			return cur;
		}
	}
	return NULL;
}


void LinkListInsert(LinkNode** phead,LinkNode* pos,LinkNodeType value){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		//若为空链表，pos位置无效，将value当作新节点插入
		*phead = CreateNode(value);
		return;
	}
	if(pos == NULL){
		//pos为NULL,简化为尾插
		LinkListPushBack(phead,value);
		return;
	}
	if(pos == *phead){
		//pos为头节点，简化为头插
		LinkListPushFront(phead,value);
		return;
	}
	LinkNode* cur = *phead;
	while(cur->next != NULL){
		if(cur->next == pos){
			LinkNode* tmp = CreateNode(value);
			tmp->next = pos;
			cur->next = tmp;
			return;
		}
		cur = cur->next;
	}
	printf("没有找到！\n");
	return;
}

void LinkListInsertAfter(LinkNode** phead,LinkNode* pos,LinkNodeType value){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		//链表为空，则直接将value作为新节点插入
		*phead = CreateNode(value);
		return;
	}
	if(pos == NULL){
		printf("[ pos = NULL ]\n");
		printf("非法输入!\n\n");
		return;
	}
	LinkNode* cur = *phead;
	while(cur->next != NULL){
		if(cur == pos){
			LinkNode* tmp = CreateNode(value);
			tmp->next = cur->next;
			cur->next = tmp;
			return;
		}
		cur = cur->next;
	}
	return;
}

void LinkListErase1(LinkNode** phead,LinkNode* pos){
	//找到前一个元素进行删除的方法
	if(phead == NULL || pos == NULL){
		//非法输入
		return;
	}
	if(*phead == NULL){
		printf("[ phead = NULL ]\n");
		printf("空链表，无法删除！\n\n");
		return;
	}
	if(*phead == pos){
		//删除位置是头节点
		LinkNode* to_delete = *phead;
		*phead = (*phead)->next;
		DestroyNode(to_delete);
		to_delete->next = NULL;
		return;
	}

	//找到前一个节点进行删除
	LinkNode* cur = *phead;
	while(cur != NULL){
		if(cur->next == pos){
			cur->next = pos->next;
			DestroyNode(pos);
			pos->next = NULL;
			return;
		}
		cur = cur->next;
	}
	return;
}

void LinkListErase2(LinkNode** phead,LinkNode** pos){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		printf("[ phead = NULL ]\n");
		printf("链表为空，无法删除！\n\n");
		return;
	}
	if(*pos != NULL && (*pos)->next != NULL){
		LinkNode* to_delete = (*pos)->next;
		(*pos)->data = to_delete->data;
		(*pos)->next = to_delete->next;
		to_delete->next = NULL;
		DestroyNode(to_delete);
		return;
	}
	if((*pos)->next == NULL){
		LinkListPopBack(phead);
		return;
	}
	printf(" 找不到pos，无法删除！\n");
	return;
}

void LinkListRemove(LinkNode** phead,LinkNodeType value){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		return;
	}
	LinkNode* pos = LinkListFind(*phead,value);
	LinkListErase1(phead,pos);
}


void LinkListRemoveAll(LinkNode** phead,LinkNodeType value){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		return;
	}
	while(1){
		LinkNode* to_delete = LinkListFind(*phead,value);
		if(to_delete == NULL){
			break;
		}
		LinkListErase1(phead,to_delete);
	}
	return;
}

int LinkListEmpty(LinkNode* phead){

	return phead == NULL ? 1 : 0;

}

size_t LinkListSize(LinkNode* phead){
	size_t  count = 1;
	if(phead == NULL){
		return 0;
	}
	LinkNode* cur = phead;
	for(;cur->next != NULL;cur = cur->next){
		count++;
	}
	return count;
}

///////////////////////////////////////////////////////////////
////////////////////////一些面试题/////////////////////////////
///////////////////////////////////////////////////////////////
//1.从尾到头打印元素
void LinkListPrintReverse(LinkNode* phead){
	if(phead == NULL){
		return;
	}
	LinkListPrintReverse(phead->next);
	printf("%c  ",phead->data);
	return;
}
//2.删除一个无头单链表的非尾节点（不能遍历链表）
void LinkListErase3(LinkNode** phead,LinkNode** pos){
    if(phead == NULL){
        return;
    }
    if(*phead == NULL){
        return;
    }
    if(*pos != NULL && (*pos)->next != NULL){
        LinkNode* to_delete = (*pos)->next;
        (*pos)->data = (*pos)->next->data;
        (*pos)->next = (*pos)->next->next;
        to_delete->next = NULL;
        free(to_delete);
    }
    if((*pos)->next == NULL){
        return;
    }
    return;
}

//在一个无头单链表的一个节点前插入一个节点（不能遍历链表）
void LinkListInsertSp(LinkNode** phead, LinkNode* pos, LinkNodeType value){
    if(phead == NULL || pos == NULL){
        return;
    }
    if(*phead == NULL){
        return;
    }
    LinkNode* tmp = CreateNode(pos->data);
    tmp->next = pos->next;
    pos->next = tmp;
    pos->data = value;
    return;
}

//单链表实现约瑟夫环
LinkNode* JoseCycle(LinkNode* phead,size_t food){
    if(phead == NULL){
        return NULL;
    }
    if(food == 0){
        return NULL;
    }
    LinkNode* cur = phead;
    while(cur != cur->next){
        size_t i = 0;
        for(; i < (food - 1); ++i){
            cur = cur->next;
        }
        LinkNode* to_delete = cur->next;
        cur->data = cur->next->data;
        cur->next = cur->next->next;
        free(to_delete);
    }
    return cur;
}

//逆置/反转单链表
void LinkListReverse(LinkNode** phead){
    if(phead == NULL){
        return;
    }
    if(*phead == NULL){
        return;
    }
    if((*phead)->next == NULL){
        return;
    }
    LinkNode* cur = *phead;
    while(cur->next != NULL){
        LinkNode* to_delete = cur->next;
        cur->next = to_delete->next;
        to_delete->next = *phead;
        *phead = to_delete;
    }
    return;
}

//单链表排序

void Swap(LinkNodeType* a,LinkNodeType* b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void LinkListBubble(LinkNode* phead){
    if(phead == NULL){
        return;
    }
    LinkNode* count = phead;
    LinkNode* tail = NULL;
    for(;count != NULL;count = count->next){
        LinkNode* cur = phead;
        for(; cur->next != tail; cur = cur->next){
            if(cur->data > cur->next->data){
                Swap(&(cur->data) , &(cur->next->data));
            }
        }
        tail = cur;
    }
}

//合并两个有序链表
LinkNode* LinkListMerge(LinkNode* phead1,LinkNode* phead2){
    if(phead1 == NULL){
        return phead2;
    }
    if(phead2 == NULL){
        return phead1;
    }
    LinkNode* cur1 = phead1;
    LinkNode* cur2 = phead2;
    LinkNode* new_head = NULL;
    LinkNode* new_tail = NULL;
    while(cur1 != NULL && cur2 != NULL){
        if(cur1->data < cur2->data){
            if(new_head == NULL){
                new_head = new_tail = cur1;
            }
            else{
                new_tail->next = cur1;
                new_tail = new_tail->next;
            }
            cur1 = cur1->next;
        }
        if(cur1->data >= cur2->data){
            if(new_head == NULL){
                new_head = new_tail = cur2;
            }
            else{
                new_tail->next = cur2;
                new_tail = new_tail->next;
            }
            cur2 = cur2->next;
        }
    }

    if(cur1 != NULL){
        new_tail->next = cur1;
    }

    if(cur2 != NULL){
        new_tail->next = cur2;
    }

    return new_head;
}

//找到中间节点
LinkNode* LinkListFindMid(LinkNode* phead){
    if(phead == NULL){
        return NULL;
    }
    LinkNode* fast = phead;
    LinkNode* slow = phead;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//查找单链表倒数第k个节点（要求只能遍历一遍链表)
LinkNode* LinkListFindKth(LinkNode* phead,size_t k){
    LinkNode* fast = phead;
    LinkNode* slow = phead;
    size_t i = 0;
    for(;i < k && fast != NULL;i++){
        fast = fast->next;
    }
    if(i < k){
        return NULL;
    }
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

//删除链表的倒数第k个节点
void LinkListEraseKth(LinkNode** phead,size_t k){
    if(phead == NULL){
        return;
    }
    if(*phead == NULL){
        return;
    }

    size_t size = LinkListSize(*phead);

    if(k > size){
        printf("超出范围，无法删除！\n");
        return;
    }

    LinkNode* pos_k = LinkListFindKth(*phead,k);

    if(pos_k->next != NULL){
        LinkNode* tmp = pos_k->next;
        pos_k->data = pos_k->next->data;
        pos_k->next = tmp->next;
        DestroyNode(tmp);
    }
    else if(pos_k->next == NULL){
        LinkListPopBack(phead);
    }
    return;
}

//判断单链表是否带环，带环返回相遇点的指针
LinkNode* LinkListHasCycle(LinkNode* phead){
    if(phead == NULL){
        return NULL;
    }
    LinkNode* fast = phead;
    LinkNode* slow = phead;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return fast;
        }
    }
    return NULL;
}

//求环的入口点
LinkNode* LinkListCycleEntryPos(LinkNode* phead){
    if(phead == NULL){
        return NULL;
    }
    LinkNode* meet_pos = LinkListHasCycle(phead);
    if(meet_pos == NULL){
        return NULL;
    }
    LinkNode* cur = phead;
    while(cur != meet_pos){
        cur = cur->next;
        meet_pos = meet_pos->next;
    }
    return cur;
}
//若链表带环，求环的长度
size_t LinkListCycleSize(LinkNode* phead){
    LinkNode* meet_pos = LinkListHasCycle(phead);
    if(meet_pos == NULL){
        return 0;
    }
    LinkNode* cur = meet_pos;
    size_t count = 1;
    for(;cur->next != meet_pos;cur = cur->next){
        ++count;
    }
    return count;
}

//判断两个链表是否相交，并求出交点
LinkNode* LinkListHasCyclePos(LinkNode* phead1,LinkNode* phead2){
    if(phead1 == NULL || phead2 == NULL){
        return NULL;
    }
    LinkNode* meet_pos1 = LinkListHasCycle(phead1);
    LinkNode* meet_pos2 = LinkListHasCycle(phead2);
    LinkNode* cur1 = phead1;
    LinkNode* cur2 = phead2;
    if(meet_pos1 == NULL && meet_pos2 == NULL ){
        size_t size1 = LinkListSize(phead1);
        size_t size2 = LinkListSize(phead2);
        size_t offset = 0;
        if(size1 > size2){
            offset = size1 - size2;
            size_t i = 0;
            for(;i < offset;++i){
                cur1 = cur1->next;
            }
            while(cur1 != NULL && cur2 != NULL){
                if(cur1 == cur2){
                    return cur1;
                }
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }else if(size1 <= size2){
            offset = size2 - size1;
            size_t i = 0;
            for(;i < offset; ++i){
                cur2 = cur2->next;
            }
            while(cur1 != NULL && cur2 != NULL){
                cur1 = cur1->next;
                cur2 = cur2->next;
                if(cur1 == cur2){
                    return cur1;
                }
            }
        }
    }

   else if(meet_pos1 != NULL && meet_pos2 != NULL){
        LinkNode* Entry1 = LinkListCycleEntryPos(phead1);
        LinkNode* Entry2 = LinkListCycleEntryPos(phead2);
        size_t offset = 0;
        if(Entry1 == Entry2){
            size_t size1 = 0;
            size_t size2 = 0;
            for(;cur1 != Entry1;cur1 = cur1->next){
                size1++;
            }
            for(;cur2 != Entry2;cur2 = cur2->next){
                size2++;
            }
            cur1 = phead1;
            cur2 = phead2;
            if(size1 >= size2){
                offset = size1 - size2;
                size_t i = 0;
                for(;i < offset;++i){
                    cur1 = cur1->next;
                }
                while(cur1 != Entry1 && cur2 != Entry2){
                    if(cur1->data == cur2->data){
                        return cur1;
                    }
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }
            }else if(size1 < size2){
                offset = size2 - size1;
                size_t i = 0;
                for(;i < offset;++i){
                    cur2 = cur2->next;
                }
                while(cur1 != Entry1 && cur2 != Entry2){
                    if(cur1->data == cur2->data){
                        return cur1;
                    }
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }
            }
        }
        if(Entry1 != Entry2){
            return Entry1;
        }
    }
    else{
        return NULL;
    }
    return NULL;
}

//求两个已排序单链表中相同的数据

LinkNode* UnionSet(LinkNode* phead1,LinkNode* phead2){
    if(phead1 == NULL || phead2 == NULL){
        return NULL;
    }
    LinkNode* cur1 = phead1;
    LinkNode* cur2 = phead2;
    LinkNode* new_head = NULL;
    LinkNode* new_tail = NULL;
    while(cur1 != NULL && cur2 != NULL){
        if(cur1->data > cur2->data){
            cur2 = cur2->next;
        }else if(cur1->data < cur2->data){
            cur1 = cur1->next;
        }else{
            LinkNode* new_node = CreateNode(cur1->data);
            if(new_node == NULL){
               return NULL; 
            }
            if(new_head == NULL){
                new_head = new_tail = new_node;
                cur1 = cur1->next;
                cur2 = cur2->next;
            }else{
                new_tail->next = new_node;
                new_tail = new_tail->next;
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }
    }
    return new_head;
}
