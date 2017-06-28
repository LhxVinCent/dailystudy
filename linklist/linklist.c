#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include"linklist.h"
typedef struct _tag_LinkList
{
  LinkListNode header;
  int length;
}TLinkList;
LinkList* LinkList_Create()
{
   TLinkList* ret=(TLinkList*)malloc(sizeof(TLinkList));
   if(ret==NULL)
   {
      return NULL;
   }
   ret->header.next=NULL;
   ret->length=0;
   return ret;

}

void LinkList_Destroy(LinkList* list)
{
    if(list==NULL)
	{
      return;
	}
	free(list);
	return;
}
void LinkList_Clear(LinkList* list)
{
   TLinkList* tList=NULL;
   if(tList==NULL)
   {
      return;
   }
   tList=(TLinkList*)list;
   tList->header.next=NULL;
   tList->length=0;
   return;
}
int LinkList_Length(LinkList* list)
{
   TLinkList* tList=NULL;
     tList=(TLinkList*)list;
    if(list==NULL)
    {
       return -1;
	}		
    return tList->length;
}
int LinkList_Insert(LinkList* list,LinkListNode* node,int pos)
{
	int i;
   TLinkList* tList=NULL;
   tList=(TLinkList*)list;
   LinkListNode* current=NULL;
   current=&tList->header;

   if(i=0;i<pos&&(current->next!=NULL);i++)
   {
       current=current->next;
   }
   node->next=current->next;
   current->next=node;
   tList->length++;
   return 0;
}
LinkListNode* LinkList_Get(LinkList* list,int pos)
{
   int i=0;
   TLinkList* tList=NULL;
   tList=(TLinkList*)list;
   LinkListNode* ret=NULL;
   LinkListNode* current=NULL;
   if(tList==NULL || pos<0 || pos>=tList->length)
   {
      return NULL;
   }
   current=&tList->header;
   for(i=0;i<pos&&(current->next!=NULL);i++)
   {
       current=current->next;
   }
   ret=current->next;
   return ret;
}
LinkListNode* LinkList_Delete(LinkList* list,int pos)
{
  int i=0;  
  TLinkList* tList=NULL;
  tList=(TLinkList*)list;
  LinkListNode* ret=NULL;
  LinkListNode* current=NULL;
  if(tList==NULL || pos<0 || pos>=tList->length )
  {
     return NULL;
  }
  current=&tList->header;
  for(i=0;i<pos&&(current->next!=NULL);i++)
  {
      current=current->next;
  }
  ret=current->next;
  current->next=ret->next;
  return ret;
}


























