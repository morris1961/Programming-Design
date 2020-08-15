#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int oneStep(int **dataI, int n, int k, int *pass);
int twoStep(int **dataI, int n, int *pass, int count);

int main()
{
	char f[10] = {0};
	int n = 0, v = 0;
	cin >> f;
	char *p = strchr(f, ',');
	*p = '\0';
	n = atoi(f);
	v = atoi(p+1);
//	cout << n << " " << v;

	char **dataC = new char *[n];
	int **dataI = new int *[n];
	int *pass = new int [n];
	pass[0] = v - 1;
	
	for (int i = 0; i < n; i++)
	{
		dataC[i] = new char [2*n+1];
		dataI[i] = new int [n];
		cin >> dataC[i];
		
		p = strchr(dataC[i], ',');
		*p = '\0';
		dataI[i][0] = atoi(dataC[i]);
		//cout << dataI[i][0] << " ";
		for (int j = 1; j < n - 1; j++)
		{
			p = strchr(p+1, ',');
			//cout << p <<endl;
			*p = '\0';
			dataI[i][j] = atoi(p-1);
			//cout << dataI[i][j] << " ";
		}
		dataI[i][n-1] = atoi(p+1);
		//cout <<dataI[i][n-1]<<endl;
	}
	int count = oneStep(dataI, n, v, pass);
	int Cnt = twoStep(dataI, n, pass, count);
	cout << count-1 << " " << Cnt;
	

	return 0;
}

int oneStep(int **dataI, int n, int k, int *pass)
{
	int count = 1;
	for (int i = 0; i < n; i++)
	{
		if (dataI[k-1][i] == 1)
		{
			pass[count] = i;
			count++;
		}
			
	}
	return count;
}

int twoStep(int **dataI, int n, int *pass, int count)
{
	int Cnt = 0;
	bool *doPass = new bool [n];
	for (int i = 0; i < n; i++)
	{
		doPass[i] = false;
		for (int j = 0; j < count; j++)
		{
			if (pass[j] == i)
				doPass[i] = true;	
		}
		//cout << i << " " << doPass[i] <<endl;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < count ; j++)
		{
			if (doPass[i] == false)
			{
				if (dataI[pass[j]][i] == 1)
				{
					pass[count + Cnt] = i;
					Cnt++;
					//cout << pass[j] <<" "<<i<<endl;
				}
			}
		}
	}
	int answer = Cnt;
	//cout <<pass[]<<endl;
	

	
	for (int i = count; i < count + Cnt; i++)
	{
		int temp = 0;
		//cout <<pass[i]<<" ";
		for (int j = i + 1; j < count + Cnt; j++)
		{
			
			if (i == j)
				break;
			else if (pass[i] == pass[j])
			{
				//cout << i << " "<< j<<endl;
				temp++;
				answer--;
			}
				
		}
		i += temp;
	}
	
	return answer;
}
