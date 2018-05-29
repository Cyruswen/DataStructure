#include "hash1.h"
#include <stdio.h>

size_t HashFuncDefault(KeyType key){
    return key % HashMaxSize;
}

void TestInit(){
    TestType;
    HashTable ht;
    HashInit(&ht, HashFuncDefault);
    printf("size expected 0, actual %lu\n", ht.size);
    printf("func expected %p, actual %p\n", HashFuncDefault, ht.func);
    return;
}

void TestHashDestroy(){
    TestType;
    HashTable ht;
    HashInit(&ht, HashFuncDefault);
    HashDestroy(&ht);
    printf("size expected 0, actual %lu\n", ht.size);
    printf("func expected NULL, actual %p\n",ht.func);
    return;
}

void TestHashRemove(){
    TestType;
    HashTable ht;
    HashInit(&ht, HashFuncDefault);
    HashInsert(&ht, 1, 1);
    HashInsert(&ht, 2, 2);
    HashInsert(&ht, 1001, 11);
    HashPrnit(&ht, "删除前");
    HashRemove(&ht, 1001);
    HashPrnit(&ht, "删除后");
    return;
}

void TestHashInsert(){
    TestType;
    HashTable ht;
    HashInit(&ht, HashFuncDefault);
    HashInsert(&ht, 1, 1);
    HashInsert(&ht, 1, 10);
    HashInsert(&ht, 2, 2);
    HashInsert(&ht, 1001, 11);
    HashInsert(&ht, 1002, 12);
    HashPrnit(&ht, "插入元素");
    return;
}

void TestFind(){
    TestType;
    HashTable ht;
    HashInit(&ht, HashFuncDefault);
    HashInsert(&ht, 1, 1);
    HashInsert(&ht, 1, 10);
    HashInsert(&ht, 2, 2);
    HashInsert(&ht, 1001, 11);
    HashInsert(&ht, 1002, 12);
    int value = 0;
    int ret = HashFind(&ht, 1002, &value);
    printf("ret expected is 1, actual %d\n", ret);
    printf("value epected is 12, actual %d\n", value);
    return;
}

int main(){
    TestInit();
    TestHashDestroy();
    TestHashInsert();
    TestFind();
    TestHashRemove();
    return 0;
}
