#include <iostream>
#include <cmath>
using namespace std;


int main ()
{
	const int MAX_M=11; 												//宣告常數MAX_M為m的最大值 
	int n=0,m=0;														//n表示有(n+1)^2個座標, m為幾個威脅點 
	int x[MAX_M]={0},y[MAX_M]={0},r[MAX_M]={0},p[MAX_M]={0};			//x[i]為第i個威脅點的x座標, y[i]為第i個威脅點的y座標 
																		//r[i]為第i個威脅點的半徑, p[i]為第i個威脅點的威脅程度 
	cin>>n>>m;															//輸入n,m 
	for (int i=0;i<m;i++)												//輸入x 
	{
		cin>>x[i];
	}
	for (int i=0;i<m;i++)												//輸入y
	{
		cin>>y[i];
	}
	for (int i=0;i<m;i++)												//輸入r
	{
		cin>>r[i];
	}
	for (int i=0;i<m;i++)												//輸入p
	{
		cin>>p[i];
	}
	
	double an=-1;														//紀錄最大風險值, 因任一點的風險必>=0, 所以先假設最大為-1 
	int x1=0,y1=0;														//x1紀錄最大風險的x座標, y1紀錄最大風險的y座標
	for (int i=0;i<=n;i++)												//找x座標 
	{
		for (int j=0;j<=n;j++)											//找y座標 
		{
			double temp1=0;												//temp1紀錄點(i,j)的風險 
			for (int k=0;k<m;k++)
			{
				double temp2=0;											//temp2紀錄點(x[k],y[k])對點(i,j)造成之風險 
				temp2=p[k]*(r[k]-sqrt((x[k]-i)*(x[k]-i)+(y[k]-j)*(y[k]-j)))/r[k];
				if (temp2>0)											//如果點(x[k],y[k])對點(i,j)造成之風險>0才做加總 
					temp1+=temp2;
			}
			cout<<i<<" "<<j<<" "<<temp1<<endl;
			if (temp1>an)												//找最大風險並記錄該風險值以及點座標 
			{
				an=temp1;
				x1=i;
				y1=j;
			}
		}
	}
	cout<<x1<<" "<<y1;													//輸出點座標 
	
	return 0;
} 
