#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *fun(void *idx)
{

	int num = *(int*)idx;

	if(num == 1)
		printf("ABC\n");
	else if(num == 2)
		printf("MINMIN\n");
	else if(num == 3)
		printf("COCO\n");
	else if(num == 4)
		printf("KFCKFC\n");

}



int main()
{

	pthread_t tid[4];
	int id[4];

	for(int i = 1; i <= 4; i++)
	{
		id[i - 1] = i;
		pthread_create(&tid[i - 1], NULL, fun, &id[i - 1]);
	}
	
	for(int i = 0; i < 4; i++)
	{
	
		pthread_join(tid[i], NULL);
	
	}


}
