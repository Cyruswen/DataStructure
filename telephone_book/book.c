#include"book.h"

void BookListInit(BookNode** phead){
	if(phead == NULL){
		return;
	}
	*phead = NULL;
}

void Destroynode(BookNode* node){
	free(node);
}

BookNode* CreateMum(char* uname,char* ugender,int uage,char* utelephone,char* uaddress){
	BookNode* new_node = (BookNode*)malloc(sizeof(BookNode));
	if(new_node == NULL){
		return NULL;
	}
	strcpy(new_node->name,uname);
	strcpy(new_node->gender,ugender);
	new_node->age = uage;
	strcpy(new_node->telephone,utelephone);
	strcpy(new_node->address,uaddress);
	new_node->next = NULL;
	return new_node;
}

void BookListPrint(BookNode* head, const char* msg){
	printf("[ %s ]:\n", msg);
	BookNode* cur = head;
	if(cur == NULL){
		printf("电话簿为空！\n");
		return;
	}
	for(;cur != NULL;cur = cur->next){
		printf("name:[ %s ]\ngender:[ %s ]\nage:[ %d ]\ntelephone:[ %s ]\naddress:[ %s ]\n\n",cur->name,cur->gender,cur->age,cur->telephone,cur->address);
	}
	return;
}

void BookListInsert(BookNode** phead,char* name,char* gender,int age,char* telephone,char* address){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		*phead = CreateMum(name,gender,age,telephone,address);
		return;
	}
	BookNode* cur = *phead;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = CreateMum(name,gender,age,telephone,address);
    return;
}

BookNode* BookListFindPos(BookNode* phead, char* to_find){
	if(phead == NULL){
		return NULL;
	}
	BookNode* cur = phead;
	while(cur != NULL){
		if(!strcmp(cur->name,to_find)){
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void BookListErase(BookNode** phead, char* to_delete){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		return;
	}
	BookNode* pos = BookListFindPos(*phead,to_delete);

	if(pos == NULL){
		return;
	}

	if( pos->next != NULL){
		strcpy((pos->name),(pos->next->name));
		strcpy((pos->gender),(pos->next->gender));
		strcpy((pos->telephone),(pos->next->telephone));
		strcpy((pos->address),(pos->next->address));
        pos->age = pos->next->age;
		BookNode* cur = pos->next;
		pos->next = pos->next->next;
		Destroynode(cur);
		cur = NULL;
		return;
	}
	if(pos->next == NULL){
		BookNode* cur = *phead;
		while(cur->next != pos){
			cur = cur->next;
		}
		Destroynode(pos);
		cur->next = NULL;
		return;
	}
}

void BookListFind(BookNode* phead, char* to_find){
	if(phead == NULL){
		return;
	}
	BookNode* cur = phead;
	while(cur != NULL){
		if(!strcmp((cur->name),to_find)){
			printf("name:[ %s ]\ngender:[ %s ]\nage:[ %d ]\ntelephone:[ %s ]\naddress:[ %s ]\n\n",cur->name,cur->gender,cur->age,cur->telephone,cur->address);
			return;
		}
		cur = cur->next;
	}
	printf("[ 抱歉，没有找到联系人！ ]\n");
	return;
}

void BookListDestroy(BookNode** phead){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		printf("[ 电话本为空，无法删除! ]\n");
		return;
	}

	while((*phead)!= NULL){
		BookNode* cur = *phead;
		Destroynode(cur);
		(*phead) = (*phead)->next;
	}
	return;
}

void BookListChange(BookNode** phead,char* to_change,int flag,char* newmsg){
	if(phead == NULL){
		return;
	}
	if(*phead == NULL){
		return;
	}
	BookNode* pos = BookListFindPos(*phead, to_change);
	
	if(pos == NULL){
		return;
	}

	switch(flag){
		case 1:
			strcpy((pos->name),newmsg);
			break;
		case 2:
			pos->age = atoi(newmsg);
			break;
		case 3:
			strcpy(pos->telephone,newmsg);
			break;
		case 4:
			strcpy(pos->address,newmsg);
			break;
	}
	return;
}

void TelephoneBookMenu(){
	printf("************************************************************\n");
	printf("******************* 凯凯的电话本 ***************************\n");
	printf("************************************************************\n");
	printf("****** 1.添加联系人 ************* 2.删除联系人 *************\n");
	printf("************************************************************\n");
	printf("****** 3.修改联系人 ************* 4.查找联系人 *************\n");
	printf("************************************************************\n");
	printf("****** 5.查看所有联系人 ********* 6.清空所有联系人 *********\n");
	printf("************************************************************\n");
	printf("********************************************* 0.退出 *******\n");
	printf("************************************************************\n");
}
