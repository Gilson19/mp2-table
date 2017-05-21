#include "Table.h"

int sumOfChar(std::string str)
{
	int result = 0;
	for (int i = 0; i < str.size(); i++)
		result += static_cast<int>(str[i]);
	return result;

}


void Table::ShowTable() 
{
	
	for (ui i = 0; i < sizeTable; i++)
	{
		cout  << table[i].name << "\t\t|\t" << table[i].strPolinom << "\t\t|\t" << table[i].polinom << "\t\t|\n";
	}


}
