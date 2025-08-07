#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>


void gogo1(int num){
	
	printf("[BUtton Clicked]");


}


void gogo2(int num)
{

	
	system("clear");
	printf("REST\n");

}	

void gogo3(int num)
{
	
	printf("BYE\n");
	exit(1);
}



int main()
{

	signal(SIGUSR1, gogo1);
	signal(SIGUSR2, gogo2);
	signal(SIGTERM, gogo3);


	int cnt = 0;

	while(1)
	{
		for(int i = 'A'; i <= 'Z'; i++){
			printf("%c\n", i);	
			sleep(1);
		}

		for(int i = 'Z'; i>= 'A'; i--)
		{
			printf("%c\n", i);
			sleep(1);
		}

	}


}


