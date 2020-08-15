#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
const int MAX_ENTRY = 200; //maximun number of entries allowed
const int MAX_FIELD = 20;  //maximun number of fields allowed
const int MAX_TABLE = 10;  //maximun tables allowed in a database
const int MAX_STRING_LEN = 10;  //maximun length of string in data allowed (include field name)
const int MAX_LINE_LEN = 300; 
struct Data 
{
	int i;
	char* c;
};
struct Field 
{
	bool isString;
	char* name;
	Data* data;
};
struct Condition
{
	char* fieldName;
	Data value;
};
struct Command 
{
	int selectNum;
	char** select;       //select
	char* tableName;	 //from
	Condition condition; //where
};
bool isStringType(char* str) /* TODO (Problem 2)*/
{
	char number[12] = "-1234567890";
	int count = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if(str[i] == number[j])
			{
				count++;
			}
		}
	}
	if (count == strlen(str))
		return false;
	else
		return true;
}
class Table 
{
private:
	char* tableName;
	int numOfField;
	int numOfEntry;
	Field* field;
	Field* getField(char* name);
public:
	Table(char name[]);								/* use your own code in homework 9*/
	~Table();										/* use your own code in homework 9*/
	void print();
	bool addField(char* colName, bool isString);	/* use your own code in homework 9 and MODIFY (Problem 3)*/
	bool addEntry(Data* data);						/* use your own code in homework 9 and MODIFY (Problem 3)*/
	bool loadcsv(char fileName[]);
	Table* executeCmd(Command cmd);					/* use your own code in homework 9 and MODIFY (Problem 3 and Problem 4)*/
	char* getName();								/* use your own code in homework 9*/
};
class Database
{
private:
	int numOfTables;
	Table** tables; 
public:
	Database();						/* use your own code in homework 9*/
	~Database();					/* use your own code in homework 9*/
	bool newTable(Table* table);	/* use your own code in homework 9*/
	Table* executeCmd(Command cmd); /* use your own code in homework 9*/
};
Table::Table(char name[])
{
	// set tableName to name
	// allocate memory spaces for Field*
	tableName = new char [strlen(name) + 1];								//幫tableName new出對的空間 
	strcpy(tableName, name);												//把name copy 過去 
	field = new Field[MAX_FIELD];											//幫field new出對的空間 
	for (int i = 0; i < MAX_FIELD; i++)										//field 的data, name new出對的空間 
	{
		field[i].data = new Data [MAX_ENTRY];
		for(int j = 0; j < MAX_ENTRY; j++)
		{
			field[i].data[j].c = new char [MAX_STRING_LEN];
			field[i].data[j].i = 0;
		}
		field[i].name = new char [MAX_STRING_LEN];
	}
	numOfEntry = 0;															 
	numOfField = 0;	
}
Table::~Table()
{
	// release dynamic allocated memory space
	delete [] tableName;
	tableName = nullptr;						
	for (int i = 0; i < MAX_FIELD; i++)
	{
		delete [] field[i].name;
		field[i].name = nullptr;
		for (int j = 0; j < MAX_ENTRY; j++)
		{
			delete [] field[i].data[j].c;
			field[i].data[j].c = nullptr;
		}
		delete [] field[i].data;
		field[i].data = nullptr;
	}
	delete [] field;
	field = nullptr;
}
Field* Table::getField(char* name)
{
	// get the pointer to specific field by its name
	// return NULL if not found
	for (int i = 0; i < numOfField; ++i)
	{
		if (strcmp(name, field[i].name) == 0)
		{
			return &field[i];
		}
	}
	return nullptr;
}
char* Table::getName()
{
	return tableName;
}
bool Table::addField(char* colName, bool isString) 	/* use your own code in homework 9 and MODIFY (Problem 3)*/
{
	// modify the following code to make it able to handle 2 types of data
	// you may start from your own code in the previous homework
}
bool Table::addEntry(Data* data)	/* use your own code in homework 9 and MODIFY (Problem 3)*/
{
	// modify the following code to make it able to handle 2 types of data
	// you may start from your own code in the previous homework
}
Table* Table::executeCmd(Command cmd) /* use your own code in homework 9 and MODIFY (Problem 3 and Problem 4)*/
{
	// modify the following code to make it able to handle 2 types of data (for problem 3)
	// modify the following code to make it able to handle WHERE clause (for problem 4)
	// you may start from your own code in the previous homework
}
void Table::print()
{
	if (numOfEntry == 0 || numOfField == 0)
	{
		cout << "Empty set\n";
		return;
	}
	int* tabSize = new int[numOfField];
	int totalTabSize = 0;
	for (int i = 0; i < numOfField; ++i)
	{
		tabSize[i] = 0;
		if (!field[i].isString)
		{
			for (int j = 0; j < numOfEntry; ++j)
			{
				int len = log10(abs(field[i].data[j].i));
				if (field[i].data[j].i < 0)
				{
					len ++;
				}
				if (len > tabSize[i])
				{
					tabSize[i] = len;
				}
			}
		}
		else
		{
			for (int j = 0; j < numOfEntry; ++j)
			{
				int len = strlen(field[i].data[j].c);
				if (len > tabSize[i])
				{
					tabSize[i] = len;
				}
			}
		}
		if (strlen(field[i].name) > tabSize[i])
		{
			tabSize[i] = strlen(field[i].name);
		}
		tabSize[i] += 1;
		totalTabSize += tabSize[i];
	}
	int lenOfSeperationLine = totalTabSize + 3*numOfField + 2;
	char* seperationLine = new char[lenOfSeperationLine];
	for (int i = 0; i < lenOfSeperationLine; ++i)
	{
		seperationLine[i] = '-';
	}
	seperationLine[lenOfSeperationLine - 1] = 0;

	cout << seperationLine << "\n";

	cout << "|";
	for (int i = 0; i < numOfField; ++i)
	{
		if (field[i].isString)
		{
			cout <<" "<<left<< setw(tabSize[i]) << field[i].name  << " |";
		}
		else
			cout <<" "<<right<< setw(tabSize[i]) << field[i].name  << " |";
		
	}

	cout <<"\n"<< seperationLine << "\n";
	for (int i = 0; i < numOfEntry; ++i)
	{
		cout << "|";
		for (int j = 0; j < numOfField; ++j)
		{
			if (field[j].isString)
			{
				cout <<" "<< left << setw(tabSize[j]) << field[j].data[i].c << " |";
			}
			else
				cout <<" "<< right << setw(tabSize[j]) << field[j].data[i].i << " |";
			
		}
		cout << "\n";
	}
	cout << seperationLine << "\n";
	if (numOfEntry > 1)
	{
		cout << numOfEntry << " rows in set\n";
	}
	else
		cout << "1 row in set\n";
	
	delete [] tabSize;
	delete [] seperationLine;
}
bool Table::loadcsv(char fileName[])
{
	// this function is already able to handle 2 types of data
	FILE* csvFile = fopen(fileName, "r");
	if (csvFile == NULL)
	{
		fprintf(stderr, "open file error\n");
		return false;
	}
	char* line = new char[MAX_LINE_LEN];
	int entryIndex = 0;

	
//	for (int i = 0; i < MAX_FIELD; ++i)
//	{
//		field[i].data = new Data[MAX_ENTRY];
//	}
	int fieldIndex = 0;
	if (fgets(line, MAX_LINE_LEN, csvFile))
	{
		char* token = strtok(line, ",;\r\n");
		
		while(token != NULL)
		{
			field[fieldIndex].name = new char[MAX_STRING_LEN];
			strcpy(field[fieldIndex].name, token);

			fieldIndex++;
			token = strtok(NULL, ",;\r\n");
		}
	}
	else{

		fprintf(stderr, "input file empty\n");
		return false;
	}
	numOfField = fieldIndex;

	bool typeDecided = false;
	while(fgets(line, MAX_LINE_LEN, csvFile))
	{
		char* token = strtok(line, ",\r\n");
		int fieldIndex = 0;
		
		while(token != NULL)
		{
			if (!typeDecided)
			{
				if ((isStringType(token)))
				{
					field[fieldIndex].isString = true;
				}
				else{
					field[fieldIndex].isString = false;
				}
			}
			if (field[fieldIndex].isString)
			{
				field[fieldIndex].data[entryIndex].c = new char[MAX_STRING_LEN];
				strcpy(field[fieldIndex].data[entryIndex].c, token);
			}
			else
				field[fieldIndex].data[entryIndex].i = atoi(token);
			
			token = strtok(NULL, ",\r\n");
			fieldIndex ++;
		}
		typeDecided = true;
		entryIndex ++;
	}
	numOfEntry = entryIndex;
	return true;
}
Database::Database()	/* use your own code in homework 9*/
{
	// initialization and allocate memory spaces for Table**
	numOfTables = 0;
	tables = new Table*[MAX_TABLE];

}
Database::~Database()	/* use your own code in homework 9*/
{
	// release memory spaces for Table**
	delete []tables;
}
bool Database::newTable(Table* table)	/* use your own code in homework 9*/
{
	// add a new table into database
	// return true if success, false if maximum table number exceeded
	if (numOfTables >= MAX_TABLE)
		return false;
	tables[numOfTables] = table;
	numOfTables++;
}
Table* Database::executeCmd(Command cmd)	/* use your own code in homework 9*/
{
	// pass the command to the correct table and return the result table's pointer
	for (int i = 0; i < numOfTables; i++)
	{
		if (strcmp(cmd.tableName, tables[i]->getName()) == 0)
			return tables[i];
	}
	return nullptr;
}
Command parseCommand(char command[])	/* use your own code in homework 9*/
{
	// take a command string and parse it to struct Command
	Command cmd;
	char *tab = new char [MAX_STRING_LEN];								//tab用來存tableName 
	char **colName = new char *[MAX_FIELD];								//colName用來吋存被選到 
	for (int i = 0; i < MAX_FIELD; i++)
		colName[i] = new char [MAX_STRING_LEN];
	char *tok = strtok(command, ", ;");									//tok拿來切字串 
	int colCnt = 0;														//colCnt用來數有幾個被選到的field 
	bool isField = false, isTab = false;								//用來確認現在是Field還是Table 
	
	while(tok != nullptr)												//切到不能再切 
	{					
		if(strcmp(tok, "FROM") == 0)									//找到FROM就不是Field 
			isField = false;
		if(isField)														//如果是Field 
		{
			strcpy(colName[colCnt], tok);								//就久紀錄名字 
			colCnt++;													//colCnt加一 
		}
		if(isTab)														//如果是table 
		{
			strcpy(tab, tok);											//就記錄他的名字 
		}
		if (strcmp(tok,"SELECT") == 0)									//如果是SELECT，那下一個開始就會是Field
			isField = true;
		if(strcmp(tok, "FROM") == 0)									//如果是FROM，那下一個開始就會是tableName 
			isTab = true;
		
		tok = strtok(nullptr, ", ;");									//每次就往下切 
	}
	cmd.selectNum = colCnt;												//紀錄到cmd裡面 
	cmd.select = colName;
	cmd.tableName = tab;
	
	return cmd;
}
int main()
{
	/* TODO (all problems) */
	char fileName[MAX_LINE_LEN] = {0};
	cin >> fileName;
	char tableName[] = "haha";
	Table x(tableName);
	x.loadcsv(fileName);
	x.print();
	return 0;
}
