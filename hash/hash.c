/****************************/
/* 采用数组的方法构建哈希表 */
/****************************/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define DataType int
#define MAX 30

typedef struct HashNode
{
  DataType data;//存储值
  int isNull; //标志改为值收否已经被填充了
}HashTable;

HashTable hashTable[MAX];


void initHashTable()
{
  int i;
 for(i=0;i<MAX;i++) 
 {
    hashTable[i].isNull=1;//设置初始状态为空
 }
}

int getHashAddress(DataType key)
{
  return key%29;
}

int insertHashData(DataType key)
{
  int hashAddress=key%29;
  int rv=1;
   if(hashTable[hashAddress].isNull==1) 
   {
     hashTable[hashAddress].data=key;
	 hashTable[hashAddress].isNull=0;
     rv=0;
   }
   else{
	   
     while(hashTable[hashAddress].isNull==0 && hashAddress<MAX)
	 {
       hashAddress++;
	 }
    if(hashAddress == MAX)//如果哈希表溢出
	{
		rv=-1;
		goto END;
	}
	hashTable[hashAddress].data=key;
	hashTable[hashAddress].isNull=0;
   }
END:
   return rv;
}

int findHashData(DataType key)
{
   int hashAddress=getHashAddress(key);
   
   while(!(hashTable[hashAddress].isNull==0&&hashTable[hashAddress].data==key&&hashAddress<MAX))
   {
         hashAddress++; 
   }
   if(hashAddress==MAX)
   {
   hashAddress=-1;
   }
   return hashAddress;

}

int main(int argc,char** argv)
{
  int key[]={123,456,688,899,7887,5678,2356,897867};
  int i;
  initHashTable();
  for(i=0;i<8;i++)
  {
      insertHashData(key[i]);
  }
  for(i=0;i<8;i++)
  {
    int address;
	address=findHashData(key[i]);

  }
  reutn 0;
}

