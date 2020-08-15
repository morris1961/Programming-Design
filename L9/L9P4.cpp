#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;
                         
int main()
{
	bool a = true;
  	const int Len = 51;
  	int n=0, answer=0;
  	cin >> n;
  	char **D = new char *[n];
  	
 	char x[Len];
	cin >> x;
	for (int i = 0; i < strlen(x); i++)
		x[i]=tolower(x[i]);
		
	for (int i = 0; i < n; i++)
	{
		D[i] = new char [Len];
		cin >> D[i];
		//cin.getline(D[i],Len); 
		//cout << D[i] << endl;
	}
	
	for (int i = 0; i < n; i++)
	{
		answer =  strcmp(x,D[i]) ;
		if (answer == 0)
		{
			cout << 1;
			a = false;
		}
	}
	if (a)
		cout << 0;
    return 0;
}


