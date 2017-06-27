//  给你一个数小于1000000，分别用100,50,20,10,5块表示出来，有多少种表示方法。写出算法即可。
//  算法如下：设置这个数值为N
//  首先将这个数字N使用5块分出，即这个数字N共有n个五块可以表示出来
//  然后分别:
//  100有20个5块
//  50有10个5块
//  20有4个5块
//  10有2个5块
//  5有1个5块
//  最后使用绑定法来求解最后值，
//  比如将n个5快以10个来绑定，穷举
//  最后完成分块
//  必须从大到小进行判断  因为如果从小到达 很有可能最后不能被100整除从而出错
//  



#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<cstdio>
#include<vector>
#include<unordered_map>
#include<stdio.h>
using namespace std;

unordered_map<int,int> BaseSum[5];
int ReturnTotal(int num,int index,int* base,FILE* fd)
{
	if(index==0)
		return 0;
   int total=0;
   int groups=0;
  printf("%d\n",total);
   groups=num/base[index];
   for(int i=0;i<=groups;i++)
   {
	   total+=1;
	   printf("%d\n",total);
	   total+=ReturnTotal(num-base[index]*i,index-1,base,fd);
   }
  printf("%d\n",total);
  BaseSum[index].insert(make_pair(num,total));
  fprintf(fd,"%d %d\n",num,total);
  return total; 
}
int main(int argc,char** argv)

   {
	   FILE* fd;
	   fd=fopen("./total.txt","w+");
       if(fd==NULL)
	   {
          printf("打开文件失败!!!\n");
	   }
	  int base[]={5,10,20,50,100};
      int n=1000;
	  
  cout<<n<<"\n"<<endl;
  printf("%d\n",n);
     ReturnTotal(n,4,base,fd); 
	 
   }
