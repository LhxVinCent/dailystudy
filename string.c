#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int SumMax(char* string)
{
int num[]={0};
int time[]={0};


int i=0;
int start=0;
int mine=0;
size_t slen=strlen(string);
while(i<slen)
{
       if(isdigit(string[i]))
	   {
		   if(start==0)
	         {
			    start=1;
				mine=i;
			 }
		else{
			int temp=0;
			if(start==1)
			{
				while(1)
				{
					if(i-1-mine!=0)
					{
						int expert=1;
						int j=0;
						for(j=0;j<(i-1-mine);j++)
						{
							expert*=10;
						}
						temp=temp+int(string[mine])*expert;
						
					}
					else{
						temp=temp+int(string[mine]);
					}
					mine+=1;
					if(i-mine==0)
                        break;					
				}
				int n=0;
				int ok=0;
				if(sizeof(num)/sizeof(int)>0)
				{
					while(n<(sizeof(num)/sizeof(int)))
					{
						if(num[n]==temp)
						{
							time[n]+=1;
							ok=1;
							
						}
						n++;
					}
					if(ok==0)
					{
						num[n]=temp;
						time[n]=1;
					}
					
				}
				else{
					
					num[n]=temp;
					time[n]=1;
				}
				
			}
			
		start=0;
			
		  
		}
		i+=1;
}

int x=0;
int Max=0;
int n=sizeof(time)/sizeof(int);

CompareResult(n,time,num);
Max=time[0]*num[0];
return Max;
}


int CompareResult(int n,int *time,int* sum)
{
    int i;
	int j;
	int temp;
    for(i=0;i<n;i++)
	{
        for(j=i+1;j<n;j++)
		{
           if(*(time+i)<*(time+j))
		   {
                temp=*(time+i);
				*(time+i)=*(time+j);
				*(time+j)=temp;
                
				temp=*(sum+i);
				*(sum+i)=*(sum+j);
				*(sum+j)=temp;
                 
		   }

		}

	}
  return 0;
}



