#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int p1=0,p2=0,p3=0,x=0,y=0,a=0,b=0,c=0;
	cin>>x>>p1>>p2>>p3>>y;
	if(x>=p1)
	{
		x=x-p1;
		a++;
	}
	if(x>=p2)
	{
		x=x-p2;
		b++;
	}
	while(x>=p3&&c<y)
	{
		x=x-p3;
		c++;
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<x;
	return 0 ;
}
