#include"linkstack.h"

void TestLinkStackPush(){
    TestType;
    LinkStack q;
    LinkStackInit(&q);
    LinkStackPush(&q,'a');
    LinkStackPush(&q,'b');
    LinkStackPush(&q,'c');
    LinkStackPush(&q,'d');
    LinkStackPush(&q,'e');
    LinkStackPrint(&q,"abcde入栈");
    return;
}

void TestLinkStackPop(){
    TestType;
    LinkStack q;
    LinkStackInit(&q);
    LinkStackPush(&q,'a');
    LinkStackPush(&q,'b');
    LinkStackPush(&q,'c');
    LinkStackPush(&q,'d');
    LinkStackPush(&q,'e');
    LinkStackPrint(&q,"abcde入栈");
    LinkStackPop(&q);
    LinkStackPrint(&q,"e出栈");
    LinkStackPop(&q);
    LinkStackPrint(&q,"d出栈");
    return;
}

void TestLinkStackFront(){
    TestType;
    LinkStack q;
    LinkStackType value;
    LinkStackInit(&q);
    LinkStackPush(&q,'a');
    LinkStackPush(&q,'b');
    LinkStackPush(&q,'c');
    LinkStackPush(&q,'d');
    LinkStackPush(&q,'e');
    LinkStackPrint(&q,"abcde入栈");
    int ret = LinkStackFront(&q,&value);
    printf("expect: 1, actual: %d\n",ret);
    printf("expext: e, actual: %c\n",value);
    LinkStackPop(&q);
    ret = LinkStackFront(&q,&value);
    printf("expect: 1, actual: %d\n",ret);
    printf("expext: d, actual: %c\n",value);
    return;
}

//最小栈

void TestMinStackPush(){
    TestType;
    LinkStack q;
    LinkStackType value;
    LinkStackInit(&q);
    MinStackPush(&q,'2');
    int ret = MinStack(&q,&value);
    printf("ret expect:1, actual:%d\n",ret);
    printf("value expect:2, actual:%c\n",value);
    MinStackPush(&q,'4');
    LinkStackPrint(&q,"最小栈入栈");
    ret = MinStack(&q,&value);
    printf("ret expect:1, actual:%d\n",ret);
    printf("value expect:2, actual:%c\n",value);
    MinStackPush(&q,'1');
    LinkStackPrint(&q,"最小栈入栈");
    ret = MinStack(&q,&value);
    printf("ret expect:1, actual:%d\n",ret);
    printf("value expect:1, actual:%c\n",value);
    MinStackPush(&q,'6');
    LinkStackPrint(&q,"最小栈入栈");
    ret = MinStack(&q,&value);
    printf("ret expect:1, actual:%d\n",ret);
    printf("value expect:1, actual:%c\n",value);
    LinkStackPrint(&q,"最小栈入栈");
    return;
}

void TestMinStackPop(){
    TestType;
    LinkStack q;
    LinkStackType value;
    LinkStackInit(&q);
    MinStackPush(&q,'2');
    int ret = MinStack(&q,&value);
    printf("ret expect:1, actual:%d\n",ret);
    printf("value expect:2, actual:%c\n",value);
    MinStackPush(&q,'4');
    ret = MinStack(&q,&value);
    printf("ret expect:1, actual:%d\n",ret);
    printf("value expect:2, actual:%c\n",value);
    MinStackPush(&q,'1');
    MinStackPop(&q);
    ret = MinStack(&q,&value);
    printf("ret expect:1, actual:%d\n",ret);
    printf("value expect:2, actual:%c\n",value);
    MinStackPush(&q,'6');
    ret = MinStack(&q,&value);
    printf("ret expect:1, actual:%d\n",ret);
    printf("value expect:2, actual:%c\n",value);
    LinkStackPrint(&q,"最小栈入栈");
    return;
}

int main(){
   // TestLinkStackPush();
   // TestLinkStackPop();
   // TestLinkStackFront();
   // return 0;
   TestMinStackPush();
   TestMinStackPop();
   return 0;
}
