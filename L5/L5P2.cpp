#include <iostream>
#include <math.h>
using namespace std;

int min (int,int);
int max (int,int);
int gcd (int,int);

int main()
{
	int x=0,y=0,a=0;
	cin>>x>>y;
	cout<<gcd(min(x,y),max(x,y))<<endl;
	return 0;
}


int min (int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int max (int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int gcd (int a,int b)
{
	if(b%a==0)
		return a;
	b%=a;
	b=gcd(b,a);
	return b;
}
