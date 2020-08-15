#include <iostream>
#include <cmath>
using namespace std;


int main ()
{
	const int MAX_M=11; 												//�ŧi�`��MAX_M��m���̤j�� 
	int n=0,m=0;														//n��ܦ�(n+1)^2�Ӯy��, m���X�ӫ¯��I 
	int x[MAX_M]={0},y[MAX_M]={0},r[MAX_M]={0},p[MAX_M]={0};			//x[i]����i�ӫ¯��I��x�y��, y[i]����i�ӫ¯��I��y�y�� 
																		//r[i]����i�ӫ¯��I���b�|, p[i]����i�ӫ¯��I���¯ٵ{�� 
	cin>>n>>m;															//��Jn,m 
	for (int i=0;i<m;i++)												//��Jx 
	{
		cin>>x[i];
	}
	for (int i=0;i<m;i++)												//��Jy
	{
		cin>>y[i];
	}
	for (int i=0;i<m;i++)												//��Jr
	{
		cin>>r[i];
	}
	for (int i=0;i<m;i++)												//��Jp
	{
		cin>>p[i];
	}
	
	double an=-1;														//�����̤j���I��, �]���@�I�����I��>=0, �ҥH�����]�̤j��-1 
	int x1=0,y1=0;														//x1�����̤j���I��x�y��, y1�����̤j���I��y�y��
	for (int i=0;i<=n;i++)												//��x�y�� 
	{
		for (int j=0;j<=n;j++)											//��y�y�� 
		{
			double temp1=0;												//temp1�����I(i,j)�����I 
			for (int k=0;k<m;k++)
			{
				double temp2=0;											//temp2�����I(x[k],y[k])���I(i,j)�y�������I 
				temp2=p[k]*(r[k]-sqrt((x[k]-i)*(x[k]-i)+(y[k]-j)*(y[k]-j)))/r[k];
				if (temp2>0)											//�p�G�I(x[k],y[k])���I(i,j)�y�������I>0�~���[�` 
					temp1+=temp2;
			}
			cout<<i<<" "<<j<<" "<<temp1<<endl;
			if (temp1>an)												//��̤j���I�ðO���ӭ��I�ȥH���I�y�� 
			{
				an=temp1;
				x1=i;
				y1=j;
			}
		}
	}
	cout<<x1<<" "<<y1;													//��X�I�y�� 
	
	return 0;
} 
