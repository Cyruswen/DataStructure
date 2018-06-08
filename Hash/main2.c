#include "hash2.h"
#include <stdio.h>


void TestHashInit(){
    TestType;
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    printf("func expected %p, actual %p\n", HashFuncDefault, ht.func);
    printf("size expected 0, actual %lu\n",ht.size);
    return;
}

void TestHashDestroy(){
    TestType;
    HashTable ht;
    HashDestroy(&ht);
    printf("func expected NULL, actual %p\n", ht.func);
    printf("size expected 0, actuall %lu\n",ht.size);
    return;
}

void TestHashInsert(){
    TestType;
    HashTable ht;
    HashInit(&ht, HashFuncDefault);
    HashInsert(&ht, 2, 10);
    HashInsert(&ht, 10, 13);
    HashInsert(&ht, 12, 14);
    HashInsert(&ht, 13, 15);
    HashPrint(&ht, "打印哈希表");
    return;
}

void TestHashFind(){
    TestType;
    HashTable ht;
    HashInit(&ht, HashFuncDefault);
    HashInsert(&ht, 2, 10);
    HashInsert(&ht, 10, 13);
    HashInsert(&ht, 12, 14);
    HashInsert(&ht, 13, 15);
    int Val;
    int ret = HashFind(&ht,13, &Val );
    printf("ret expect 1, actual %d\n", ret);
    printf("value expect 15, actual %d\n", Val);
    return;
}

void TestHashRemove(){
    HashTable ht;
    HashInit(&ht, HashFuncDefault);
    HashInsert(&ht, 2, 10);
    HashInsert(&ht, 10, 13);
    HashInsert(&ht, 12, 14);
    HashInsert(&ht, 13, 15);
    HashPrint(&ht, "删除前");
    HashRemove(&ht,12);
    HashPrint(&ht, "删除后");
    return;
}

int main(){
    TestHashInit();
    TestHashDestroy();
    TestHashInsert();
    TestHashFind();
    TestHashRemove();
    return 0;
}
