#include "hash1.h"
#include <stdio.h>
#include <stddef.h>


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
            //线性探测找到下一个有效位置
            offset++;
            if(offset > HashMaxSize){
                offset = 0;
            }
        }
    }
    return;
}

int HashFind(HashTable* ht, KeyType key, ValType* value){
    if(ht == NULL){
        return 0;
    }
    if(ht->size == 0){
        return 0;
    }
    size_t offset = ht->func(key);
    while(1){
        if(ht->data[offset].key == key && ht->data[offset].stat == Valid){
            *value = ht->data[offset].value;
            return 1;
        }else if(ht->data[offset].stat == Empty){
            return 0;
        }else{
            ++offset;
            offset = offset > HashMaxSize ? 0 : offset;
        }
    }
    return 0;
}

void HashRemove(HashTable* ht, KeyType key){
    if(ht == NULL){
        return;
    }
    if(ht->size == 0){
        //空的哈希表
        return;
    }
    size_t offset = ht->func(key);
    while(1){
        if(ht->data[offset].key == key && ht->data[offset].stat == Valid){
            ht->data[offset].stat = Deleted;
            --ht->size;
            return;
        }else if(ht->data[offset].stat == Empty){
            //如果当前状态为空，表示查找失败
            return;
        }else{
            //线性地向下探测
            ++offset;
            offset = offset > HashMaxSize ? 0 : offset;
        }
    }
}

void HashPrnit(HashTable* ht, const char* message){
    if(ht == NULL || message == NULL){
        return;
    }
    printf("[%s]\n", message);
    size_t i = 0;
    for(;i <= ht->size; i++){
        if(ht->data[i].stat == Empty){
            continue;
        }
        printf("[%lu, %d : %d]\n", i, ht->data[i].key, ht->data[i].value);
    }
    return;
}
