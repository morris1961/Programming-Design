#include <iostream>
using namespace std;

int main()
{
	int g=0,a=0;
	cin>>g>>a;
	if((g==1&&a>=18)or(g==0&&a>=16))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0 ;
}
