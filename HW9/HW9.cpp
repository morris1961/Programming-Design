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

bool first = true;

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
	char* column;
	char* value;
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
	tableName = new char [strlen(name) + 1];
	strcpy(tableName, name);
	field = new Field[MAX_FIELD];
	for (int i = 0; i < MAX_FIELD; i++)
	{
		field[i].data = new char *[MAX_ENTRY];
		for(int j = 0; j < MAX_ENTRY; j++)
		{
			field[i].data[j] = new char [MAX_STRING_LEN];
		}
		field[i].name = new char [MAX_STRING_LEN];
	}
	numOfEntry = 0;
	numOfField = 0;
}
Table::~Table() /* TODO (Problem 3)*/
{
	// release dynamic allocated memory space
	delete [] field;
}
bool Table::addField(char* colName) /*TODO (Problem 4)*/
{
	// colName: the name of the added field
	// add a new field to the table
	// after adding, there will be no value for all data in that field
	// return true if success, false if maximum field number exceeded
	if (numOfField >= MAX_FIELD)
		return false;
	strcpy(field[numOfField].name, colName);
	numOfField++;
}
bool Table::addEntry(char** data) /* TODO (Problem 4)*/
{
	// data: the entry to be added
	// add a new entry to the table
	// you may assume number of element in data is the same as the number of fields in the table
	// return true if success, false if maximum entry number exceeded
	if(numOfEntry >= MAX_ENTRY)
		return false;
	
	for (int i = 0; i < numOfField; i++)
	{
		strcpy(field[i].data[numOfEntry], data[i]);
	}
	numOfEntry++;
	
}
Table* Table::executeCmd(Command cmd) /* TODO (Problem 4)*/
{
	// cmd: commnad to be executed
	// save the result of the command executed into a new table, and then return its pointer
	char tableName[] = "answer";
	Table *ansTab = new Table(tableName);
	if (strcmp(cmd.select[0], "*") == 0)
	{
		char **entry = new char *[numOfField];
		for (int i = 0; i < numOfField; i++)
		{
			entry[i] = new char [MAX_STRING_LEN];
		}
		
		for (int i = 0; i < numOfField; i++)
		{
			ansTab->addField(field[i].name);
		}
		
		for (int j = 0; j < numOfEntry; j++)
		{
			for (int k = 0; k < numOfField; k++)
			{
				strcpy(entry[k], field[k].data[j]);	
			}
			ansTab->addEntry(entry);
			//cout << entry[0] << " " << entry[1] << "\n";			
		}	
	}
	else
	{
		char **entry = new char *[cmd.selectNum];
		for (int i = 0; i < cmd.selectNum; i++)
		{
			entry[i] = new char [MAX_STRING_LEN];
		}
		
		for (int i = 0; i < cmd.selectNum; i++)
		{
			Field *tempFie = getField(cmd.select[i]);
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
				Field *tempFie = getField(cmd.select[k]);
				//cout << tempFie->name << " ";
				if(tempFie != nullptr)
				{
					strcpy(entry[k], tempFie->data[j]);	
				}
			}
			ansTab->addEntry(entry);
			//cout << entry[0] << " " << entry[1] << "\n";			
		}	
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
	char *tab = new char [MAX_STRING_LEN];
	char **colName = new char *[MAX_FIELD];
	for (int i = 0; i < MAX_FIELD; i++)
		colName[i] = new char [MAX_STRING_LEN];
	char *column = nullptr;
	char *value = nullptr;
	char *tok = strtok(command, ", ;");
	int colCnt = 0;
	bool isField = false, isTab = false, iscolumn = false, isvalue = false;
	
	while(tok != nullptr)
	{
		
		if(strcmp(tok, "FROM") == 0)
			isField = false;
		if(strcmp(tok, "WHERE") == 0)
			isTab = false;
		if(strcmp(tok, "=") == 0)
			iscolumn = false;
		
		if(isField)
		{
			strcpy(colName[colCnt], tok);
			colCnt++;
		}
		if(isTab)
		{
			strcpy(tab, tok);
		}
		if(iscolumn)
		{
			column = new char [MAX_STRING_LEN];
			strcpy(column, tok);
		}
		if(isvalue)
		{
			value = new char [MAX_STRING_LEN];
			strcpy(value,tok);
		}
		
		if (strcmp(tok,"SELECT") == 0)
			isField = true;
		if(strcmp(tok, "FROM") == 0)
			isTab = true;
		if(strcmp(tok, "WHERE") == 0)
			iscolumn = true;
		if(strcmp(tok, "=") == 0)
			isvalue = true;
		
		tok = strtok(nullptr, ", ;");	
	}
	cmd.selectNum = colCnt;
	cmd.select = colName;
	cmd.tableName = tab;
	
	if(column != nullptr)
		cmd.column = column;
	else
		cmd.column = nullptr;
		
	if(value != nullptr)
		cmd.value = value;
	else
		cmd.value = nullptr;
	return cmd;
}
int main()
{
	Command cmd;
	char x[1000], y[100];
	cin.getline(x,1000);
	cin.getline(y,100);
	cmd = parseCommand(x);
	
	if(strcmp(y,"SELECT") == 0)
	{
		cout << cmd.select[0];
		for (int i = 1; i < cmd.selectNum; i++)
			cout << " " << cmd.select[i];
	}
	else if (strcmp(y, "FROM") == 0)
	{
		cout << cmd.tableName;
	}
	else if (strcmp(y, "WHERE") == 0)
	{
		if (cmd.column != nullptr && cmd.value != nullptr)	
		{
			cout << cmd.column << " ";
			cout << cmd.value;
		}
		else
		{
			cout << "NULL";
		}
	}

	
	
	
	return 0;
}
