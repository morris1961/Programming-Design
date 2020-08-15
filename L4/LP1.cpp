#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;

int main()
{
	float a,b;
	cin>>a>>b;
	if((a+b)==0.3)
		cout<<"a + b is 0.3.\n";
	else
		cout<<"a + b is not 0.3.\n";
	cout<<setprecision(10)<<a+b;
	return 0;
}
