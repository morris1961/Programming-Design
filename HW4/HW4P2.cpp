#include <iostream>
#include <cstring>
using namespace std;

void bigMoneyAdd(char [], char [], int [], int, int );						//�ŧi�j�ƥ[�k���
void bigMoneySub(char [], char [], int [], int, int );						//�ŧi�j�ƴ�k��� 

int main()
{	
	const int len=200;														//�ŧi�`��len���}�C���� 
	char m1[len],m2[len],sumc[len],suma[len],diffc[len],diffa[len];			//m1,m2����J����Ʀr�Asumc/diffc��sum/diff�নchar�Asuma/diffa���[�W�d���Ÿ������� 
	int n=0,a=0,b=0,k=0,sum[len]={0},diff[len]={0},count=0;					//n���̤j��ƤW���Aa/b����m1/m2���סAk���b�Ĥ@�ӫD0�Ƥ��e���X��'0'��','�Asum/diff���[/��᪺�Ʀr�Acount�����X��',' 
	
	cin>>n>>m1>>m2;															//��Jn,m1,m2 
	
	a=strlen(m1);															//��Xm1���� 
	b=strlen(m2);															//��Xm2����
	
	bigMoneyAdd(m1,m2,sum,a,b);												//����bigMoneyAdd 
	for(int i=0;i<=n;i++)													//��sum���Ȫ��榡�qint�אּchar 
	{
		sumc[i]=sum[i]+'0';
	}
	bigMoneySub(m1,m2,diff,a,b);											//����bigMoneySub 
	for(int i=0;i<=n;i++)													//��diff���Ȫ��榡�qint�אּchar
	{
		diffc[i]=diff[i]+'0';
	}
	
	for(int i=0;i<=n;i++)													//�bsuma���[',' ��������X�� 
	{
		if(i!=0&&i%3==0)													//�C�T�ӼƷ|���@��',' 
			count++;														//�������X�� 
		if(i%4==3)															//','�[�bi%4==3���a�� 
		{
			suma[i]=',';
		}
		suma[(i+count)]=sumc[i];											//��sumc���ȿ�isuma�A���׶}',' 
	}
	for(int i=n;i<=n+count;i++)												//suma�]���h','�ҥH�ֿ骺�ȱqsumc��J 
	{
		if(i%4==3)															//','�[�bi%4==3���a��
		{
			suma[i]=',';													
		}
		suma[(i+count)]=sumc[i];
	}
	cout<<"$";																//��X$ 
	for(int i=n+count;i>=0;i--)												//��X�b�Ĥ@�ӫD0�Ƥ��e���X��'0'��','
	{
		
		if(suma[i]=='0'||suma[i]==',')
			k++;															//������k 
		else
			break;
	}
	if(n==k-1)																//�p�G���O'0'��','�h��X0 
		cout<<0;
	else
		for(int i=n-k+count;i>=0;i--)											//��suma�˹L�ӿ�X 
			cout<<suma[i];
	
	k=0;																	//���mk	
	count=0;																//���mcount
	cout<<endl;																//�Ŧ� 
	
	for(int i=0;i<=n;i++)													//�bdiffa���[',' ��������X�� 
	{
		if(i!=0&&i%3==0)													//�C�T�ӼƷ|���@��','
			count++;														//�������X��
		if(i%4==3)															//','�[�bi%4==3���a��
		{
			diffa[i]=',';
		}
		diffa[(i+count)]=diffc[i];											//��diffc���ȿ�idiffa�A���׶}','
	}
	for(int i=n;i<=n+count;i++)												//diffa�]���h','�ҥH�ֿ骺�ȱqdiffc��J
	{
		if(i%4==3)															//','�[�bi%4==3���a��															
		{
			diffa[i]=',';
		}
		diffa[(i+count)]=diffc[i];											//��diffc���ȿ�idiffa�A���׶}','
	}
	cout<<"$";																//��X$ 
	for(int i=n+count;i>=0;i--)												//��X�b�Ĥ@�ӫD0�Ƥ��e���X��'0'��','
	{
		if(diffa[i]=='0'||diffa[i]==',')									
			k++;															//������k
		else
			break;
	}
	if(n==k-1)																//�p�G���O'0'��','�h��X0 
		cout<<0;
	else																	//�_�h��suma�˹L�ӿ�X
		for(int i=n-k+count;i>=0;i--)
		{
			cout<<diffa[i];
		}
	return 0;
} 

void bigMoneyAdd(char m1[], char m2[], int sum[],int a,int b)				//���bigMoneyAdd 
{
	int x[101]={0},y[101]={0};
	for(int i=0; i<a; i++)													//��m1���Ȫ��榡�qchar�令int
	{
		x[i]=m1[a-i-1]-'0';
	}
	for(int i=0; i<b; i++)													//��m2���Ȫ��榡�qchar�令int
	{
		y[i]=m2[b-i-1]-'0';
	}	 
	for(int i=0; i<a; i++)													//��x,y�۹�������ƥ[�_�� 
	{
		sum[i]=x[i]+y[i];
	}
	for(int i=0; i<a; i++)													//��C�Ӧ�Ƴ��ˬd�@�M 
	{
   		if(sum[i]>=10) 														//�p�G��>10�� 
		{
     		sum[i+1]+=sum[i]/10;											//�U�@��ƥ[�W�i�쪺�� 
     		sum[i]=sum[i]%10;												//�o�Ӧ�ƳѤU�@��� 
 		}
	}
}

void bigMoneySub(char m1[], char m2[], int diff[], int a, int b)			//���bigMoneyAdd
{
	int x[101]={0},y[101]={0};
	for(int i=0; i<a; i++)													//��m1���Ȫ��榡�qchar�令int
	{
		x[i]=m1[a-i-1]-'0';
	}
	for(int i=0; i<b; i++)													//��m2���Ȫ��榡�qchar�令int
	{
		y[i]=m2[b-i-1]-'0';
	}	 
	for(int i=0; i<a; i++)													//��x�y�۹��������
	{
		diff[i]=x[i]-y[i];
	}
	for(int i=0; i<a-1; i++)												//��C�Ӧ�Ƴ��ˬd�@�M
	{
   		if(diff[i]<0) 														//�p�G��<0��
		{
     		diff[i+1]--;													//�U�@��ƴ�1 
     		diff[i]=10+diff[i];												//�o�Ӧ�ƥ[10 
 		}
	}
}
