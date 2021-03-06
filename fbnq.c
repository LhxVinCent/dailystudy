#include<iostream>
#include "stdafx.h"
#include<memory>

using namespace std;



const int max_size==20;//斐波那契数组的长度

/*构造一个斐波拿妾数组*/

void Fibonacci(int *F)
{
   F[0]=0;
   F[1]=1;
   for(int i=2;i<max_size;i++)
   {
       F[i]=F[i-1]+F[i-2];

   }

}


/*定义斐波拿妾查找法*/

int FibonacciSearch(int *a,int n,int key)//a为要查找的数组,n为要查找的数组的长度,key为要查找的数组的关键字
｛
　　int low=0;
   int high=n-1;
   int F[max_size];
   Fibnacci(F);//构造一个斐波拿妾数组Ｆ
   
   int k=0;
   while(n>F[k]-1) //计算n位于斐波拿妾数列的位置
{
    ++k;
}

int *temp;//将数组a扩展到F[K]-1的长度
temp=new int[F[k]-1];
memcpy(temp,a,n*sizeof(int));

for(int i=n;i<F[k]-1;i++)
  {
	   temp[i]=a[n-1];
  }

while(low<=high)
{
     int mid=low+F[k-1]-1;
	 if(key<temp[mid])
	 {
        if(key<temp[mid])
		{
           high=mid-1;
		   k-=1;
		}
	 }
	 else if(key>temp[mid])
	 {

         low=mid+1;
		 k-=2;

	 }
	 else{

       
	   
         if(mid<n)
		 { 
           return mid;//若相等则说明mid即为查找到的位置
		 }
		 else
			 return n-1;//若mid>=n则说明是扩展的数值,返回n-1

	   }
	 }
delete [] temp;
return -1;
}







   
   
   
   　　　

｝

