#include <iostream>
using namespace std;

int main()
{
	int x=0,y=0;
	cin>>x>>y;										//輸入兩個數 
	bool f=true;										 
	if(x>y)	      									//比較x跟y的大小 
	{
		cout<<x<<" "<<y<<":";						//先輸出x在輸出y 
	}
	else
	{
		cout<<y<<" "<<x<<":";						//先輸出y在輸出x
	}
	while(true)										//迴圈做未知次 
	{
    	if(x>=y)									//比較x跟y的大小 
    	{
    		x=x%y;									//x=(x/y的餘數)		
    		if (f)									//第一次輸出不要空格 
			{
				cout<<x;
				f=false;
			}
			else									//之後要空格
				cout <<" "<<x;						  
			if(x==0||y%x==0)						//x=0或已經整除就停止迴圈	
    			break;
		}
		else
		{
			y=y%x;									//y=(y/x的餘數)
			if (f)									//第一次輸出不要空格 
			{
				cout<<y;
				f=false;
			}
			else									//之後要空格
				cout <<" "<<y;						 
			if(y==0||x%y==0)						//如果y=0或已經整除就停止迴圈	
    			break;
		}
		
	}
	cout<<".";										//加上句號 
	return 0 ;
}
