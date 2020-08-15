#include <iostream>
#include <cstring>  // for string processing
#include <iomanip>  // for printing tables
using namespace std;
// you may assume the following constant will work in all test data
const int MAX_ENTRY = 200;    	  //maximum number of entries allowed
const int MAX_FIELD = 20;  		  //maximum number of fields allowed
const int MAX_TABLE = 5;  		  //maximum tables allowed in a database
const int MAX_STRING_LEN = 10;    //maximum length of string in data allowed (including field name)
const int MAX_FILENAME_LEN = 100; //maximum length of file name string
const int MAX_LINE_LEN = 300; 	  //maximum length a line in csv files

struct Field
{
	char* name;
	char** data; //array of data
};
struct Command
{
	int selectNum;		//number of fields to be selected
	char** select; 		//fields to be selected
	char* tableName;	//table name for FROM clause
};
class Table 
{
private:
	char* tableName;
	int numOfField; //number of columns
	int numOfEntry; //number of rows
	Field* field;   //array of columns
	Field* getField(char* name);
public:
	Table(char name[]); /* TODO (Problem 3)*/
	~Table();           /* TODO (Problem 3)*/
	bool addField(char* colName);   /*TODO (Problem 4)*/
	bool addEntry(char** data);       /*TODO (Problem 4)*/
	Table* executeCmd(Command cmd); /*TODO (Problem 4)*/
	char* getName();
	void print();
	bool loadcsv(char fileName[]);
	
};
class Database
{
private:
	int numOfTables;
	Table** tables; //pointer array for tables contained in this database
public:
	Database();                     /* TODO (Problem 3)*/
	~Database();                    /* TODO (Problem 3)*/
	bool newTable(Table* table);    /* TODO (Problem 3)*/
	Table* executeCmd(Command cmd); /* TODO (Problem 4)*/
};
Table::Table(char name[]) /* TODO (Problem 3)*/
{
	// set tableName to name
	// allocate memory spaces for Field*
	tableName = new char [strlen(name) + 1];								//幫tableName new出對的空間 
	strcpy(tableName, name);												//把name copy 過去 
	field = new Field[MAX_FIELD];											//幫field new出對的空間 
	for (int i = 0; i < MAX_FIELD; i++)										//field 的data, name new出對的空間 
	{
		field[i].data = new char *[MAX_ENTRY];
		for(int j = 0; j < MAX_ENTRY; j++)
		{
			field[i].data[j] = new char [MAX_STRING_LEN];
		}
		field[i].name = new char [MAX_STRING_LEN];
	}
	numOfEntry = 0;															//初始化numOfEntry  
	numOfField = 0;															//初始化numOfField
}
Table::~Table() /* TODO (Problem 3)*/
{
	// release dynamic allocated memory space
	delete [] tableName;						
	for (int i = 0; i < MAX_FIELD; i++)
	{
		delete [] field[i].name;
		for (int j = 0; j < MAX_ENTRY; j++)
			delete [] field[i].data[j];
		delete [] field[i].data;
	}
	delete [] field;
}
bool Table::addField(char* colName) /*TODO (Problem 4)*/
{
	// colName: the name of the added field
	// add a new field to the table
	// after adding, there will be no value for all data in that field
	// return true if success, false if maximum field number exceeded
	if (numOfField >= MAX_FIELD)											//如果太多column就失敗 
		return false;
	strcpy(field[numOfField].name, colName);								//不然就copy column的名字 
	numOfField++;															//每copy一個就增加numOfField 
}
bool Table::addEntry(char** data) /* TODO (Problem 4)*/
{
	// data: the entry to be added
	// add a new entry to the table
	// you may assume number of element in data is the same as the number of fields in the table
	// return true if success, false if maximum entry number exceeded
	if(numOfEntry >= MAX_ENTRY)												//如果太多row就失敗
		return false;
	for (int i = 0; i < numOfField; i++)									//不然就copy row的data 
	{
		strcpy(field[i].data[numOfEntry], data[i]);
	}
	numOfEntry++;															//每copy一個就增加numOfEntry 
}
Table* Table::executeCmd(Command cmd) /* TODO (Problem 4)*/
{
	// cmd: commnad to be executed
	// save the result of the command executed into a new table, and then return its pointer
	char tableName[] = "answer";
	Table *ansTab = new Table(tableName);									//宣告一個新的Table 
	if (strcmp(cmd.select[0], "*") == 0)									//看是不是* 
	{
		char **entry = new char *[numOfField];								//宣告一個entry用來存對應column的row 
		for (int i = 0; i < numOfField; i++)
		{
			entry[i] = new char [MAX_STRING_LEN];
		}
		
		for (int i = 0; i < numOfField; i++)								//先把column加進去 
		{
			ansTab->addField(field[i].name);
		}
		
		for (int j = 0; j < numOfEntry; j++)								//再加entry 
		{
			for (int k = 0; k < numOfField; k++)
			{
				strcpy(entry[k], field[k].data[j]);							//找對應column的row然後存到entry 
			}
			ansTab->addEntry(entry);
			//cout << entry[0] << " " << entry[1] << "\n";			
		}
		
		for (int i = 0; i < numOfField; i++)								//釋放記憶體 
		{
			delete [] entry[i]; 
		}
		delete [] entry;	
	}
	else																	//基本上跟上面一樣 
	{
		char **entry = new char *[cmd.selectNum];
		for (int i = 0; i < cmd.selectNum; i++)
		{
			entry[i] = new char [MAX_STRING_LEN];
		}
		
		for (int i = 0; i < cmd.selectNum; i++)
		{
			Field *tempFie = getField(cmd.select[i]);						//用這個來找被選到的column 
			//cout << tempFie->name << " ";
			if(tempFie != nullptr)
			{
				ansTab->addField(tempFie->name);
			}
		}
		
		for (int j = 0; j < numOfEntry; j++)
		{
			for (int k = 0; k < cmd.selectNum; k++)
			{
				Field *tempFie = getField(cmd.select[k]);					//用這個來找被選到的column
				//cout << tempFie->name << " ";
				if(tempFie != nullptr)
				{
					strcpy(entry[k], tempFie->data[j]);	
				}
			}
			ansTab->addEntry(entry);
			//cout << entry[0] << " " << entry[1] << "\n";			
		}
		
		for (int i = 0; i < cmd.selectNum; i++)								//釋放記憶體 
		{
			delete [] entry[i]; 
		}
		delete [] entry;		
	}
	return ansTab;
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
char* Table::getName() // return the name of the table
{
	return tableName;
}
void Table::print() // print the table in pretty format
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

		for (int j = 0; j < numOfEntry; ++j)
		{
			int len = strlen(field[i].data[j]);
			if (len > tabSize[i])
			{
				tabSize[i] = len;
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
		cout <<" "<<left<< setw(tabSize[i]) << field[i].name  << " |";
	}

	cout <<"\n"<< seperationLine << "\n";
	for (int i = 0; i < numOfEntry; ++i)
	{
		cout << "|";
		for (int j = 0; j < numOfField; ++j)
		{
			cout <<" "<< left << setw(tabSize[j]) << field[j].data[i] << " |";
		
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
	// fileName: the file name for csv file including file extension (ex: "D:/hw9/table/table1.csv")
	// load data into table from csv files with the assumption that there's no data in the table
	// the first row of csv file contains field names
	// return true if success, false if fail. You may test whether loading is successful by its return value.
	FILE* csvFile = fopen(fileName, "r");
	if (csvFile == nullptr)
	{
		cerr << "open file error\n";
		return false;
	}
	char* line = new char[MAX_LINE_LEN];
	int entryIndex = 0;
	
	for (int i = 0; i < MAX_FIELD; ++i)
	{
		field[i].data = new char*[MAX_ENTRY];
	}
	int fieldIndex = 0;
	if (fgets(line, MAX_LINE_LEN, csvFile))
	{
		char* token = strtok(line, ",;\n");
		
		while(token != nullptr)
		{
			field[fieldIndex].name = new char[MAX_STRING_LEN];
			strcpy(field[fieldIndex].name, token);

			fieldIndex++;
			token = strtok(nullptr, ",;\n");
		}
	}
	else{
		cerr << "input file empty\n";
		return false;
	}
	numOfField = fieldIndex;

	while(fgets(line, MAX_LINE_LEN, csvFile))
	{
		char* token = strtok(line, ",\n");
		int fieldIndex = 0;
		
		while(token != nullptr)
		{
			field[fieldIndex].data[entryIndex] = new char[MAX_STRING_LEN];
			strcpy(field[fieldIndex].data[entryIndex], token);
					
			token = strtok(nullptr, ",\n");
			fieldIndex ++;
		}
		entryIndex ++;
	}
	numOfEntry = entryIndex;
}
Database::Database() /* TODO (Problem 3)*/
{
	// initialization and allocate memory spaces for Table**
	numOfTables = 0;
	tables = new Table*[MAX_TABLE];
}
Database::~Database() /* TODO (Problem 3)*/
{
	// release memory spaces for Table**
	delete []tables;
}
bool Database::newTable(Table* table) /* TODO (Problem 3)*/
{
	// add a new table into database
	// return true if success, false if maximum table number exceeded
	if (numOfTables >= MAX_TABLE)
		return false;
	tables[numOfTables] = table;
	numOfTables++;
}
Table* Database::executeCmd(Command cmd) /* TODO (Problem 4)*/
{
	// pass the command to the correct table and return the result table's pointer
	for (int i = 0; i < numOfTables; i++)
	{
		if (strcmp(cmd.tableName, tables[i]->getName()) == 0)
			return tables[i];
	}
	return nullptr;
}
Command parseCommand(char command[]) /* TODO (Problem 2)*/
{
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
	Command cmd;
	int n = 0;
	cin >> n;													//輸入有幾個table 
	Database DB;
	Table **t = new Table*[n];									//暫存table 
	char command[10000], space[2];								
	cin.getline(space,2);										//把endl弄掉 
	for (int i = 0; i < n; i++)									//把table存到DB裡面 
	{
		char x[111];											//暫存命令 
		cin.getline(x,111);
		char *tok = strtok(x, " ");								//拔tableName 
		t[i] = new Table(tok);
		tok = strtok(nullptr, " ");								//拔table的位置 
		t[i]->loadcsv(tok);
		DB.newTable(t[i]);										//把它塞到DB裡面 
		//t.print();
	}
	cin.getline(command,10000);									//處理command 
	cmd = parseCommand(command);
	Table *source = DB.executeCmd(cmd);							//找到要用的table 
	Table *ansTab = source->executeCmd(cmd);					//執行命令
	ansTab->print();
	return 0;
}
