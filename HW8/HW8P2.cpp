#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

bool checkDate(char *date, char *ds, char *de);											//�T�{date�O�_�bds�Pde���� 
int checkWord(char **source, char *x, int num);											//�T�{x�O�_�bsource[num]���e�X�{�L, �bsource[i]�X�{�h�^��i, �S�X�{�L�h�^��num 
void insertionSort(char **x, int y[], int len);											//��x��insertionSort, �۹�����y�@�_��ۧ� 
void releasememory(char **a ,char **b, int c[], int d[], int n);						//����ʺA�O���� 
              
const int WORD_LEN = 51;																//��J�r����׭��� 
const int DATE_LEN = 9;																	//������׭��� 
const int DIGIT_LEN = 4;																//�P��q��ƭ��� 
			             
int main()
{
	int n = 0;																			//n���h�֭ӥ������ 
	char ds[10] = {0}, de[10] = {0};													//ds/de���_�W��� 
	cin >> n >> ds >> de;
	char **w = new char *[n], **answerWord = new char *[n];								//w���ӫ~�W�r���r��, answerWord�����׷|�����ӫ~���r�� 
	int *sales = new int [n], *answerSales = new int [n];								//sales����X�Y�Ӱӫ~���P��q, answerSales���ӫ~���banswerWord���P��q 
	
	for (int i = 0; i < n; i++)															//���Rn����� 
	{
		char x[WORD_LEN] = {0};															//x���x�s�����ƥ� 
		w[i] = new char [WORD_LEN];														//w[i]�x�s��i��������ӫ~�W�r 
		char date[DATE_LEN] = {0}, digit[DIGIT_LEN] = {0};								//date[i]�x�s��i��������ɶ�, digit[i]�x�s��i��������P��q(�H�r��) 
		sales[i] = 0;																	//���]��i��������P��q��0 
		cin >> x;
		
		char *start = strtok(x,",");													//�H�r�I���Φr�� 
		strcpy(w[i],start);																//�Ĥ@�q�s�Jw[i] 
		for (int j = 0; j < strlen(w[i]); j++)											//��w[i]�ର�p�g 
		{
			w[i][j] = tolower(w[i][j]);
		}
		start = strtok(nullptr,",");
		strcpy(date, start);															//�ĤG�q�s�Jdate[i] 
		start = strtok(nullptr,",");
		strcpy(digit, start);															//�ĤT�q�s�Jdigit[i] 
		if (checkDate(date, ds, de))													//�ˬddate�O�_�bds�Pde���� 
		{
			int num = checkWord(w, w[i], i);											//�^��w[i]�o�Ӱӫ~�W�r�b��1�����i���������ĴX���X�{�L 
			sales[num] += atoi(digit);													//�U�ӫ~�W�r�Ĥ@���X�{�b�ĴX��, �N�H�ӵ���sales���֥[ 
		}
	}
	
	int count=0;																		//count�������X�Ӥ��P���ӫ~�W�� 
	for (int i = 0; i < n; i++)															//���Rsales[0]��sales[n] 
	{
		answerWord[i] = new char [WORD_LEN];											//answerWord[i]�x�s�ӫ~�W�r 
		if (sales[i] != 0)																//�p�G��i��������ӫ~�e���X�{�L, ��sales[i]�N�|����0, �ҥH�⤣���󪺬D�X�� 
		{
			strcpy(answerWord[count],w[i]);												//��w[i]�ƻs��answerWord[count]�� 
			answerSales[count] = sales[i];												//sales�]�O 
			count++;																	//�C���@��count�N�[�@ 
		}	
	}
	
	insertionSort(answerWord, answerSales, count);										//�ƦC�@�U���� 
	for (int i = 0; i < count; i++)														//��X���� 
		cout << answerWord[i] << ":" << answerSales[i] << endl;	
		
	releasememory(w, answerWord, sales, answerSales, n);								//����O���� 
    return 0;
}
 
bool checkDate(char *date, char *ds, char *de)
{
	int x = atoi(date);																	//��T�Ӥ�����ন��� 
	int s = atoi(ds);
	int e = atoi(de);
	if (s <= x && x <= e)																//�p�G�bdate�bds�Pde�� 
		return true;																	//�N�^��true 
	else
		return false;																	//�_�h�^��false 
}

int checkWord(char **source, char *x, int num)											//��Ĥ@���X�{x�O�b�ĴX����� 
{
	char *tp1 = nullptr;
	tp1 = strchr(x,'-');																//���䦳�S��- 
	if (tp1 != nullptr)																	//�p�G�� 
	{
		char *tp2 = strtok(x,"-");
		tp2 = strtok(nullptr,"-");															//�N���Ψ��᭱���r�� 
		if (strcmp(tp2,"vip") == 0 || strcmp(tp2,"special") == 0 || strcmp(tp2,"old") == 0) //�ݬO���Ovip�άOspecial�άOold 
			*tp1 = '\0';																	//�O���ܴN��-�令\0, �o��xxx-vip�N�ܦ�xxx 
		else
			*tp1 = '-';																		//���O���ܴN�٬O- 
	}

	for (int i = 0; i < num; i++)														//�bnum���e������� 
	{
		if (strcmp(source[i],x) == 0)													//���Ĥ@���X�{x�ɬO��i����� 
		{
			return i;																	//�N�^��i 
		}
	}
	return num;																			//�䤣��N�^��num, �]�N�O�o���N�O�Ĥ@���X�{ 
}

void insertionSort(char **x, int y[], int len)											//��x��insertionsort, y�u�O��ۧ�� 
{
	for (int i = 0; i < len; i++)														//�q�Ĥ@���}�l����̫�@�� 
	{
		for (int j = i; j > 0; j--)														//����i����, ��i�e���� 
		{
			int cmp = strcmp(x[j-1], x[j]);												//���x[j-1],x[j]���j�p 
			if (cmp >= 0)																//�p�Gx[j]��p 
			{
				char temp1 [WORD_LEN] = {0}; 											//�N�洫��l 
				strcpy(temp1, x[j-1]);
				strcpy(x[j-1], x[j]);
				strcpy(x[j], temp1);
				int temp2 = y[j-1];														//y��ۧ� 
				y[j-1] = y[j];
				y[j] = temp2;
			}
			else																		//�_�h�N���U�@��i 
				break;
		}
	}
}

void releasememory(char **a ,char **b, int c[], int d[], int n)							//�M���ʺA�t�m�O����� 
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
