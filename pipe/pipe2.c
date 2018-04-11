#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(){
	int pipefd[2];
	if(pipe(pipefd) == -1){
		ERR_EXIT("pipe error");
	}
	
	pid_t pid;
	pid = fork();
	if(pid == -1){
		ERR_EXIT("fork error");
	}
	if(pid == 0){
		close(pipefd[0]);
		while(1){
		write(pipefd[1], "hello RaoJie and JiangSiSi",30);
		sleep(2);
		}
	//	close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);
	char buf[30] = {0};
	while(1){
		read(pipefd[0],buf,30);
		printf("buf = %s\n",buf);
	}
	return 0;
}
