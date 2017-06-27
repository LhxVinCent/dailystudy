#include<stdio.h>
#include "stdlib.h"
#include "seqlist.h"
#include "string.h"

typedef struct _Teacher
{
  char name[64];
  int age;
}Teacher;
typedef struct _tag_SeqList
{
   int capacity;
   itn length;
   unsigned int *node;
}TSeqList;


int main()
{

	 int i=0;
	 SeqList *list=NULL;
	 Teacher t1,t2,t3;
	 t1.age=31;
	 t2.age=32;
	 t3.age=33;

	 list = SeqList_Create(10);
	 SeqList_Insert(list,(SeqListNode*)&t1,0);

	 SeqList_Insert(list,(SeqListNode*)&t2,0);
	 SeqList_Insert(list,(SeqListNode*)&t3,0);
	 for(i=0;i<SeqList_length(list);i++)
	 {
       Teacher* tmp=(Teacher*)SeqList_Get(list,i);
	   if(tmp!=NULL)
	   {
         printf("");
	   }
	 }

	 for(i=0;i<SeqList_Length(list);i++)
	 {
        SeqList_Delete(list,i);
	 }
	 SeqList_Destroy(list);
     system("pause");
}
