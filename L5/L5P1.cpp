#include <iostream>
#include <math.h>
using namespace std;

int min (int,int);

int main()
{	
	int x=0,y=0;
	cin>>x>>y;
	cout<<min(x,y); 
	
	return 0;
	
}

int min (int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}


