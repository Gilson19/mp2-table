#include "UnorderedTable.h"


void UnorderedTable::Delete(std::string _name)
{
	if (isEmpty()) {
		cout << "table is empty";
		return;
	}

	for (ui i = 0; i < curentSize; i++)
	{
		if (_name == table[i].name)
		{
			for (int j = i; j < curentSize - 1; j++)
				std::swap(table[i], table[i + 1]);
			clearRecord(table[curentSize - 1]);
			curentSize--;
			
			break;
		}
	}

}






