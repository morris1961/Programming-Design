#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int x=0,r=0;
	cin>>x>>r;
	if(x>=r)
	{
		x=x/r;
		while(x>=r)
		{
			x=x/r;
		}
		cout<<x;
	}
	else
	{
		cout<<x;
	}
	return 0 ;
}
