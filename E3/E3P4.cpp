#include <iostream>
using namespace std;


int main()
{
	int pA = 0, pB = 0, pC = 0, k1 = 0, k2 = 0, b = 0;
	cin >> pA >> pB >> pC >> k1 >> k2 >> b;
	bool **buy = new bool *[3];
	int **num = new int *[3];
	for (int i = 0; i < 3; i++)
	{
		buy[i] = new bool [7];
		num[i] = new int [7];
	}
	for (int i = 0; i < 3; i++)
		for(int j = 0; j < 7; j++)
		{
			cin >> buy[i][j];
			num[i][j] = 0;
		}
			
	bool oneday[7] = {false}, twoday[7] = {false};
	int forone[7] = {0}, fortwo[2][7] = {0}; 
	
	for (int i = 0; i < 7; i++)
	{
		if(buy[0][i])
		{
			if(buy[1][i])
			{
				if(buy[2][i])
				{
					num[0][i] = 0;
					num[1][i] = 0;
					num[2][i] = 0;
				}
				else
				{
					twoday[i] = true;
					fortwo[0][i] = 0;
					fortwo[1][i] = 1;
					num[2][i] = -1;
				}
			}
			else if (buy[2][i])
			{
				twoday[i] = true;
				fortwo[0][i] = 0;
				fortwo[1][i] = 2;
				num[1][i] = -1;
			}
			else
			{
				oneday[i] = true;
				forone[i] = 0;
				num[1][i] = -1;
				num[2][i] = -1;
			}
		}
		else if (buy[1][i])
		{
			if(buy[2][i])
			{
				twoday[i] = true;
				fortwo[0][i] = 1;
				fortwo[1][i] = 2;
				num[0][i] = -1;
			}
			else
			{
				oneday[i] = true;
				forone[i] = 1;
				num[0][i] = -1;
				num[2][i] = -1;
			}
		}
		else if (buy[2][i])
		{
			oneday[i] = true;
			forone[i] = 2;
			num[0][i] = -1;
			num[1][i] = -1;
		}
		else
		{
			num[0][i] = -1;
			num[1][i] = -1;
			num[2][i] = -1;
		}
	}
	
	for (int i = 0; i < 7; i++)
	{
		if(oneday[i])
		{
			if (forone[i] == 0)
			{
				if(b > pA)
				{
					b-=pA;
					num[0][i]++;
				}
				else
				{
					break;
				}	
			}
			else if (forone[i] == 1)
			{
				if(b > pB)
				{
					b-=pB;
					num[1][i]++;
				}
				else
				{
					break;
				}
			}
			else if (forone[i] == 2)
			{
				int count = 0;
				if(b > pC)
				{
					while(b > pC)
					{
						b-=pC;
						num[2][i]++;
						count++;
						if (count == k1)
							break;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	
	for (int i = 0; i < 7; i++)
	{
		if(twoday[i])
		{
			if(fortwo[0][i] == 0 && fortwo[1][i] == 1)
			{
				if(b > pA)
				{
					b-=pA;
					num[0][i]++;
					if(b > pB)
					{
						b-=pB;
						num[1][i]++;
					}
					else
					{
						break;
					}
				}
				else
				{
					if(b > pB)
					{
						b-=pB;
						num[1][i]++;
					}
					else
					{
						break;
					}
				}	
			}
			else if(fortwo[0][i] == 1 && fortwo[1][i] == 2)
			{
				if(b > pB)
				{
					b-=pB;
					num[1][i]++;
					if(b > pC)
					{
						int count = 0;
						while(b > pC)
						{
							b-=pC;
							num[2][i]++;
							count++;
							if (count == k2)
								break;
						}
					}
					else
					{
						break;
					}
				}
				else
				{
					if(b > pC)
					{
						int count = 0;
						while(b > pC)
						{
							b-=pC;
							num[2][i]++;
							count++;
							if (count == k2)
								break;
						}
					}
				}		
			}
			else if(fortwo[0][i] == 0 && fortwo[1][i] == 2)
			{
				if(b > pA)
				{
					b-=pA;
					num[0][i]++;
					if(b > pC)
					{
						int count = 0;
						while(b > pC)
						{
							b-=pC;
							num[2][i]++;
							count++;
							if (count == k2)
								break;
						}
					}
					else
					{
						break;
					}
				}
				else
				{
					if(b > pC)
					{
						int count = 0;
						while(b > pC)
						{
							b-=pC;
							num[2][i]++;
							count++;
							if (count == k2)
								break;
						}
					}
				}		
			}
		}
//		cout << i << " " <<b;
	}
//	cout << endl;
//	for(int i = 0; i < 7; i++)
//		cout << oneday[i] << " ";
//	cout << endl;
//	for(int i = 0; i < 7; i++)
//		cout << twoday[i] << " ";
//	cout << endl;

	if(num[0][0] == -1)
		cout << "-";
	else
		cout << num[0][0];
	for (int i = 0; i < 3; i++)
	{
		for(int j = 1; j < 7; j++)
		{
			if(num[i][j] == -1)
				cout << " " << "-";
			else
				cout << " " << num[i][j];
		}
		cout << "\n";
		if (i != 2)
		{
			if(num[i+1][0] == -1)
				cout << "-";
			else
				cout << num[i+1][0];
		}
		
	}
		
	return 0;
 } 
