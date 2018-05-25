#include <stdio.h>
#include "hash1.h"

size_t HashFuncDefault(KeyType key){
    return key % HashMaxSize;
}

void TestInit(){
    TestType;
    HashTable ht;
    HashInit(&ht, HashFuncDefault);
    printf("size expected 0, actual %lu\n", ht.size);
    printf("func expected %p, actual %p\n", HashFuncDefault, ht.func);
}

int main(){
    TestInit();
    return 0;
}
