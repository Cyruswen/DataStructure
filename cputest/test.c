#include <stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int count = 0;
void handler(int signo){
    printf("get 14 signo,%d\n",count);
    exit(0);
}
int main(){
    signal(14,handler);
    alarm(1);
    while(1){
    //    printf("hello world!\n");
        count++;
    }
}
