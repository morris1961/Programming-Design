#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;

int main()
{
	int n=0,B=0,Tw=0,Tv=0;
	int w[100]={0},v[100]={0};
	bool x[100]={0};
	cin>>n>>B;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(x[i])
		{
			Tw+=w[i];
			Tv+=v[i];
		}
	}
	if(Tw<=B)
		cout<<Tw<<" "<<Tv;
	else
		cout<<0;
	return 0;
}
