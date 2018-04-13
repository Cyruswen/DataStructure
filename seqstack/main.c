#include"seqstack.h"

void TestSeqStackInit(){
    TestType;
    SeqStack stack;
    SeqStackInit(&stack);
    SeqStackPrint(&stack,"初始化栈");
}

void TestSeqStackReSize(){
    TestType;
    SeqStack stack;
    SeqStackInit(&stack);
    printf("扩容之前：%zu\n",stack.capacity);
    stack.size = 1001;
    SeqStackReSize(&stack);
    printf("扩容之后：%zu\n",stack.capacity);
    return;
}

void TestSeqStackPush(){
    TestType;
    SeqStack stack;
    SeqStackInit(&stack);
    SeqStackPush(&stack, 'a');
    SeqStackPush(&stack, 'b');
    SeqStackPush(&stack, 'c');
    SeqStackPush(&stack, 'd');
    SeqStackPrint(&stack, "abcd入栈");
    return;
}

void TestSeqStackPop(){
    TestType;
    SeqStack stack;
    SeqStackInit(&stack);
    SeqStackPush(&stack, 'a');
    SeqStackPush(&stack, 'b');
    SeqStackPush(&stack, 'c');
    SeqStackPush(&stack, 'd');
    SeqStackPrint(&stack, "abcd入栈");
    SeqStackPop(&stack);
    SeqStackPrint(&stack, "d 出栈");
    SeqStackPop(&stack);
    SeqStackPrint(&stack, "c 出栈");
}

void TestSeqStackDestroy(){
    TestType;
    SeqStack stack;
    SeqStackInit(&stack);
    SeqStackPush(&stack, 'a');
    SeqStackPush(&stack, 'b');
    SeqStackPush(&stack, 'c');
    SeqStackPush(&stack, 'd');
    SeqStackPrint(&stack, "abcd入栈");
    SeqStackDestroy(&stack);
    SeqStackPrint(&stack, "销毁栈结构");
    return;
}

void TestSeqStackGetFront(){
    TestType;
    SeqStack stack;
    SeqStackType value;
    int result;
    SeqStackInit(&stack);
    SeqStackPush(&stack, 'a');
    SeqStackPush(&stack, 'b');
    SeqStackPush(&stack, 'c');
    SeqStackPush(&stack, 'd');
    SeqStackPush(&stack, 'e');
    SeqStackPrint(&stack, "abcd入栈");
    result = SeqStackGetFront(&stack,&value);
    printf("expect:1,actual:%d\n",result);
    printf("expect:e,actual：%c\n",value);
    SeqStackPop(&stack);
    result = SeqStackGetFront(&stack,&value);
    printf("expect:1,actual:%d\n",result);
    printf("expect:d,actual：%c\n",value);
    SeqStackPop(&stack);
    return;
}

int main(){
    TestSeqStackInit();
    TestSeqStackReSize();
    TestSeqStackPush();
    TestSeqStackPop();
    TestSeqStackDestroy();
    TestSeqStackGetFront();
    return 0;
}
