#include <iostream>

using namespace std;

int HG(int,int,int[]);

int main() 
{
	int x[60]={0},n=0,t=0;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	cout<<HG(n,t,x);
	return 0;
}

int HG(int n,int t,int x[])
{
	int a=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]>=t)
		{
			a++;
		}
	}
	return a;
}
