#include <iostream>
using namespace std;

double Expect (int, double[] , int, int);

int main()
{
	int c = 0, r = 0, N = 0,answer1 = 0, s = 0;								 
	double a1 = 0, a2 = 0, a3 = 0, answer2 = 0;								 
	
	cin >> c >> r >> N >> s;
	double p[N+1]={0};
	for (int i = 0; i <= N; i++)
	{
		cin >> p[i];
	}
	int U=N,D=1;
	while (true)
	{	
		a1 = Expect((U+D)/2-1, p, r - s, s - c);
		a2 = Expect((U+D)/2, p, r - s, s - c);
		a3 = Expect((U+D)/2+1, p, r - s, s - c);
		if (a1>a2)
		{
			U=(U+D)/2-1;
		}
		else if (a3>a2)
		{
			D=(U+D)/2+1;
		}
		else
		{
			cout << (U+D)/2 << " " << static_cast<int>(a2);
			break;
		}
		
	}
	//cout << answer1 << " " << static_cast<int>(answer2);
	return 0;
}

double Expect(int i, double p[], int n, int m)
{
	double a = 0, psum = 1;
	for (int j = 0; j < i; j++)
	{
		a += p[j] * (n * j + m * i);
		psum -= p[j];
	}
	a += psum * (i * (n + m));
	
	return a;
}
