#include"iostream"
#include"math.h"
#define MAX 100
using namespace std;
int main(int argc, char* argv[])
{
    int N;
    double D[MAX],sum=0,SumD[MAX];
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>D[i];
        sum+=D[i];
        SumD[i] = sum;
    }
    while(true)
    {
        int a,b;
        cin>>a>>b;
        if(a>N||b>N)
            break;
        float temp = fabs(SumD[a-1]-SumD[b-1]);
        cout<<"result: "<<(temp>(sum-temp)?(sum-temp):temp)<<endl;
    }
    return 0;
}


某环形公路上有N个站点，分别记为A1......An，从Ai到A（ i+1）的距离为Di。An到A1的距离为Do，假设Do=Dn=1，保存在数组D（N）中，现在要求你与一个函数，能够高效的计算出公路上任意两点的最近距离，要求空间复杂度不能超过O(N)。

const int N=100;
double D(N);
double sum=0;
double sumD[N];
Void preprocess(){
	cin>>N;
	for(int i=0;i<N;i++)
	{
		sum+=D[i];
		sumD[i]=sum;
	}
}
double Distance(int i, int j){
   float temp;
   temp=fabs(sumD[i]-sum[j]);
   return (temp>(sum-temp)?(sum-temp):temp);
   
}
