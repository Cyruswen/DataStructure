#pragma
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define MaxNum 1000

#define TestType printf("\n################################# %s #############################\n",__FUNCTION__)
typedef struct BookNode{
	char name[20];
	char gender[8];
	int age;
	char telephone[20];
	char address[100];
	struct BookNode* next;
} BookNode;

void BookListInit(BookNode** phead);

void BookListPrint(BookNode* head, const char* msg);

void BookListInsert(BookNode** phead,char* name,char* gender,int age,char* telephone,char* address);

BookNode* BookListFindPos(BookNode* phead, char* to_find);

void BookListErase(BookNode** phead, char* to_delete);

void BookListFind(BookNode* phead, char* to_find);

void BookListDestroy(BookNode** phead);

void BookListChange(BookNode** phead, char* to_change, int flag, char* newmsg);

void TelephoneBookMenu();
