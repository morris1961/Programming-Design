#include <iostream>
#include <math.h>
using namespace std;

int find(int,int,int);
int mod(int,int,int);

int main()
{	
	long long int p=0,g=0,A=0,a=0,B=0,b=0,K=0;
	cin>>p>>g>>A>>B;
	a=find(g,A,p);
	b=find(g,B,p);
	K=mod(B,a,p);										
	cout<<a<<" "<<b<<" "<<K;
	return 0;
}

int find(int x,int y,int z)
{								
	int m=0;
	
	for(int i=1;;i++)								 
	{	
		m=mod(x,i,z);
		if(m==y)
			return i;
	} 
}

int mod(int x,int y,int z) 
{
	int c=1;
	while (true)
	{
		if(y==1)
		{
			return (x*c)%z;
		}
		else if(y%2==1)
		{
			c=(c*x)%z;
			y--;
		}
		x=(x*x)%z;
		y=y/2;
	}
}
