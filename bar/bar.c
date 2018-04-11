#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int i = 0;
	int j = 0;
	char bar[102];

	int color[] = {1,2,3,4,5,6,7};
	const char* status = "|/-\\";
	memset(bar,0,sizeof(bar));
	while(i <= 100){
		printf("\033[3%dm[%-100s]\033[0m\033[33m[%d%%]\033[0m[%c]\r",color[j],bar,i,status[i%4]);
		fflush(stdout);
		bar[i++] = '#';

		if(i%15 == 0){
			++j;
		}
		usleep(30000);
	}
	printf("\n");
	return 0;
}
