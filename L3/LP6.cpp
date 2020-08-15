#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int h=0,m=0,s=0,x=0,a=0,b=0,c=0;
	cin>>h>>m>>s>>x;
	a=(x+s)%60;
	b=(m+((x+s)/60))%60;
	c=h+((m+((x+s)/60))/60);
	cout<<c<<":"<<b<<":"<<a;
	return 0 ;
}
