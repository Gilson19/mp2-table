#pragma once
#include "Table.h"




class HashTable :
	public Table
{
private:
	void Initilization()
	{
		for (int i = 0; i < sizeTable; i++)
		{
			clearRecord(table[i]);
		}
	}
	int Hash(int key)
	{
		return key % sizeTable;
	}
	bool *used;
public:
	HashTable(ul _sizeTable) : Table(_sizeTable) {
		used = new bool[_sizeTable];
		for (ui i = 0; i < _sizeTable; i++)
			used[i] = false;
		Initilization();

	};
	
	virtual void insert(std::string _name, std::string _str, TPolinom *_p)
	{
		if (isFull())
			return;

		TRecord insertRec(_name, _str, _p);
		int hashIndex = Hash(sumOfChar(insertRec.name));
		while (used[hashIndex] && table[hashIndex].name != insertRec.name)
			hashIndex = Hash(hashIndex + 1);
		if (!used[hashIndex]) {
			used[hashIndex] = true;
			table[hashIndex] = insertRec;
		}
		curentSize++;
	}
	virtual void Delete(std::string _name)
	{
		if (isEmpty())
			return;

		ul hashIndex;
		hashIndex = Hash(sumOfChar(_name));
		while (used[hashIndex] && table[hashIndex].name != _name)
			hashIndex = Hash(hashIndex + 1);

		if (!used[hashIndex])
		{
			return;
		}

		used[hashIndex] = false;
		clearRecord(table[hashIndex]);
		curentSize--;
		
		
		





	}
	virtual  TRecord* search(std::string _name)
	{
		ul hashIndex;
		hashIndex = Hash(sumOfChar(_name));
		while(used[hashIndex] && table[hashIndex].name != _name)
			hashIndex = Hash(hashIndex + 1);

		if (!used[hashIndex])
			return nullptr;

		else
			return &table[hashIndex];

	}
	virtual ~HashTable()
	{
		delete[] used;
	}
};



