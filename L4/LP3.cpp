#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n=0,m=0,Tx=0,i=0,j=0;
	bool f=true;
	cin>>n>>m;
	int* x=new int [m];
	for(i=0;i<m;i++)
	{
		cin>>x[i];
	}
	for(i=0;i<(m-n+1);i++)
	{
		Tx=0;
		for(j=i;j<(i+n);j++)
		{
			Tx+=x[j];
		}
		if(f)
		{
			cout<<Tx/n;
			f=false;
		}
		else
			cout<<" "<<Tx/n;
	}
	return 0;
}
