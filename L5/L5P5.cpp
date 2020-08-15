#include <iostream>

using namespace std;

int HG(int,int,int,int[][60]);

int main() 
{
	int x[20][60]={0},n=0,t=0,m=0;
	cin>>m>>n>>t;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>x[i][j];
	cout<<HG(m,n,t,x);
	return 0;
}

int HG(int m,int n,int t,int x[][60])
{
	int a[20]={0};
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i][j]>=t)
			{
				a[i]=a[i]+1;
			}	
		}
	}
	int b=1;
	for(int i=2;i<=m;i++)
	{
		if(a[i]>a[b])
		{
			b=i;
		}
	}
	return b;
}
