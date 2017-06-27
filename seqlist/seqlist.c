#include "seqlist.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _tag_SeqList
{
  int capacity;
  int length;
}TSeqList;
SeqList* SeqList_Create(int capacity)
{
  TSeqList* ret=NULL;
  if(capacity<0)
  {
    return NULL;
  }
	 ret=(TSeqList*)malloc(sizeof(TSeqList)+sizeof(unsigned int)*capacity); 
	 if(ret==NULL)
	 {
      return NULL;
	 }
	 memset(ret,0,sizeof(TSeqList)+sizeof(unsigned int)*capacity);
	 ret->node=(unsigned int*)(ret+1);
	 ret->capacity=capacity;
	 ret->length=0;
	 return ret;
}
void SeqList_Destroy(SeqList* list)
{
	if(list==NULL)
	{
		return;
	}
	free(list);
	return;
}
void SeqList_Clear(SeqList* list)
{
 TSeqList* tList=NULL;
 if(list==NULL)
 {
   return;
 }
 tList = (TSeqList*)list;
 tList->length=0;
 return;
}
int SeqList_Length(SeqList* list)
   {
	   TSeqList* tList=NULL;
	   tList=(TSeqList*)list;
	   if(list==NULL)
	   {
		   return -1;
	   }
	   
	   return tList->length;
   }
int SeqList_Capacity(SeqList* list)
{
   TSeqList* tList=NULL;
   tList=(TSeqList*)list;
   if(list==NULL)
   {
     return -1;
   }
   return tList->capacity; 
}
int SeqList_Insert(SeqList* list,SeqListNode* node,int pos)
{
    int i=0;
	TSeqList *tList=NULL;
	tList=(TSeqList*)list;
	if(list==NULL||node==NULL)
	{
      return -1;
    }
    if(tList->length>=tList->capacity)
	{
        return -2;
	}
	if(pos<0||pos>=tList->capacity)
	{
         return -3;
	}
	if(pos>=tList->length)
	{
      pos=tList->length;
	}
    for(i=tList->length;i>pos;i--)
	{
       tList->node[i]=tList->node[i-1];
	}
	tList->node[pos]=(unsigned int)node;
	tList->length++;
	return 0;
}
SeqListNode* SeqList_Get(SeqList* list,int pos)
{
   SeqListNode* ret=NULL;
   TSeqList *tList=NULL;
   tList=(TSeqList*)list;
   if(list==NULL|| pos<0||pos>=tList->length)
   {
      return NULL;
   }
  ret=(SeqListNode*)tList->node[pos];
  return ret;

}
SeqListNode* SeqList_Delete(SeqList* list,int pos)
{
   int i;
   TSeqList *tList=NULL;
   SeqListNode *ret=NULL;
   tList=(TSeqList*)list;
   if(list==NULL||pos<0||pos>=tList->length)
   {
      return NULL;
   }
   ret=(SeqListNode*)tlist->node[pos];
   for(i=pos+1;i<tList->length;i++)
   {
       tList->node[i-1]=tList->node[i];

   }
   tList->length--;
   return ret;
}








