#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int N=0,m=0,i=0,n=0,j=0;
	float min=0;
	cin>>N>>m;
	int* x=new int[m];
	float Tx=0;
	float Tn[20]={0};
	for(i=0;i<m;i++)
		cin>>x[i];
	for(n=2;n<=N;n++)
	{
		Tn[n]=0;
		for(i=0;i<(m-n);i++)
		{
			Tx=0;
			for(j=i;j<(i+n);j++)
			{
				Tx+=x[j];
			}
			Tx/=n;
			Tn[n]+=fabs(Tx-x[i+n]);
		}
		Tn[n]/=(m-n);
	}
	min=Tn[2];
	int a=2;
	for(n=2;n<=N;n++)
	{
		if(min>Tn[n])
		{
			min=Tn[n];
			a=n;
		}		
	}
	cout<<a<<" "<<fixed<<setprecision(2)<<min;
	return 0;
}
