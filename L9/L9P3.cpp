#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;
                         
int main()
{
  	const int Len = 1001;
  	char a[Len],b[Len];
  	cin.getline(a,Len);
  	cin.getline(b,Len);
  	for (int i = 0;i < strlen(a); i++)
  	{
  		a[i]=toupper(a[i]);
	}
	for (int i = 0;i < strlen(b); i++)
  	{
  		b[i]=toupper(b[i]);
	}
  	char *p=strstr(a,b);
  	if (p!=nullptr)
  		cout<<1;
  	else 
 		cout<<0;
  		
  	
    return 0;
}
 
