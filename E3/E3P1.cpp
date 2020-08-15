#include <iostream>
using namespace std;

int main()
{
	int n = 0, ans[2] = {0}, count = 0;
	cin >> n;
	int *x = new int [n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}

	while(count < n)
	{
		int max = -1, index = 0;
		for (int i = 0; i < n; i++)
		{
			if (max < x[i])
			{
				max = x[i];	
				index = i;
			}
		}
		if(ans[0] > ans[1])
		{
			ans[1] += max;
			x[index] = -2;
		}
		else
		{
			ans[0] += max;
			x[index] = -2;
		}
		count++;
	}
	cout << ans[0] << " " << ans[1];
	return 0;
 } 
