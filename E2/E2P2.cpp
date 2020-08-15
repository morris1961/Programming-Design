#include <iostream>
using namespace std;

void insertionSort(int *x, int *y, int len);	

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	int *x = new int [n], *y = new int [n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}  
	insertionSort(x, y, n);
	for (int i = 0; i < n; i++)
	{
		cout << x[i] <<" ";
	}
	cout <<endl;
	for (int i = 0; i < n; i++)
	{
		cout << y[i] <<" ";
	} 
	cout <<endl;
//	if (k > n)
//		k = n;
//	if (k < 1)
//		k = 1;
//	cout << x[k-1] << " " << y[k-1];
	return 0;
}

void insertionSort(int *x, int *y, int len)											 
{
	for (int i = 0; i < len; i++)														 
	{
		for (int j = i; j > 0; j--)														 
		{												 
			if (x[j-1] + y[j-1] > x[j] + y[j])																 
			{
				int temp1 = x[j-1];														 
				x[j-1] = x[j];
				x[j] = temp1;
				
				int temp2 = y[j-1];														 
				y[j-1] = y[j];
				y[j] = temp2;
				
			}
			else if (x[j-1] + y[j-1] == x[j] + y[j])
			{
				if (x[j-1] > x[j])
				{
					int temp1 = x[j-1];														 
					x[j-1] = x[j];
					x[j] = temp1;
					
					int temp2 = y[j-1];														 
					y[j-1] = y[j];
					y[j] = temp2;
				}
				else
					break; 
			}
			else																		 
				break;
		}
	}
}
