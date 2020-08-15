#include <iostream>
using namespace std;

int findMax(const int *y, const int n);
int findMin(const int *y, const int n);

int main()
{
	int n = 0;
	cin >> n;
	int **x = new int*[n], **y = new int*[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = new int [n];
		y[i] = new int [n];
	}	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> x[i][j];
	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			y[j][i] = x[i][j];
		

	int *minRow = new int [n], *maxCol = new int [n];
	for(int i = 0; i < n; i++)
		minRow[i] = findMin(x[i], n);
	for(int i = 0; i < n; i++)
		maxCol[i] = findMax(y[i], n);
	int max = findMax(minRow, n), min = findMin(maxCol, n);
	cout << max << " " << min;
	return 0;
 } 
 
int findMax(const int *y, const int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if(max < y[i])
			max = y[i];
	}
	return max;
}
int findMin(const int *y, const int n)
{
	int min = 9999;
	for (int i = 0; i < n; i++)
	{
		if(min > y[i])
			min = y[i];
	}
	return min;
}
