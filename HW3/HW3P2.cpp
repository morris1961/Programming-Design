#include <iostream>
using namespace std;

int main()
{
	int n = 0,m = 0,s = 0,d = 0,a[101][101] = {0},t = 0,x[4] = {0};			//�ŧi�ܼ�n���`���ơAm���̦h�U�����ơAs���_�l���Ad�����I�� 
																			//a[i][j]���q��j�����i+1��������At�qs~d����O�Ax[i]����i���U���U���� 
	cin >> n >> m >> s >> d;												//��Jn,m,s,d 
	
	for(int i = 1;i < n;i++)												//��Ja[i][j] 
	{
		for(int j = 1;j <= i;j++)
		{
			cin >> a[i][j];
		}
	} 
	
	int min = a[d - 1][s];													//���]�̧C���欰�qs������d������ 
	
	for(int y = 1;y <= m ;y++)												//�Hm�ȨM�w�i�U���X�� 
	{
		switch (y)															//�M�w�o���n�U���X�� 
		{
			case(1):														//�U�@�� 
			{
				for(int i = s;i < d - 1;i++)									//�Ĥ@���qs+1���U��d-1�� 
				{	
					t = a[i][s] + a[d - 1][i + 1];								//�����[�_�� 
					if(min > t)												//�p�G������p 
					{
						min = t;											//�������� 
						x[1] = i + 1;										//�����Ĥ@���U���� 
					}
				}
				break;
			}
			case(2):														//�U�⦸ 
			{
				for(int j = s;j < d - 2;j++)								//�Ĥ@���qs+1�U��d-2 
				{
					for(int i = j + 1;i < d - 1;i++)						//�ĤG���qj+1�U��d-1�� 
					{
						t = a[j][s] + a[i][j + 1] + a[d - 1][i + 1];		//�����[�_��
						if(min > t)											//�p�G������p
						{
							min = t;										//��������
							x[1] = j + 1;									//�����Ĥ@���U����
							x[2] = i + 1;									//�����ĤG���U����
						}
					}
				}
				break;
			}
			case(3):														//�U�T�� 
			{
				for(int k = s;k < d - 3;k++)								//�Ĥ@���qs+1�U��d-3�� 
				{
					for(int j = k + 1;j < d - 2;j++)						//�ĤG���qk+1�U��d-2��
					{
						for(int i = j + 1;i < d - 1;i++)					//�ĤT���qj+1�U��d-1��
						{
							t = a[k][s] + a[j][k + 1] + a[i][j + 1] + a[d - 1][i + 1];		//�����[�_��
							if(min > t)										//�p�G������p
							{
								min = t;									//��������
								x[1] = k + 1;								//�����Ĥ@���U����
								x[2] = j + 1;								//�����ĤG���U����
								x[3] = i + 1;								//�����ĤT���U����
							}
						}
					}
				}
				break;
			}
		}
	}
	
	cout << x[1];															//��X�Ĥ@���U����(�p�G�S�U�h�|��X�ŧi���ȹs) 
	for(int i = 2;i <= m;i++)												//��X�ĤG�B�T���U���� 
	{		
		if(x[i] != 0)														//�p�G���U�~��X 
			cout << " " << x[i];
	}
	cout << " " << min;														//��X�̤p���� 
	
	return 0 ;
}
