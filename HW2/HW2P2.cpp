#include <iostream>
using namespace std;

int main()
{
	int x=0,y=0;
	cin>>x>>y;										//��J��Ӽ� 
	bool f=true;										 
	if(x>y)	      									//���x��y���j�p 
	{
		cout<<x<<" "<<y<<":";						//����Xx�b��Xy 
	}
	else
	{
		cout<<y<<" "<<x<<":";						//����Xy�b��Xx
	}
	while(true)										//�j�鰵������ 
	{
    	if(x>=y)									//���x��y���j�p 
    	{
    		x=x%y;									//x=(x/y���l��)		
    		if (f)									//�Ĥ@����X���n�Ů� 
			{
				cout<<x;
				f=false;
			}
			else									//����n�Ů�
				cout <<" "<<x;						  
			if(x==0||y%x==0)						//x=0�Τw�g�㰣�N����j��	
    			break;
		}
		else
		{
			y=y%x;									//y=(y/x���l��)
			if (f)									//�Ĥ@����X���n�Ů� 
			{
				cout<<y;
				f=false;
			}
			else									//����n�Ů�
				cout <<" "<<y;						 
			if(y==0||x%y==0)						//�p�Gy=0�Τw�g�㰣�N����j��	
    			break;
		}
		
	}
	cout<<".";										//�[�W�y�� 
	return 0 ;
}
