#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>


int main(int argc, char *argv[])
{

	if(argc != 2)
	{
		printf("ERROR\n");
		return 0;
	
	}


	int pid = atoi(argv[1]);
	printf("%d", pid);

	int num = 0;

	while(1){

	scanf("%d", &num);

	if(num == 1)
		kill(pid, SIGUSR1);
	else if(num == 2)
		kill(pid, SIGUSR2);
	else if(num == 3)
		kill(pid, SIGTERM);
	
	}

}

