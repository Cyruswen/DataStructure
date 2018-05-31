#include "hash2.h"
#include <stdio.h>

size_t HashFuncDefault(KeyType key){
    return key % HASHMAXSIZE;
}

void TestHashInit(){
    TestType;
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    printf("func expected %p, actuall %p\n", HashFuncDefault, ht.func);
    printf("size expected 0, actuall %lu\n",ht.size);
    return;
}

int main(){
    TestHashInit();
    return 0;
}
