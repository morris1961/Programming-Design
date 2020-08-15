#include <iostream>
#include <cmath>
using namespace std;

void bubbleSort(const int unsorted[], int sorted[], int len);
void insertionSort(const int unsorted[], int sorted[], const int unsIndex[], int sIndex[], int len);

struct Point
{
	int x; 
	int y;
	int dis()
	{
		return (pow(x,2) + pow(y,2));
	}
};

int main()
{
	int n = 0;
	cin >> n;
	Point *a = new Point [n];
	int *unsorted = new int [n], *sorted = new int [n], *unsIndex = new int [n], *sIndex = new int [n];
	for(int i = 0; i < n; i++)
		cin >> a[i].x;
	for(int i = 0; i < n; i++)
		cin >> a[i].y;
	for (int i = 0; i < n; i++)
	{
		unsorted[i] = a[i].dis();
		unsIndex[i] = i; 
	}
	insertionSort(unsorted, sorted, unsIndex, sIndex, n);
	cout << sIndex[0]+1;
	for (int i = 1; i < n; i++)
	{
		cout << " " << sIndex[i]+1;
	}	
		
	return 0;
}

void bubbleSort(const int unsorted[], int sorted[], int len)
{
	for (int i = 0; i < len; i++)
		sorted[i] = unsorted[i];
		
	for (int j = len; j >= 0; j--)
	{
		for (int i = 0; i < len - 1; i++)
		{
			if (sorted[i] > sorted[i+1])	 
			{
				int temp = sorted[i+1];
				sorted[i+1] = sorted[i];				
				sorted[i] = temp;
			}
		}
	}
}

void insertionSort(const int unsorted[], int sorted[], const int unsIndex[], int sIndex[], int len)
{
	for (int i = 0; i < len; i++)
	{
		sorted[i] = unsorted[i];
		sIndex[i] = unsIndex[i];
		for (int j = i; j > 0 ; j--)
		{
			if(sorted[j-1] > sorted[j])
			{
				int temp1 = sorted[j];
				sorted[j] = sorted[j-1];
				sorted[j-1] = temp1;
				
				int temp2 = sIndex[j];
				sIndex[j] =  sIndex[j-1];
				sIndex[j-1] = temp2;
			}
			else
			{
				break;
			}
		}
	}
}
	 
