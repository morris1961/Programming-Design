#include <iostream>
using namespace std;

double Expect (int, double[], int, int, int);								//宣告算期望值的函數 

int main()
{
	int c=0,r=0,N=0,answer1=0;											//進貨價格為c, 零售價格為r, 最多賣N份報紙,answer1為賣幾分最賺 
	double a[9]={0},p[9]={0},answer2=0;									//a[i]為進i份報紙的預期利潤, p[i]為會有i個人來買報紙的機率, answer2為最賺的利潤 
	cin>>c>>r>>N;														//輸入各項數字 
	for (int i=0;i<=N;i++)
		cin>>p[i];
	
	for (int i=0;i<=N;i++)												//分別紀錄0~N個人來買報紙的預期利潤 
	{
		a[i]=Expect(i,p,c,r,N);											//呼叫Expect計算i個人買報紙的預期利潤並記錄為a[i] 
		if (answer2<a[i])												//找出最大的預期利潤 
		{
			answer2=a[i];
			answer1=i;
		}
	}
	cout<<answer1<<" "<< static_cast<int>( answer2);					//印出答案並將answer2 cast成int 
	return 0;
}

double Expect(int i, double p[], int c, int r,int N)					//傳入有i個人買報紙, p[i]會有i個人來買報紙的機率, 進貨價格為c, 零售價格為r, 最多可能有N個人買 
{
	double a=0,psum=0;													//a為會回傳的預期利潤期望值, psum為第i~N個人會來買的機率的加總 
	for (int j=0;j<i;j++)												//先算出有0個到有i-1個人來買的預期利潤期望值, 並加起來 
	{
		a+=p[j]*(j*r-i*c);
		
	}
	for (int j=i;j<=N;j++)												//再算出有i個人來買的預期利潤期望值
	{
		psum+=p[j];
	}
	a+=psum*(i*(r-c));													//將預期利潤期望值加起來 
	return a;															//回傳有i個人買報紙時的預期利潤期望值
}
