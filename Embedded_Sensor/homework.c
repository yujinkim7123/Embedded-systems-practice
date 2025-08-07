/*
 * helloworld.c
 *
 *  Created on: 2022. 9. 23.
 *      Author: SSAFY
 */
#include<stdio.h>
int main(){
/*

	char *p[3] = {"abc", "dbf", "hig"};

	p[0][0] = 'c';

*/

	char *p1[2] = {"kfc world", "david"};
	char p2[2][10] = {"kfc world", "david"};

	for(int i =0 ;i < 2; i++)
	{
		printf("%s\n", *(p1+i));
		printf("%s\n", p1[i]);
	}

	for(int i =0 ;i < 2; i++)
	{
		printf("%s\n", *(p2+i));
		printf("%s\n", p2[i]);
	}



}
