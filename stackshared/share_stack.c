#include"share_stack.h"

void ShareStackInit(ShareStack* stack){
    if(stack == NULL){
        return;
    }
    stack->top1 = 0;
    stack->top2 = ShareStackMaxSize;
    return;
}

void ShareStackPush1(ShareStack* stack, ShareStackType value){
    if(stack == NULL){
        return;
    }
    if(stack->top1 >= stack->top2){
        //栈满
        return;
    }
    stack->data[stack->top1++] = value;
    return;
}

void ShareStackPush2(ShareStack* stack,ShareStackType value ){
    if(stack == NULL){
        return;
    }
    if(stack->top1 >= stack->top2){
        return;
    }
    stack->data[--stack->top2] = value;
    return;
}

void ShareStackPop1(ShareStack* stack){
    if(stack == NULL){
        //非法输入
        return;
    }
    if(stack->top1 == 0){
        //空栈
        return;
    }
    --stack->top1;
    return;
}

void ShareStackPop2(ShareStack* stack){
    if(stack == NULL){
        //非法输入
        return;
    }
    if(stack->top2 == ShareStackMaxSize){
        //空栈
        return;
    }
    ++stack->top2;
}

int ShareStackTop1(ShareStack* stack, ShareStackType* value){
    if(stack == NULL || value == NULL){
        return 0;
    }
    if(stack->top1 == 0){
        return 0;
    }
    *value = stack->data[--stack->top1];
    return 1;
}

int ShareStackTop2(ShareStack* stack, ShareStackType* value){
    if(stack == NULL || value == NULL){
        return 0;
    }
    if(stack->top2 == ShareStackMaxSize){
        return 0;
    }
    *value = stack->data[stack->top2];
    return 1;
}
