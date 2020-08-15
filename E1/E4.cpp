#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int p=0,q=0,n=0,f[11]={0},r[11]={0},t[11]={0};
	int a1=0;
	float a2=0;
	cin>>n>>p>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	if(q<=t[1])
	{
		a2=p*q-(f[1]+r[1]*q);
		a1=1;	
	}
	else if(q>t[1])
	{
		a2=p*q-(f[1]+r[1]*t[1]+r[1]*(q-t[1])/2);	
		a1=1;	
	}
	for(int i=2;i<=n;i++)
	{
		float temp=0;
		if(q<=t[i])
		{
			temp=p*q-(f[i]+r[i]*q);	
			if(a2<temp)
			{
				a2=temp;
				a1=i;
			}
			if(a2==temp&&f[i]<f[a1])
			{
				a2=temp;
				a1=i;
			}
			
		}
		else if(q>t[i])
		{
			temp=p*q-(f[i]+r[i]*t[i]+r[i]*(static_cast<float>(q-t[i]))/2);	
			if(a2<temp)
			{
				a2=temp;
				a1=i;
			}
			if(a2==temp&&f[i]<f[a1])
			{
				a2=temp;
				a1=i;
			}
		}
	}
	if(a2<=0)
		cout<<0<<" "<<0;
	else
		cout<<a1<<" "<<a2;
	return 0;
}
