#include <iostream>

using namespace std;

const int MAX_CUS_CNT=100;
void noBusTour(int [][MAX_CUS_CNT+1], int [], int );

int main()
{
	int n=0,d[MAX_CUS_CNT+1][MAX_CUS_CNT+1]={0},Bd[MAX_CUS_CNT+1][MAX_CUS_CNT+1]={0},tour[MAX_CUS_CNT+1]={0};
	int a=0,b=0;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>d[i][j];
		}
		for(int j=0;j<=n;j++)
		{
			cin>>Bd[i][j];
		}
	}
	noBusTour(d,tour,n);
	for(int i=0;i<=n;i++)
	{
		a+=tour[i];
	}	
	noBusTour(Bd,tour,n);
	for(int i=0;i<=n;i++)
	{
		b+=tour[i];
	}
	cout<<(a>b?b:a);
	return 0;
}

void noBusTour(int d[][ MAX_CUS_CNT + 1], int tour[],const int n)
{
	int re[101]={0},i=0;
	bool repeat=false;
	for(int t=0;t<=n;t++)
	{
		tour[t]=99999;
		for(int j=1;j<=n;j++)
		{
			repeat=false;
			for(int k=0;k<t;k++)
			{
				if(re[k]==j)
					repeat=true;
			}
			if(i==j||repeat)
				continue;
			else if(tour[t]>d[i][j])
			{
				tour[t]=d[i][j];
				re[t]=j;
			}
		}
		tour[n]=d[i][0];
		i=re[t];
	}
	
}
