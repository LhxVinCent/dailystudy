/****************************/
/*这个程序实现压缩字符串中的*/
/*多个空格 并且最后打印字符串*/
/*****************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* DeleteBlank(char* str)
{
	if(str==NULL)
		return 0;
	char* temp =(char*)malloc(strlen(str)+1);
	char* second=str;
	char* first=str;
	int count=0;
	while(*second!='\0')
	{
		if(*second!=' ')
		{
			printf("%s\n",second);
            *temp=*second;
			printf("the numis\n");
			first++;
			temp++;
			count++;
		}else if(first==second && *(first-1)!=' ')
		{
			*temp=' ';
			first++;
			temp++;
			count++;
		}
		++second;
	}
   *temp='\0'; 
	return (temp-count);
}

void TailPrint(char* str,char** out)
{
	if(str==NULL)
		return;
	char* first=str;
	int count=0;
	char temp;
	while(*first!='\0')
	{  

		if(*first!=' ')
		{
			count+=1;
		}else 
		{
			for(int i=0;i<(count/2);i++)
			{
				temp=*(first-count+i);
				*(first-count+i)=*(first-i-1);
				*(first-i-1)=temp;
			}
			count=0;
		}


		first++;
}
//for(unsigned int i=0;i<=(strlen(str)+1);i++)
//{
//	printf("the str");
//*out=str;
//}

*out=str;
}
void Print(char* str)
{
	printf("the string is %s\n",str);
}

int main()
{
   char* str="abc def gnh";

   char* pstr= DeleteBlank(str);
   char* out=(char*) malloc(strlen(pstr)+1);
   TailPrint(pstr,&out);
   Print(out);
   free(out);
   return 0;
}
