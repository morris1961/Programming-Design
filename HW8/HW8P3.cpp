#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

bool checkDate(char *date, char *ds, char *de);											 
int checkWord(char **source, char *x, int num);											 
void insertionSort(char **x, int y[], int len);											
void releasememory(char **a ,char **b, int c[], int d[], int n);						 
              
const int WORD_LEN = 51;																 
const int DATE_LEN = 9;																	 
const int DIGIT_LEN = 4;																 
			             
int main()
{
	int n = 0;																			 
	char ds[10] = {0}, de[10] = {0};													 
	cin >> n >> ds >> de;
	char **w = new char *[n], **answerWord = new char *[n];								 
	int *sales = new int [n], *answerSales = new int [n];								 
	
	for (int i = 0; i < n; i++)															 
	{
		char x[WORD_LEN] = {0};															 
		w[i] = new char [WORD_LEN];														 
		char date[DATE_LEN] = {0}, digit[DIGIT_LEN] = {0};								 
		sales[i] = 0;																	 
		cin >> x;
		
		char *start = strtok(x,",");													 
		strcpy(w[i],start);																 
		for (int j = 0; j < strlen(w[i]); j++)											
		{
			w[i][j] = tolower(w[i][j]);
		}
		start = strtok(nullptr,",");
		strcpy(date, start);															 
		start = strtok(nullptr,",");
		strcpy(digit, start);															 
		if (checkDate(date, ds, de))													 
		{
			int num = checkWord(w, w[i], i);											 
			sales[num] += atoi(digit);													 
		}
	}
	
	int count=0;																		 
	for (int i = 0; i < n; i++)															 
	{
		answerWord[i] = new char [WORD_LEN];											 
		if (sales[i] != 0)																 
		{
			strcpy(answerWord[count],w[i]);												
			answerSales[count] = sales[i];												 
			count++;																	 
		}	
	}
	
	insertionSort(answerWord, answerSales, count);										 
	for (int i = 0; i < count; i++)														 
		cout << answerWord[i] << ":" << answerSales[i] << endl;	
		
	releasememory(w, answerWord, sales, answerSales, n);								 
    return 0;
}
 
bool checkDate(char *date, char *ds, char *de)
{
	int x = atoi(date);																	 
	int s = atoi(ds);
	int e = atoi(de);
	if (s <= x && x <= e)																 
		return true;																	 
	else
		return false;																	 
}

int checkWord(char **source, char *x, int num)											 
{
	char *tp1 = x;
//	tp1 = strchr(x,'-');
	while (true)
	{
		tp1 = strchr(tp1+1,'-');
		//cout << tp1 << endl;
		if (tp1 == nullptr ||strchr(tp1+1,'-') == nullptr)
			break;
	}															 
	if (tp1 != nullptr)																	 
	{
//		char *tp2 = strtok(x,"-");
//		tp2 = strtok(nullptr,"-");															 
		if (strcmp(tp1+1,"vip") == 0 || strcmp(tp1+1,"special") == 0 || strcmp(tp1+1,"old") == 0)  
			*tp1 = '\0';																	 
		else
			*tp1 = '-';																		 
	}

	for (int i = 0; i < num; i++)														 
	{
		if (strcmp(source[i],x) == 0)													 
		{
			return i;																	 
		}
	}
	return num;																			 
}

void insertionSort(char **x, int y[], int len)											 
{
	for (int i = 0; i < len; i++)														 
	{
		for (int j = i; j > 0; j--)														 
		{
			int cmp = strcmp(x[j-1], x[j]);												 
			if (cmp >= 0)																 
			{
				char temp1 [WORD_LEN] = {0}; 											
				strcpy(temp1, x[j-1]);
				strcpy(x[j-1], x[j]);
				strcpy(x[j], temp1);
				int temp2 = y[j-1];														 
				y[j-1] = y[j];
				y[j] = temp2;
			}
			else																		 
				break;
		}
	}
}

void releasememory(char **a ,char **b, int c[], int d[], int n)							 
{
	for (int i = 0; i < n; i++)
	{
		delete [] a[i];
		delete [] b[i];
	}
	delete [] a;
	delete [] b;
	delete [] c;
	delete [] d;
}
