#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int k=0,m=0,n=0,y=0,q=0,a[99]={0},t=0;
	cin>>k>>m>>n;
	int* x=new int[k];
	for(int i=1;i<=k;i++)
	{
		cin>>x[i];
		x[i]=pow(m,k-i)*x[i];
		y=y+x[i];
	}
	if(y>=n)
	{
		q=y/n;
		a[1]=y%n;
		cout<<a[1];
		for(t=2;q>=n;t++)
		{
			a[t]=q%n;
			q=q/n;
			cout<<" "<<a[t];
		}
		cout<<" "<<q;
		
	}
	else
	{
		cout<<y;
	}
	return 0;
}
