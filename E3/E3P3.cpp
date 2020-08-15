#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char word[10001] = {0};
	cin.getline(word, 10001);
	char dleI[] ="I", dlea[] ="a", dlethe[] ="the", dleThe[] ="The", dle[] = " ,.";
	int countI = 0, counta = 0, countthe = 0;
	
	int count = 0;
	char *tok = strtok(word, dle);
	while(tok != nullptr)
	{
		if(strcmp(tok, dleI) == 0)
			countI++;
		else if (strcmp(tok, dlea) == 0)
			counta++;
		else if (strcmp(tok, dlethe) == 0)
			countthe++;
		else if (strcmp(tok, dleThe) == 0)
			countthe++;
		tok = strtok(nullptr, dle);
	}
	cout << countI << " " << counta << " " << countthe; 
	return 0;
}
