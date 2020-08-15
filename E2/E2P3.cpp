#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
	const int LEN = 101;
	char x[LEN] = {0}, mode[3];
	cin.getline(mode,3);
	cin.getline(x, 101);
	for (int i = 0; i < strlen(x); i++)
		x[i] = tolower(x[i]);
	
	if (mode[0] == 'R')
	{
		char *p = strchr(x,' ');
		p = strchr(p+1, ' ');
		*p = '\0';
		x[0] = toupper(x[0]);
		cout << x;
		cout << " not ";
		cout << p+1;
	}
	
	if (mode[0] == 'Q')
	{
		char *two = strchr(x,' ');
		*two = '\0';
		char *third = strchr(two+1, ' ');
		*third = '\0';
		two[1] = toupper(two[1]);
		cout << two+1 << " ";
		cout << x << " ";
		cout << third+1;
	}
	return 0;
}
