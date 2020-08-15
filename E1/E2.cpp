#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x1=0,x2=0,y1=0,y2=0,a=0,b=0;
	cin>>x1>>y1>>x2>>y2;
	if(abs(y1-y2)==abs(x1-x2))
		a=1;
	else
		a=0;
	if(x1==x2||y1==y2)
		a=0;
	b=abs(y1-y2)*abs(x1-x2);
	cout<<a<<" "<<b;
	return 0;
}
