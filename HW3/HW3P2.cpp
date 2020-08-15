#include <iostream>
using namespace std;

int main()
{
	int n = 0,m = 0,s = 0,d = 0,a[101][101] = {0},t = 0,x[4] = {0};			//宣告變數n為總站數，m為最多下車次數，s為起始站，d為終點站 
																			//a[i][j]為從第j站到第i+1站之價格，t從s~d的花費，x[i]為第i次下車下哪站 
	cin >> n >> m >> s >> d;												//輸入n,m,s,d 
	
	for(int i = 1;i < n;i++)												//輸入a[i][j] 
	{
		for(int j = 1;j <= i;j++)
		{
			cin >> a[i][j];
		}
	} 
	
	int min = a[d - 1][s];													//假設最低價格為從s直接到d的價格 
	
	for(int y = 1;y <= m ;y++)												//以m值決定可下車幾次 
	{
		switch (y)															//決定這次要下車幾次 
		{
			case(1):														//下一次 
			{
				for(int i = s;i < d - 1;i++)									//第一次從s+1站下到d-1站 
				{	
					t = a[i][s] + a[d - 1][i + 1];								//把價格加起來 
					if(min > t)												//如果價格較小 
					{
						min = t;											//紀錄價格 
						x[1] = i + 1;										//紀錄第一次下哪站 
					}
				}
				break;
			}
			case(2):														//下兩次 
			{
				for(int j = s;j < d - 2;j++)								//第一次從s+1下到d-2 
				{
					for(int i = j + 1;i < d - 1;i++)						//第二次從j+1下到d-1站 
					{
						t = a[j][s] + a[i][j + 1] + a[d - 1][i + 1];		//把價格加起來
						if(min > t)											//如果價格較小
						{
							min = t;										//紀錄價格
							x[1] = j + 1;									//紀錄第一次下哪站
							x[2] = i + 1;									//紀錄第二次下哪站
						}
					}
				}
				break;
			}
			case(3):														//下三次 
			{
				for(int k = s;k < d - 3;k++)								//第一次從s+1下到d-3站 
				{
					for(int j = k + 1;j < d - 2;j++)						//第二次從k+1下到d-2站
					{
						for(int i = j + 1;i < d - 1;i++)					//第三次從j+1下到d-1站
						{
							t = a[k][s] + a[j][k + 1] + a[i][j + 1] + a[d - 1][i + 1];		//把價格加起來
							if(min > t)										//如果價格較小
							{
								min = t;									//紀錄價格
								x[1] = k + 1;								//紀錄第一次下哪站
								x[2] = j + 1;								//紀錄第二次下哪站
								x[3] = i + 1;								//紀錄第三次下哪站
							}
						}
					}
				}
				break;
			}
		}
	}
	
	cout << x[1];															//輸出第一次下哪站(如果沒下則會輸出宣告的值零) 
	for(int i = 2;i <= m;i++)												//輸出第二、三次下哪站 
	{		
		if(x[i] != 0)														//如果有下才輸出 
			cout << " " << x[i];
	}
	cout << " " << min;														//輸出最小價格 
	
	return 0 ;
}
