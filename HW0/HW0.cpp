#include <iostream>
using namespace std;

int main()
{
	int X=0,A=0,B=0,C=0,Y=0;
	cin >>X>>A>>B>>C>>Y;
	if (X>A+B*Y+C)
	{
		cout<<X-A-B*Y-C;
	}
	else
	{
		cout<<"0";
	}
	return 0;
} 
