#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
                         
int main()
{
    const int LEN=1000;
    int count=0;
    char pun[10]=",.:;!?";
    char a[LEN];
    cin.getline(a,LEN);
    char *p;
    
    for (int i=0;i<6;i++)
    {
    	p=strchr(a,pun[i]);
		while (p!=nullptr)
		{
			count++;
			*p='_';
			p=strchr(p,pun[i]);
		}
	}
	//cout<<pun;
    cout<<count;
    return 0;
}
 
