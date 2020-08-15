#include <iostream>
using namespace std;

int main()
{
	int a=0;
	cin>>a;
	while (a!=2)
	{
		if (a%2==0)
		{
			a=a/2;
		}
		else
		{
			a=(a*3)+1;
		}
		cout<<a<<" ";
	}
	cout<<"1";
	return 0 ;
}
