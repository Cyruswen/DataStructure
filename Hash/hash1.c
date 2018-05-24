#include "hash1.h"
#include <stdio.h>
#include <stddef.h>

size_t HashFuncDefault(KeyType key){
    return key % HashMaxSize;
}

void HashInit(HashTable* ht, HashFunc hash_func){
    if(ht == NULL){
        return;
    }
    ht->size = 0;
    ht->func = hash_func;
    size_t i = 0;
    for(; i < HashMaxSize; ++i){
        ht->data[i].stat = Empty; 
    }
    return;
}

void HashDestroy(HashTable* ht){
    if(ht == NULL){
        return;
    }
    ht->size = 0;
    ht->func = NULL;
    size_t i = 0;
    for(; i < HashMaxSize; i++){
        ht->data[i].stat = Empty;
    }        
    return;
}

void HashInsert(HashTable* ht, KeyType key, ValType value){
    if(ht == NULL){
        return;
    }

    //设置负载因子为0.8
    if(ht->size >= 0.8 * HashMaxSize){
        //表示大于负载因上限
        return;
    }

    size_t offset = ht->func(key);
    while(1){
        if(ht->data[offset].stat != Valid){
            ht->data[offset].key = key;
            ht->data[offset].stat = Valid;
            ht->data[offset].value = value;
            ++ht->size;
        }else if(ht->data[offset].stat == Valid && ht->data[offset].key == key){
            //如果遇到key值相同的，插入失败
            return;
        }else{
            offset++;
            if(offset > HashMaxSize){
                offset = 0;
            }
        }
    }
    return;
}
