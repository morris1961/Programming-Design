#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void setRN(int rn[], int len);

int main ()
{
	int n = 0;
	cin >> n;
	int *rn = new int [n];
	setRN(rn, n);
	for (int i = 0; i < n; i++)
		cout << rn[i] << " ";
	return 0;
}

void setRN(int rn[], int len)
{
	srand(time(nullptr));
	for (int i = 0; i < len ;i++)
	{
		rn[i] = (rand()+10000) % 10000;
	}
}
