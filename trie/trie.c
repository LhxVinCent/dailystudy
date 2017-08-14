/***************/
/*本例实现字典树*/
/***************/

#include<iostream>
#include<string>

using namespace std;
//表示next数据的长度,表示26个字母.如果字符串中有其他字符串的话，应相应调整
//如果所有的字符串都是手机的话，那就是10了
const int MAX_NUM=26;

typedef struct trieNode{
   int num;
   struct trieNode* next[MAX_NUM];

}TRIENODE;

TRIENODE* CreateTrie()
{
	int i;
    TRIENODE* p=new TRIENODE;
     if(p==NULL)
	 {
        return 0;
	 }
     for(i=0;i<MAX_NUM;i++)
	 {
        p->next[i]=NULL;
	 }
     p->num=1;
	 return p;
}

void InsertTrieTree(TRIENODE* *root,string str)

{
  TRIENODE* p;
  if(*root==NULL)
	  {
          p=CreateTrie();
          *root=p;
	  }
     else{

        p=*root;
	 }
 int len=str.length();
 int k;
  for(int i=0;i<len;i++)
  {
       k=str.at(i)-'a';
	   if(p->next[k]!=NULL)
	   {
          p->next[k]->num+=1;
	   }
	   else
		   p->next[k]=CreateTrie();
	   p=p->next[k];
 
  }
}

int SearchTrieTree(TRIENODE* *root,string str)
{
    TRIENODE* p
	if(root==NULL)
	{ 
		return -1;

	}
	else{
      p=*root;

	}
	int len=str.length();
	int k;
	for(int i=0;i<len;i++)
	{
        
         k=str.at(i)-'a';
		 if(p->next[k]==NULL)
			 return;
		 p=p->next[k];

	}
	return p->num;








}





















