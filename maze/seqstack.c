#include"seqstack.h"

void SeqStackInit(SeqStack* stack){
    if(stack == NULL){
        return;
    }
    stack->size = 0;
    stack->capacity = 1000;
    stack->data = (SeqStackType*)malloc(stack->capacity * sizeof(SeqStackType));
    return;
}

void SeqStackPrint(SeqStack* stack, const char* msg){
    if(stack == NULL){
        return;
    }
    printf("[ %s ]:\n",msg);
    size_t i = 0;
    for(;i < stack->size;i++){
        printf("%d %d\t ",stack->data[i].row, stack->data[i].col);
    }
    printf("\n");
    return;
}

void SeqStackReSize(SeqStack* stack){
    if(stack == NULL){
        return;
    }
    if(stack->size < stack->capacity){
        return;
    }
    stack->capacity = stack->capacity * 2 + 1;
    SeqStackType* new_ptr = (SeqStackType*)malloc(stack->capacity * sizeof(SeqStackType));
    size_t i = 0;
    for(;i < stack->size;++i){
        new_ptr[i] = stack->data[i];
    }
    free(stack->data);
    stack->data = new_ptr;
    return;
}

void SeqStackPush(SeqStack* stack,SeqStackType value){
    if(stack == NULL){
        return;
    }
    if(stack->size > stack->capacity){
        SeqStackReSize(stack);
    }
    stack->data[stack->size++] = value;
    return;
}

void SeqStackPop(SeqStack* stack){
    if(stack == NULL){
        return;
    }
    if(stack->size == 0){
        return;
    }
    stack->size--;
    return;
}

void SeqStackDestroy(SeqStack* stack){
    if(stack == NULL){
        return;
    }
    free(stack->data);
    stack->capacity = 0;
    stack->size = 0;
    return;
}

int SeqStackGetFront(SeqStack* stack,SeqStackType* value){
    if(stack == NULL){
        return 0;
    }
    *value = stack->data[stack->size -1];
    return 1;
}

int SeqStackSize(SeqStack* stack){
    if(stack == NULL){
        return -1;
    }
    return stack->size;
}

void SeqStackAssign(SeqStack* from, SeqStack* to){
    if(from == NULL || to == NULL){
        return;
    }
    to->size = from->size;
    to->capacity = from->size;
    size_t i = 0;
    for(; i < to->size; i++){
        to->data[i] = from->data[i];
    }
    return;
}
