#include <iostream>
#include <cmath>
using namespace std;
void releaseMemory(int *pathLen, int **d, int **s, int *count, int n);				//�M���ʺA�t�m���O���� 
int isNeighbor(int a, int b, int **s, int len);										//��a,b����I���O�_���D�� 

int main()
{
	int n = 0 ,m = 0, k = 0, nodeCnt=0;												//n���X���I, m���X�q��, k���P�_�X�q���u, nodeCnt���P�_�����u���X���I											
	
	cin >> n >> m >> k;
	
	int *u = new int [m], *v = new int [m], *a = new int [m], *dt = new int [m];	//u[i]��v[i]���Z����dt[i]		
	int **s = new int *[n+1], *count = new int [n+1], **d = new int *[n+1];			//s[i][j]����i�I���s�����I, d[i][j]����i�I���s[i][j]�I���Z��, count[i]����i�I���s���X���I 
	int *pathLen = new int [k];														//pathLen[i]����i�Ӹ��u����
	 
	for (int i = 0; i < m; i++) 
	{
		cin >> u[i] >> v[i] >> dt[i];
	}
	for (int i = 1; i < n+1; i++)													//���D�ص���u,v,dt��s�Js,d 
	{
		count[i] = 0;																//��l��ocount[i] 
		for(int j = 0; j < m; j++)													//��X��i�I���X�ӳs���I 
		{
			if(u[j] == i)															
			{
				a[count[i]] = j;													//a[count[i]]������j��u�Oi 
				count[i]++;
			}
		}
		d[i] = new int [count[i]];													//�bd[i]����count[i]�ӰʺA�}�C 
		s[i] = new int [count[i]];													//�bs[i]����count[i]�ӰʺA�}�C
		for (int j = 0; j < count[i]; j++)
		{
			d[i][j] = dt[a[j]];														//d[i][j]�s�J�qi��s[i][j]���Z��	
			s[i][j] = v[a[j]];														//s[i][j]�s�J�qi�i�H�쪺�I 
		}
	}
	delete [] u;																	//�⤣�|�Ψ쪺�O�������� 
	delete [] dt;
	delete [] v;
	delete [] a;																	
	
	for (int i = 0; i < k; i++)														//��k�Ӹ��u 
	{
		cin >> nodeCnt;																//��J�o�����u���X���I 
		int *x = new int [nodeCnt];													//���ͪ��׬�nodeCnt���}�C 
		for (int j = 0; j < nodeCnt; j++)											
		{
			cin >> x[j];															//��J�I
		}
		
		pathLen[i] = 0;																//��l��pathLen[i] 
		for (int j = 0; j < nodeCnt-1; j++)											//��qx[0]����x[nodeCnt]������ 
		{
			int num = isNeighbor(x[j], x[j+1], s, count[x[j]]);						//�d��x[j]��x[j+1]�O�_����, �S���^��-1, �����^�ǬOs[x[j]][]�����@���I 
			if (num == -1)										
			{
				pathLen[i] = -1;													//�S�����|���N�O-1 
				break;																//����U�� 
			}
			else
			{
				pathLen[i] += d[x[j]][num];											//�����N�ݨ����, �M�����|�[�_�� 
			}
		}
		delete [] x;																//���񤣥Ϊ��O���� 
	}
	
	for (int i = 0; i < k-1; i++)													//��Xk�Ӹ��|�� 
		cout << pathLen[i] << " ";
	cout << pathLen[k-1];
	
	releaseMemory(pathLen, d, s, count, n+1);										//����ѤU���O���� 
	return 0;
}

void releaseMemory(int *pathLen, int **d, int **s, int *count, int n )				//����ѤU���O����
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

int isNeighbor(int a, int b, int **s, int len)										//��a,b����I���O�_���D��
{
	for (int i = 0; i < len ;i++)													//�bs[a][]����O�_��b�I 
	{
		if (s[a][i] == b)
			return i;																//���h�^��s[a][]���ĴX�� 
	}
	return -1;																		//�S���N�^��-1 
}
