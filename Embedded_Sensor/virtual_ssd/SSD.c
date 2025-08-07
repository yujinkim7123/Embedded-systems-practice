#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	FILE *fp = fopen("nand.txt", "r+");
	for(int i =0 ; i < 100; i++)
	{
		fwrite("0x00000000", 10, 1, fp);

	}
	fclose(fp);


	char line[50];

	while(1){

	char *p;
	printf(" SHELL >> ");
	fflush(stdout);
	//fputs(" SHELL >> ", stdout);
	fgets(line, 100, stdin);
	p = strtok(line, "\n");
	p = strtok(p, " ");

	if(strcmp(p, "write") == 0)
	{

		p = strtok(NULL, " ");

		int number = atoi(p);

		if(number > 99 || number < 0)
		{
			printf("Index Format Wrong\n");
			continue;
		}

		p = strtok(NULL, " ");
		int check = 0;

		for(int i = 2; i < 10; i++)
		{
			//printf("%c", p[i]);

			if((p[i] >= '0' && p[i] <= '9') || (p[i] >= 'A' && p[i] <= 'F'))continue;
			else{
				check = 1;
				break;
			}
		}

		if(check == 1)
		{

			printf("16 Format Wrong\n");
						continue;
		}

		FILE * fp = fopen("nand.txt", "r+");
		fseek(fp, 10*number - 10, SEEK_SET);

		fwrite(p, strlen(p), 1, fp);
		fclose(fp);
	}
	else if(strcmp(p, "read") == 0)
	{
		p = strtok(NULL, " ");

		char ans[11];

		int number = atoi(p);


		if(number > 99 || number < 0)
		{
			printf("Format Wrong\n");
			continue;
		}

		FILE *fp1 = fopen("result.txt", "r+");
		FILE *fp2 = fopen("nand.txt", "r+");


		fseek(fp2, number*10 - 10, SEEK_SET);
		fread(ans, 10, 1, fp2);
		ans[10] = '\0';
		fwrite(ans, strlen(ans), 1 , fp1);

		fclose(fp1);

		char res[11];

		fp1 = fopen("result.txt", "r");
		fread(res, 10, 1, fp1);

		res[10] = '\0';

		printf("%s \n", res);

		fclose(fp1);
		fclose(fp2);


	}
	else if(strcmp(p , "fullread")== 0)
	{

		FILE *fp1 = fopen("nand.txt", "r+");
		FILE *fp2 = fopen("result.txt", "r+");

		for(int i =0 ; i < 100; i++)
		{
			char ans[11];
			fread(ans, 10, 1, fp1);
			ans[10] ='\0';
			fseek(fp2, i*10, SEEK_SET);
			fwrite(ans, strlen(ans), 1, fp2);
			printf("%s \n", ans);

		}

		fclose(fp1);
		fclose(fp2);

	}
	else if(strcmp(p, "fullwrite") == 0)
	{
		p = strtok(NULL, " ");

		int check =0 ;
		for(int i = 2; i < 10; i++)
		{
					//printf("%c", p[i]);

			if((p[i] >= '0' && p[i] <= '9') || (p[i] >= 'A' && p[i] <= 'F'))continue;
			else{
				check = 1;
				break;
			}
		}

		if(check == 1)
		{

			printf("16 Format Wrong\n");
					continue;
		}


		FILE *fp = fopen("nand.txt", "r+");

		for(int i =0 ; i < 100; i++)
		{

			fseek(fp, i*10, SEEK_SET);
			fwrite(p, strlen(p), 1 , fp);

		}

		fclose(fp);

	}
	else if(strcmp(p, "exit") == 0)
	{
		printf("SHELL EXIT\n");
		break;
	}
	else if(strcmp(p, "help") == 0)
	{
		printf("read : page 22p \n");
		printf("write : page 22p \n");
		printf("fullwrite : page 24p \n");
		printf("fullread : page 24p \n");
		printf("exit : exit 치고 나가세요 \n");
		printf("help : 명령서 사전 \n");
		printf("testapp1 : page 28p \n");
		printf("testapp2 : page 29p \n");
	}
	else if(strcmp(p, "testapp1") == 0)
	{
		char * copy;
		printf(" fullwrite 수행을 위해 원하는 단어를 입력하세요 >> ");
		fflush(stdout);
		fgets(line, 100, stdin);
		copy = strtok(line, "\n");

		int check = 0;
		for(int i = 2; i < 10; i++)
		{
			if((copy[i] >= '0' && copy[i] <= '9') || (copy[i] >= 'A' && copy[i] <= 'F'))continue;
			else{
				check = 1;
				break;
			}
		}

		if(check == 1)
		{
			printf("Format Wrong\n");
			continue;
		}

		FILE *fp = fopen("nand.txt", "r+");

		for(int i =0 ; i < 100; i++)
		{

			fseek(fp, i * 10, SEEK_SET);
			fwrite(copy, strlen(copy), 1 , fp);

		}

		fclose(fp);

		FILE *fp1 = fopen("nand.txt", "r+");
		FILE *fp2 = fopen("result.txt", "r+");

		for(int i = 0; i < 100; i++)
		{
			char ans[11];
			fread(ans, 10 , 1, fp1);
			ans[10] ='\0';
			fseek(fp2, i*10, SEEK_SET);
			fwrite(ans, strlen(ans), 1, fp2);
			printf("%s \n", ans);

		}

		fclose(fp1);
		fclose(fp2);

		printf("정상 동작을 확인하였습니다. 메일로 알아서 문제가 있는 경우 오류 메시지를 보내세요\n");

	}
	else if(strcmp(p, "testapp2") == 0)
	{
		FILE *fp = fopen("nand.txt", "r+");

		for(int j=0 ; j < 30; j++){
			for(int i = 0; i < 5; i++)
			{
				fseek(fp, i*10, SEEK_SET);
				fwrite("0xAAAABBBB", 10 , 1, fp);
			}
		}
		for(int i =0 ; i < 5; i++)
		{

			fseek(fp, i*10, SEEK_SET);
			fwrite("0x12345678", 10 , 1, fp);

		}

		fclose(fp);

		FILE *fp1 = fopen("nand.txt", "r+");
		FILE *fp2 = fopen("result.txt", "r+");

		for(int i =0 ; i < 5; i++)
		{
			char ans[11];
			fread(ans, 10 , 1, fp1);
			ans[10] ='\0';
			fseek(fp2, i*10, SEEK_SET);
			fwrite(ans, strlen(ans), 1, fp2);
			printf("%s \n", ans);

		}

		fclose(fp1);
		fclose(fp2);

	}
	else
		printf("INVALID COMMAND\n");

   }
}
