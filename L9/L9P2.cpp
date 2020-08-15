#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;
                         
int main()
{
    const int LEN = 1000;
    char a[LEN];
    cin.getline(a,LEN);
	for (int i = 0; i < strlen(a); i++)
	{
		a[i] = tolower(a[i]);
		if (i == 0 || a[i-1] == ' ')
			a[i] = toupper(a[i]);
	}
	cout<<a;
    return 0;
}
 
