#pragma once
#include "Table.h" 







class OrderedTable :
	public Table
{
public:

	OrderedTable(ul _sizeTable) : Table(_sizeTable) {};
	virtual void insert(std::string _name, std::string _str, TPolinom *_p)
	{
		if (isFull()) {
			cout << "table is full";
			return;
		}

		TRecord insertRec(_name, _str, _p);

		ui i;
		for (i = 0; i < curentSize; i++)
		{
			if (sumOfChar(insertRec.name) >= sumOfChar(table[i].name))
			{
				curentSize++;
				for (ui j = curentSize - 1; j > i; j--)
				{
					table[j] = table[j - 1];
				}
				table[i] = insertRec;
				return;
			}
		}
		table[curentSize++] = insertRec;


	}
	virtual void Delete(std::string _name)
	{
		if (isEmpty())
			return;

		int resultIndex = -1;;
		int key = sumOfChar(_name);
		int firstIndex = 0, lastIndex = curentSize - 1, curentIndex = 0;
		do
		{
			curentIndex = (firstIndex + lastIndex) / 2;

			if (key < sumOfChar(table[curentIndex].name))
				lastIndex = curentIndex - 1;
			else if (key > sumOfChar(table[curentIndex].name))
				firstIndex = curentIndex + 1;
			else {
				resultIndex = curentIndex;
				break;
			}

		} while (lastIndex >= firstIndex);

		if (resultIndex == -1)
			return;

		for (int i = resultIndex; i < curentSize - 1;i++)
			std::swap(table[i], table[i + 1]);

		clearRecord(table[curentSize - 1]);
		curentSize--;


	}
	virtual  TRecord* search(std::string _name)
	{

		if (isEmpty())
			return nullptr;

		int key = sumOfChar(_name);
		int firstIndex = 0, lastIndex = curentSize - 1, curentIndex = 0;
		do
		{
			curentIndex = (firstIndex + lastIndex) / 2;
			
			if (key < sumOfChar(table[curentIndex].name))
				lastIndex = curentIndex - 1;
			else if (key > sumOfChar(table[curentIndex].name))
				firstIndex = curentIndex + 1;
			else return &table[curentIndex];
			

		} while (lastIndex >= firstIndex);

		return nullptr;
	}


	~OrderedTable()
	{

	};
};

