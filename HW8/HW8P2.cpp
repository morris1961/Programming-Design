#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

bool checkDate(char *date, char *ds, char *de);											//確認date是否在ds與de之間 
int checkWord(char **source, char *x, int num);											//確認x是否在source[num]之前出現過, 在source[i]出現則回傳i, 沒出現過則回傳num 
void insertionSort(char **x, int y[], int len);											//把x做insertionSort, 相對應的y一起跟著改 
void releasememory(char **a ,char **b, int c[], int d[], int n);						//釋放動態記憶體 
              
const int WORD_LEN = 51;																//輸入字串長度限制 
const int DATE_LEN = 9;																	//日期長度限制 
const int DIGIT_LEN = 4;																//銷售量位數限制 
			             
int main()
{
	int n = 0;																			//n為多少個交易紀錄 
	char ds[10] = {0}, de[10] = {0};													//ds/de為起訖日期 
	cin >> n >> ds >> de;
	char **w = new char *[n], **answerWord = new char *[n];								//w為商品名字的字串, answerWord為答案會有的商品的字串 
	int *sales = new int [n], *answerSales = new int [n];								//sales為賣出某個商品的銷售量, answerSales為商品有在answerWord的銷售量 
	
	for (int i = 0; i < n; i++)															//分析n筆交易 
	{
		char x[WORD_LEN] = {0};															//x為儲存交易資料用 
		w[i] = new char [WORD_LEN];														//w[i]儲存第i筆交易的商品名字 
		char date[DATE_LEN] = {0}, digit[DIGIT_LEN] = {0};								//date[i]儲存第i筆交易的時間, digit[i]儲存第i筆交易的銷售量(以字串) 
		sales[i] = 0;																	//假設第i筆交易的銷售量為0 
		cin >> x;
		
		char *start = strtok(x,",");													//以逗點分割字串 
		strcpy(w[i],start);																//第一段存入w[i] 
		for (int j = 0; j < strlen(w[i]); j++)											//把w[i]轉為小寫 
		{
			w[i][j] = tolower(w[i][j]);
		}
		start = strtok(nullptr,",");
		strcpy(date, start);															//第二段存入date[i] 
		start = strtok(nullptr,",");
		strcpy(digit, start);															//第三段存入digit[i] 
		if (checkDate(date, ds, de))													//檢查date是否在ds與de之間 
		{
			int num = checkWord(w, w[i], i);											//回傳w[i]這個商品名字在第1筆到第i筆之中的第幾筆出現過 
			sales[num] += atoi(digit);													//各商品名字第一次出現在第幾筆, 就以該筆的sales做累加 
		}
	}
	
	int count=0;																		//count紀錄有幾個不同的商品名稱 
	for (int i = 0; i < n; i++)															//分析sales[0]到sales[n] 
	{
		answerWord[i] = new char [WORD_LEN];											//answerWord[i]儲存商品名字 
		if (sales[i] != 0)																//如果第i筆交易的商品前面出現過, 那sales[i]就會等於0, 所以把不等於的挑出來 
		{
			strcpy(answerWord[count],w[i]);												//把w[i]複製到answerWord[count]裡 
			answerSales[count] = sales[i];												//sales也是 
			count++;																	//每做一次count就加一 
		}	
	}
	
	insertionSort(answerWord, answerSales, count);										//排列一下答案 
	for (int i = 0; i < count; i++)														//輸出答案 
		cout << answerWord[i] << ":" << answerSales[i] << endl;	
		
	releasememory(w, answerWord, sales, answerSales, n);								//釋放記憶體 
    return 0;
}
 
bool checkDate(char *date, char *ds, char *de)
{
	int x = atoi(date);																	//把三個日期都轉成整數 
	int s = atoi(ds);
	int e = atoi(de);
	if (s <= x && x <= e)																//如果在date在ds與de中 
		return true;																	//就回傳true 
	else
		return false;																	//否則回傳false 
}

int checkWord(char **source, char *x, int num)											//找第一次出現x是在第幾筆資料 
{
	char *tp1 = nullptr;
	tp1 = strchr(x,'-');																//先找有沒有- 
	if (tp1 != nullptr)																	//如果有 
	{
		char *tp2 = strtok(x,"-");
		tp2 = strtok(nullptr,"-");															//就分割取後面的字串 
		if (strcmp(tp2,"vip") == 0 || strcmp(tp2,"special") == 0 || strcmp(tp2,"old") == 0) //看是不是vip或是special或是old 
			*tp1 = '\0';																	//是的話就把-改成\0, 這樣xxx-vip就變成xxx 
		else
			*tp1 = '-';																		//不是的話就還是- 
	}

	for (int i = 0; i < num; i++)														//在num之前的交易找 
	{
		if (strcmp(source[i],x) == 0)													//找到第一次出現x時是第i筆交易 
		{
			return i;																	//就回傳i 
		}
	}
	return num;																			//找不到就回傳num, 也就是這次就是第一次出現 
}

void insertionSort(char **x, int y[], int len)											//對x做insertionsort, y只是跟著改動 
{
	for (int i = 0; i < len; i++)														//從第一項開始做到最後一項 
	{
		for (int j = i; j > 0; j--)														//做第i項時, 找i前面的 
		{
			int cmp = strcmp(x[j-1], x[j]);												//比較x[j-1],x[j]的大小 
			if (cmp >= 0)																//如果x[j]比小 
			{
				char temp1 [WORD_LEN] = {0}; 											//就交換位子 
				strcpy(temp1, x[j-1]);
				strcpy(x[j-1], x[j]);
				strcpy(x[j], temp1);
				int temp2 = y[j-1];														//y跟著改 
				y[j-1] = y[j];
				y[j] = temp2;
			}
			else																		//否則就換下一個i 
				break;
		}
	}
}

void releasememory(char **a ,char **b, int c[], int d[], int n)							//清除動態配置記憶體～ 
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
