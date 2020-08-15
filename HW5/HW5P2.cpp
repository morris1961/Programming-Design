#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void bigMoneyAdd(char [], char [], int [], int, int );						//宣告大數加法函數
bool bigMoneySub(char [], char [], int [], int, int ,int ,int);						//宣告大數減法函數 

int main()
{	
	const int len=200;														//宣告常數len為陣列長度 
	char m1[len],m2[len],sumc[len],suma[len],diffc[len],diffa[len];			//m1,m2為輸入之兩數字，sumc/diffc為sum/diff轉成char，suma/diffa為加上千分符號之答案 
	int n=0,a=0,b=0,k=0,sum[len]={0},diff[len]={0},count=0;					//n為最大位數上限，a/b為為m1/m2長度，k為在第一個非0數之前有幾個'0'或','，sum/diff為加/減完後的數字，count為有幾個',' 
	bool m1Big;
	cin>>n>>m1>>m2;															//輸入n,m1,m2 
	
	a=strlen(m1);															//找出m1長度 
	int a1=m1[0]=='-'?a-1:a;
	b=strlen(m2);															//找出m2長度
	int b1=m2[0]=='-'?b-1:b;

	if ((m1[0]=='-'&&m2[0]!='-')||(m2[0]=='-'&&m1[0]!='-'))
	{
		m1Big=bigMoneySub(m1,m2,sum,a,b,a1,b1);											//執行bigMoneyAdd 
		for(int i=0;i<=n;i++)													//把sum的值的格式從int改為char 
		{
			sumc[i]=sum[i]+'0';
		}
		bigMoneyAdd(m1,m2,diff,a,b);												//執行bigMoneySub 
		for(int i=0;i<=n;i++)													//把diff的值的格式從int改為char
		{
			diffc[i]=diff[i]+'0';
		}
	}
	else
	{
		bigMoneyAdd(m1,m2,sum,a,b);												//執行bigMoneyAdd 
		for(int i=0;i<=n;i++)													//把sum的值的格式從int改為char 
		{
			sumc[i]=sum[i]+'0';
		}
		m1Big=bigMoneySub(m1,m2,diff,a,b,a1,b1);											//執行bigMoneySub 
		for(int i=0;i<=n;i++)													//把diff的值的格式從int改為char
		{
			diffc[i]=diff[i]+'0';
		}
	}

	
	for(int i=0;i<=n;i++)													//在suma中加',' 跟紀錄有幾個 
	{
		if(i!=0&&i%3==0)													//每三個數會有一個',' 
			count++;														//紀錄有幾個 
		if(i%4==3)															//','加在i%4==3的地方 
		{
			suma[i]=',';
		}
		suma[(i+count)]=sumc[i];											//把sumc的值輸進suma，並避開',' 
	}
	for(int i=n;i<=n+count;i++)												//suma因為多','所以少輸的值從sumc輸入 
	{
		if(i%4==3)															//','加在i%4==3的地方
		{
			suma[i]=',';													
		}
		suma[(i+count)]=sumc[i];
	}
	cout<<"$";									 
	for(int i=n+count;i>=0;i--)												//找出在第一個非0數之前有幾個'0'或','
	{
		
		if(suma[i]=='0'||suma[i]==',')
			k++;															//紀錄為k 
		else
			break;
	}
	if ((m1[0]=='-'||m2[0]=='-')&&((m1Big==false&&m2[0]=='-')||(m1Big&&m1[0]=='-'))&&n-k+count>=0)
		cout<<"-";	
	if(n-k+count<0)																//如果都是'0'或','則輸出0 
		cout<<0;
	else
		for(int i=n-k+count;i>=0;i--)											//把suma倒過來輸出 
			cout<<suma[i];
	
	k=0;																	//重置k	
	count=0;																//重置count
	cout<<endl;																//空行 
	
	for(int i=0;i<=n;i++)													//在diffa中加',' 跟紀錄有幾個 
	{
		if(i!=0&&i%3==0)													//每三個數會有一個','
			count++;														//紀錄有幾個
		if(i%4==3)															//','加在i%4==3的地方
		{
			diffa[i]=',';
		}
		diffa[(i+count)]=diffc[i];											//把diffc的值輸進diffa，並避開','
	}
	for(int i=n;i<=n+count;i++)												//diffa因為多','所以少輸的值從diffc輸入
	{
		if(i%4==3)															//','加在i%4==3的地方															
		{
			diffa[i]=',';
		}
		diffa[(i+count)]=diffc[i];											//把diffc的值輸進diffa，並避開','
	}
	cout<<"$";																 
	for(int i=n+count;i>=0;i--)												//找出在第一個非0數之前有幾個'0'或','
	{
		if(diffa[i]=='0'||diffa[i]==',')									
			k++;															//紀錄為k
		else
			break;
	}
	if (((m1Big==false&&m2[0]!='-')||(m1Big&&m1[0]=='-'))&&n-k+count>=0)
		cout<<"-";
	if(n-k+count<0)																//如果都是'0'或','則輸出0 
		cout<<0;
	else																	//否則把suma倒過來輸出
		for(int i=n-k+count;i>=0;i--)
		{
			cout<<diffa[i];
		}
	return 0;
} 

void bigMoneyAdd(char m1[], char m2[], int sum[],int a,int b)				//函數bigMoneyAdd 
{
	int x[101]={0},y[101]={0};
	int max=a>b?a:b;
	for(int i=0; i<a; i++)													//把m1的值的格式從char改成int
	{
		x[i]=m1[a-i-1]=='-'?0:m1[a-i-1]-'0';
	}
	for(int i=0; i<b; i++)													//把m2的值的格式從char改成int
	{
		y[i]=m2[b-i-1]=='-'?0:m2[b-i-1]-'0';
	}	 
	for(int i=0; i<max; i++)													//把x,y相對應的位數加起來 
	{
		sum[i]=x[i]+y[i];
	}
	for(int i=0; i<max; i++)													//把每個位數都檢查一遍 
	{
   		if(sum[i]>=10) 														//如果有>10的 
		{
     		sum[i+1]+=sum[i]/10;											//下一位數加上進位的數 
     		sum[i]=sum[i]%10;												//這個位數剩下一位數 
 		}
	}
}

bool bigMoneySub(char m1[], char m2[], int diff[], int a, int b,int a1,int b1)			//函數bigMoneyAdd
{
	int x[101]={0},y[101]={0};
	int max=a>b?a:b;
	bool m1Big=true;
	
	for(int i=0; i<a; i++)													//把m1的值的格式從char改成int
	{
		x[i]=m1[a-i-1]=='-'?0:m1[a-i-1]-'0';
	}
	for(int i=0; i<b; i++)													//把m2的值的格式從char改成int
	{
		y[i]=m2[b-i-1]=='-'?0:m2[b-i-1]-'0';
	}	 
	
	if(a1==b1)
	{
		for (int i=0; i<a1;i++)
		{
			if (x[a1-i-1]>y[a1-i-1])
			{
				break;
			}
			else if (x[a1-i-1]<y[a1-i-1])
			{
				m1Big=false;
				break;
			}
		}
	}
	
	for(int i=0; i<max; i++)													//把x減掉y相對應的位數
	{
		if (m1Big||a1>b1)
			diff[i]=x[i]-y[i];
		else
			diff[i]=y[i]-x[i];
	}
	for(int i=0; i<max-1; i++)												//把每個位數都檢查一遍
	{
   		 if(diff[i]<0) 														//如果有<0的
		{
			diff[i+1]--;													//下一位數減1 
	     	diff[i]=10+diff[i];												//這個位數加10 	
 		}
	}
	return m1Big;
}
