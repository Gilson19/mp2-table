#include "Table.h"





void Table::ShowTable() 
{
	if(isEmpty())
	{
		std::cout << "Table is empty";
		return;
	}
	for (ui i = 0; i < curentSize; i++)
	{
		cout  << table[i].name << "\t\t|\t" << table[i].strPolinom << "\t\t|\t" << table[i].polinom << "\t\t|\n";
	}


}
