#include <iostream>
#include <cmath>
using namespace std;
void releaseMemory(int *pathLen, int **d, int **s, int *count, int n);				//清除動態配置之記憶體 
int isNeighbor(int a, int b, int **s, int len);										//找a,b兩個點間是否有道路 

int main()
{
	int n = 0 ,m = 0, k = 0, nodeCnt=0;												//n為幾個點, m為幾段路, k為判斷幾段路線, nodeCnt為判斷之路線有幾個點											
	
	cin >> n >> m >> k;
	
	int *u = new int [m], *v = new int [m], *a = new int [m], *dt = new int [m];	//u[i]到v[i]的距離為dt[i]		
	int **s = new int *[n+1], *count = new int [n+1], **d = new int *[n+1];			//s[i][j]為第i點有連接的點, d[i][j]為第i點到第s[i][j]點的距離, count[i]為第i點有連接幾的點 
	int *pathLen = new int [k];														//pathLen[i]為第i個路線長度
	 
	for (int i = 0; i < m; i++) 
	{
		cin >> u[i] >> v[i] >> dt[i];
	}
	for (int i = 1; i < n+1; i++)													//把題目給的u,v,dt改存入s,d 
	{
		count[i] = 0;																//初始化ocount[i] 
		for(int j = 0; j < m; j++)													//算出第i點有幾個連接點 
		{
			if(u[j] == i)															
			{
				a[count[i]] = j;													//a[count[i]]紀錄第j個u是i 
				count[i]++;
			}
		}
		d[i] = new int [count[i]];													//在d[i]產生count[i]個動態陣列 
		s[i] = new int [count[i]];													//在s[i]產生count[i]個動態陣列
		for (int j = 0; j < count[i]; j++)
		{
			d[i][j] = dt[a[j]];														//d[i][j]存入從i到s[i][j]的距離	
			s[i][j] = v[a[j]];														//s[i][j]存入從i可以到的點 
		}
	}
	delete [] u;																	//把不會用到的記憶體釋放 
	delete [] dt;
	delete [] v;
	delete [] a;																	
	
	for (int i = 0; i < k; i++)														//找k個路線 
	{
		cin >> nodeCnt;																//輸入這次路線有幾個點 
		int *x = new int [nodeCnt];													//產生長度為nodeCnt的陣列 
		for (int j = 0; j < nodeCnt; j++)											
		{
			cin >> x[j];															//輸入點
		}
		
		pathLen[i] = 0;																//初始化pathLen[i] 
		for (int j = 0; j < nodeCnt-1; j++)											//算從x[0]走到x[nodeCnt]的長度 
		{
			int num = isNeighbor(x[j], x[j+1], s, count[x[j]]);						//查詢x[j]到x[j+1]是否有路, 沒路回傳-1, 有路回傳是s[x[j]][]中哪一個點 
			if (num == -1)										
			{
				pathLen[i] = -1;													//沒路路徑長就是-1 
				break;																//停止往下走 
			}
			else
			{
				pathLen[i] += d[x[j]][num];											//有路就看走到哪, 然後把路徑加起來 
			}
		}
		delete [] x;																//釋放不用的記憶體 
	}
	
	for (int i = 0; i < k-1; i++)													//輸出k個路徑長 
		cout << pathLen[i] << " ";
	cout << pathLen[k-1];
	
	releaseMemory(pathLen, d, s, count, n+1);										//釋放剩下的記憶體 
	return 0;
}

void releaseMemory(int *pathLen, int **d, int **s, int *count, int n )				//釋放剩下的記憶體
{
  	delete [] pathLen;
	delete [] count;
	for (int i=1 ;i<n;i++)
	{
		delete [] d[i];
		delete [] s[i];
	}
	delete [] d;
	delete [] s;
}

int isNeighbor(int a, int b, int **s, int len)										//找a,b兩個點間是否有道路
{
	for (int i = 0; i < len ;i++)													//在s[a][]中找是否有b點 
	{
		if (s[a][i] == b)
			return i;																//有則回傳s[a][]中第幾個 
	}
	return -1;																		//沒有就回傳-1 
}
