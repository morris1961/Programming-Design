#include <iostream>
using namespace std;

int main()
{
	int a=0,b=0,c=0,max=0;
	cin>>a>>b>>c;
	int p=c;
	max=(a-b*p)*(p-c);
	while(max<(a-b*(p+1))*((p+1)-c))
	{
		p++;
		max=(a-b*p)*(p-c);
	}
	cout<<p<<" "<<max;
	return 0 ;
}
