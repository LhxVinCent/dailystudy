#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

#define HASH_LEN 50 //哈希表的长度
#define M 47        //小于50的最小质数

typedef int DataType;//定义一个类型别名
typedef char NameType;//定义名称的类型别名
int NAME_NO=34;  //城市名的个数

typedef struct{
char* py;//名字的拼音
int k;//拼音对应的整数
}NAME;

NAME NameList[HASSSSH_LEN];//全局变量NAME

typedef struct //哈希表的长度
{
	NameType* py;//名字的拼音
	DataType k;//拼音对应的整数
	int si;//占位标记位
   
}HASH_TABLE;

HASH_TABLE HashList[HASH_LEN];

void InitNameList()//城市名称初始化
{
  char* f=NULL;
  int r,s0,i;
  NameList[0].py="harbin";

  NameList[1].py="shijiazhuang";
  NameList[2].py="lanzhou";
  NameList[3].py="kunming";
  NameList[4].py="chengdu";
  NameList[5].py="changchun";
  NameList[6].py="shenyang";

  NameList[7].py="xining";
  NameList[8].py="xian";
  NameList[9].py="kunming";
  NameList[10].py="chengdu";
  NameList[11].py="changchun";
  NameList[12].py="shenyang";

  for(i=0;i<NAME_NO;i++)
  {
   s0=0;
   f=NameList[i].py;
   for(r=0;*(f+r)!='\0';r++)

	 {
       //将字符串的各个字符串所对应的ASCII码相加,所得的整数作为哈希表的关键字
	   s0=*(f+r)+s0;
	 }

   NameList[i].k=s0;
  }
}


void CreateHashList()//建立哈希表
{

  int i;
  for(i=0;i<HASH_LEN;i++)
  {
    HashList[i].py="";
	HashList[i].k=0;
    HashList[i].si=0;
  }

  for(i=0;i<HASH_LEN;i++)
  {
    int sum=0;

	int adr=(NameList[i].k)%M;//哈希表
	int d=adr;
	if(HashList[adr].si==0)//如果不冲突
	{
      HashList[adr].k=NameList[i].k;
	  HashList[adr].py=NameList[i]py;
	  HashList[adr].si=1;
	}

	else//冲突
	{

      do{

          d=(d+NameList[i].k%10+1)%M;
		  sum=sum+1;

	  }while(HashList[d].k!=0);
	  HashList[d].k=NameList[i].k;
	  HashList[d].py=NameList[i].py;
	  HashList[d].si=sum+1;

	}
   
  }


}



int FindList()//查找
{

   char name[20]={0};

   int s0=0,r,sum=1,addr,d;
   
   printf("\n请输入城市名称:");
   scanf("%s",name);

   for(r=0;r<20;r++)//求出姓名的拼音所对应的整数(关键字)
   {
     s0+=name[r];
   }
adr=s0%M;//使用哈希函数

d=adr;

if(HashList[adr].k==s0)//分3种情况判断
{
   printf("\n名称:%s 关键字:%d 查找长度:1",HashList[d].py,s0);
   cout<<endl;
   return 0;
}
else if(HashList[adr].k==0)
{
printf("无此记录!");
cout<<endl;
return 1;


}
else{
int g=0;
do
{
 d=(d+s0%10+1)%M;//伪随机探测再三列法处理冲突
 sum=sum+1;
 if(HashList[d].k==0)
 {
    printf("无此记录!");
	cout<<endl;
	g=1;
	return 1;
 }
 if(HashList[d].k==s0)
 {
    printf("\n名称:%s 关键字:%d 查找长度为:%d",HashList[d].py,s0,sum);
	cout<<endl;
	g=1;
	return 0;
 }
}while(g==0);

}

void DisPlay()//显示哈希表
{
  int i;
  float average=0;
  for(i=0;i<HASH_LEN;i++)
  {
   if(HashList[i].k%M==0)
   {
      HashList[i].py="";
   }
  }

printf("\n\\n地址\t关键字\t\t搜索长度\tH(key)\t名称\n)");//显示格式

for(i=0;i<HASH_LEN;i++)
{
  printf("%d",i);
  printf("\t%d",HashList[i].k);
  printf("\t\t%d",HashList[i].si);
  printf("\t\t%d",HashList[i].k%M);
  printf("\t\t%s",HashList[i].py);
  for(i=0;i<HASH_LEN;i++)
  {
    average+=HashList[i].si;

  }
  average/=NAME_NO;


}


}

void DeleteList()
{
  char name[20]={0};

  int s0=0,r,sum=1,adr,d;

  printf("\n请输入城市名称:");
  scanf("%s",name);
  for(r=0;r<20;r++)//求出姓名的拼音所对应的整数(关键字)
  {
     s0+=name[r];

  }

  adr=s0%M;//使用哈希表
  d=adr;

  if(HashList[adr].k==s0)
  {
     s0=0;
	 HashList[d].py="";//名字的拼音
	 HashList[d].k=0;//拼音对应的整数
	 HashList[d].si=0;
  }
  else if(HashList[adr].k==0)
  {

 printf("\n无此记录!");
 else{
  int g=0;
  do{
   d=(d+s0%10+1)%M;
   sum=sum+1;
   if(HashList[d].k==0)
   {
	   printf("无此记录!");
	   g=1;
   }
   if(HashList[d].k==s0)
   {
     s0=0;
	 HashList[d].py="";
	 HashList[d].k=0;
	 HashList[d].si=0;
	 g=1;
   }
  }while(g==0);
 }

}

}

void EnterList()
{
  int s0=0;r,sum=1,adr,d,h;
  printf("\n请输入姓名的拼音");

scanf("%s",name);
for(r=0;r<20;r++)
	s0+=namer];
{
 char st[20];
 char *xin;

}

cin=st;
printf("\n请输入城市名称的拼音:");
cin>>xin;

for(r=0;*(xin+r)!='\0';r++)
{
  /*方法:将字符串各个字符所对应的ASCII码相加,所得到的整数作为哈希表的关键字*/
s0=(int)(*(xin+r))+s0;

}

adr=s0%M;//使用哈希函数

d=adr;
if(HashList[adr].k==s0)
{
  
}
else if(HashList[d].k==0)
{
	HashList[d].py=xin;
	HashList[d].k=s0;
	HashList[d].si=1;
	h=1;

}
else{

int g=0,h=0;
do
{
 d=(d+s0%10+1)%M;
 sum=sum+1;
 if(HashList[d].k==0)
 {
   HashList[d].py=xin;
   HashList[d].k=s0;
   HashList[d].si=sum;
   h=1;
   g=1;
 }
 if(HashList[d].k=s0)
 {
    cout<<endl;
	g=1;
 }

}while(g==0);
if(h==0)
	return;
else{

 NAME_NO++;
 NameList[NAME_NO-1].py=xin;
 int sum=0;
 int adr=(NameList[NAME_NO-1].k)%M;
 int d=adr;
 if(HashList[adr].si==0)
 {
   HashList[adr].k=NameList[NAME_NO-1].k;
   HashList[adr].py=NameList[NAME_NO-1].py;
   HashList[adr].si=1;

 }else{

   do
   {
       d=(d+NameList[NAME_NO-1].k%10+1)%M;
	   sum=sum+1;
   }while(HashList[d].k!=0)
   HashList[d].k=NameList[NAME_NO-1].k;
   HashList[d].py=NameList[NAME_NO-1].py;
   HashList[d].si=sum+1;




 }
}
}


}

int main()
{

  char ch1;
  printif("\n哈希表\n");
printf("***********************************\n");
printf("      |  D.显示哈希表   |\n");
printf("     |   F.查找         |\n");
printf("      |  S.删除         |\n");
printf("      |  E.插入         |\n");
printf("      |  Q.退出         |\n");
printf("*************************************\n");
InitNameList();

CreateHashList();


while(1)
{
 printf("\n Option");
 fflush(stdin);
 cha1=getchar();
 if(ch1=='D' || ch1=='d')
	 DisPlay();
 else if(ch1 =='F' || ch1 =='f')
   FindList();
 else if(ch1 == 'S' || ch1 == 's')
	 DeleteList();
 else if(ch1 == 'E' || ch1 == 'e')
	 EnterList();
 else if(ch1 == 'Q' || ch1 == 'q')
	 return;
 else{
    printf("\n请输入正确的选择!");
 }

}




}















