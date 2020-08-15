#include <iostream>
#include <cmath>
using namespace std; 

int shortestPath (int [][101],int ,int ,int );

int main()
{
	int n=0,m=0,u=0,v=0,s=0,t=0,d[101][101];
	cin>>n>>m>>s>>t;
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			d[i][j]=99999;
		}
	}
	
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v;
		cin>>d[u][v];
	}
	cout<<shortestPath(d,s,t,n);
	return 0;
}

int shortestPath (int array[][101],int s,int t,int n)
{
	int F = 99999,x = 0;
	if (s == t)
		return 0;
	else
		for (int i = 1 ; i <= n ; i++)
		{
			if (array[i][t] != 99999)
			{
				x=shortestPath(array,s,i,n);	
				if (x+array[i][t]<F)
					F=x+array[i][t];
			}		
		}
	return F;
}

// morris is an asshole
	

