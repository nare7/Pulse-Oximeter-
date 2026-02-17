//string library functions
#include <stdio.h>
#include <string.h>

void main()
{
	char *k;
	

/*	
	//find length 
	char str1[]= {"sai srinivas"};
	k= strlen(str1);
	printf("%d", k);
*/


	
	//string compare1
/*	
	char str1[]= {"sai"};
	char str2[]= {"sai"};
	k= strcmp(str1, str2);
	printf("k value is %d\n", k);
	if(k==0)
	{
		printf("both strings are same\n");
	}
	else if(k>0)
	{
		printf("%s is bigger than %s", str1, str2);
	}
	else
	{
		
		printf("%s is smaller than %s", str1, str2);
	}

*/



	//string compare2	
/*
	char str1[]= {"sai "};
	char str2[]= {"saib"};
	k= strcmp(str1, str2);
	printf("k value is %d\n", k);
	if(k==0)
	{
		printf("both strings are same\n");
	}
	else if(k>0)
	{
		printf("%s is bigger than %s", str1, str2);
	}
	else
	{
		
		printf("%s is smaller than %s", str1, str2);
	}

*/


	//string compare3
/*
	char str1[]= {"sai"};
	char str2[]= {"bsai"};
	k= strcmp(str1, str2);
	printf("k value is %d\n", k);
	if(k==0)
	{
		printf("both strings are same\n");
	}
	else if(k>0)
	{
		printf("%s is bigger than %s", str1, str2);
	}
	else
	{
		
		printf("%s is smaller than %s", str1, str2);
	}
*/


	
	//string concatenate

/*	char str1[5]= {"sai "};
	char str2[]= {"srinivas"};
	strcat(str1, str2);
	printf("%s", str1);
*/
	
/*	printf("\n");
	char str1[5]= {"sai "};
	char str2[]= {"srinivas"};
	k= strcat(str1, str2);
	printf("%s\n", str1);
	printf("%d", k);

*/
	


	//string copy
	
	char str1[]= {"sai "};
	char str2[]= {"srinivas"};
	k= strcpy(str1, str2);
	printf("%s\n", str1);
	printf("%c", *k);

	
}
