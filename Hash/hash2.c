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

void HashInsert(HashTable* ht, KeyType key, ValType value){
    if(ht == NULL){
        return;
    }
    //根据key算出offset
    size_t offset = ht->func(key);
    HashElem* ret = HashBucketFind(ht->data[offset], key);
    if(ret != NULL){
        //返回值不为空，表示已经有key
        return;
    }

    HashElem* new_node = CreateHashElem(key, value);
    new_node->next = ht->data[offset]->next;
    ht->data[offset] = new_node;
    ht->size++;
    return;
}

int HashFind(HashTable* ht, KeyType key, ValType* value){
    if(ht == NULL || value == NULL){
        return -1;
    }
    size_t offset = ht->func(key);
    HashElem* ret = HashBucketFind(ht->data[offset], key);
    if(ret == NULL){
        return 0;
    }
    *value = ret->value;
    return 1;
}

int HashSize(HashTable* ht){
    if(ht == NULL){
        return 0;
    }
    return ht->size;
}

int HashBucketFindEx(HashElem* head, KeyType to_find, HashElem** pre_node, HashElem** cur_node){
    HashElem* pre = NULL;
    HashElem* cur = head;
    for(;cur != NULL; pre = cur, cur = cur->next){
        if(cur->key == to_find){
            break;
        }
    }
    if(cur == NULL){
        return 0;
    }
    *cur_node = cur;
    *pre_node = pre;
    return 1;
}

void HashRemove(HashTable* ht, KeyType key){
    if(ht == NULL){
        return;
    }
    if(ht->size == 0){
        return;
    }
    size_t offset = ht->func(key);
    HashElem* pre = NULL;
    HashElem* cur = NULL;
    int ret = HashBucketFindEx(ht->data[offset], key, &pre, &cur);
    if(ret == 0){
        return;
    }
    if(pre == NULL){
        ht->data[offset] = cur->next;
    }else{
        pre->next = cur->next;
    }
    DestroyHashElem(cur);
    ht->size--;
    return;
}

void HashPrint(HashTable* ht,const char* msg){
    if(ht == NULL){
        return;
    }
    printf("[%s:]\n",msg);
    size_t i = 0;
    for(; i < HASHMAXSIZE; ++i){
        if(ht->data[i] == NULL){
            continue;
        }
        printf("%lu\n",i);
        HashElem* cur = ht->data[i];
        for(;cur != NULL; cur = cur->next){
            printf("[%d:%d] ", cur->key, cur->value);
        }
        printf("\n");
    }
    return;
}
