#include <iostream> 
using namespace std;

int gcd(int , int );
int a(int,int []);
int b(int,int []);
	 
int main() 
{ 
	int n=0,x[11]={0},a1=0,b1=0,g1=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	g1=gcd(x[1],x[2]);
	for(int i=2;i<n;i++)
	{
		g1=gcd(g1,x[i+1]);
	}
	a1=a(n,x);
	b1=b(n,x);
	cout<<g1<<" "<<a1<<" "<<b1;
	return 0;
}

int gcd(int q,int p)
{	
	int temp;
	if(q>p)
	{
		temp=q;
		q=p;
		p=temp;
	}	
	if(p%q==0)
		return q;
	p%=q;
	p=gcd(p,q);
	return p;

} 

int a(int n,int x[])
{
	int y=0;
	for(int i=1;i<=n;i++)
		if(x[i]%2==1)
			y++;
	return y;
}

int b(int n,int x[])
{
	int y=0,k=0;
	for(int i=1;i<=n;i++)
	{
		if(y<x[i])
		{
			y=x[i];
			k=i;
		}
			
	}
	y=0;
	for(int i=1;i<=n;i++)
	{
		if(i==k)
			continue;
		if(y<x[i])
		{
			y=x[i];
		}
			
	}
	return y;
}
