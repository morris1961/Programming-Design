#include <iostream>
using namespace std;

double Expect (int, double[], int, int, int);								//�ŧi�����Ȫ���� 

int main()
{
	int c=0,r=0,N=0,answer1=0;											//�i�f���欰c, �s����欰r, �̦h��N������,answer1����X������ 
	double a[9]={0},p[9]={0},answer2=0;									//a[i]���ii�����Ȫ��w���Q��, p[i]���|��i�ӤH�ӶR���Ȫ����v, answer2�����Ȫ��Q�� 
	cin>>c>>r>>N;														//��J�U���Ʀr 
	for (int i=0;i<=N;i++)
		cin>>p[i];
	
	for (int i=0;i<=N;i++)												//���O����0~N�ӤH�ӶR���Ȫ��w���Q�� 
	{
		a[i]=Expect(i,p,c,r,N);											//�I�sExpect�p��i�ӤH�R���Ȫ��w���Q��ðO����a[i] 
		if (answer2<a[i])												//��X�̤j���w���Q�� 
		{
			answer2=a[i];
			answer1=i;
		}
	}
	cout<<answer1<<" "<< static_cast<int>( answer2);					//�L�X���רñNanswer2 cast��int 
	return 0;
}

double Expect(int i, double p[], int c, int r,int N)					//�ǤJ��i�ӤH�R����, p[i]�|��i�ӤH�ӶR���Ȫ����v, �i�f���欰c, �s����欰r, �̦h�i�঳N�ӤH�R 
{
	double a=0,psum=0;													//a���|�^�Ǫ��w���Q������, psum����i~N�ӤH�|�ӶR�����v���[�` 
	for (int j=0;j<i;j++)												//����X��0�Ө즳i-1�ӤH�ӶR���w���Q������, �å[�_�� 
	{
		a+=p[j]*(j*r-i*c);
		
	}
	for (int j=i;j<=N;j++)												//�A��X��i�ӤH�ӶR���w���Q������
	{
		psum+=p[j];
	}
	a+=psum*(i*(r-c));													//�N�w���Q�����ȥ[�_�� 
	return a;															//�^�Ǧ�i�ӤH�R���Ȯɪ��w���Q������
}
