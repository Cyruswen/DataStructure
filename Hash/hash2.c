#include "hash2.h"

HashElem* CreateHashElem(KeyType key, ValType value){
    HashElem* new_node = (HashElem*)sizeof(HashElem);
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

size_t HashFuncDefault(KeyType key){
    return key % HASHMAXSIZE;
}

void DestroyHashElem(HashElem* hash){
    free(hash);
    return;
}

void HashInit(HashTable* ht, HashFunc HashFuncDefault){
    if(ht == NULL){
        return;
    }
    ht->func = HashFuncDefault;
    ht->size = 0;
    size_t i = 0;
    for(;i < HASHMAXSIZE; i++){
        ht->data[i] = NULL;
    }
    return;
}

void HashInit(HashTable* ht){
    if(ht == NULL){
        return;
    }
    ht->func = NULL;
    ht->size = 0;
    size_t i = 0;
    for(; i < HASHMAXSIZE; i++){
        HashElem* cur = ht->data[i];
        while(cur != NULL){
            HashElem* tmp = cur;
            cur = cur->next;
            DestroyHashElem(tmp);
            tmp = NULL;
        }
    }
}

HashElem* HashBucketFind(HashElem* Elem, KeyType to_find){
    if(Elem == NULL){
        return NULL;
    }

    HashElem* cur = Elem;
    for(; cur != NULL; cur = cur->next){
        if(cur->key == to_find){
            break;
        }
    }
    return cur == NULL ? NULL : cur;
}
