#pragma once
#include "Table.h"

int sumOfChar(std::string str)
{
	int result = 0;
	for (int i = 0; i < str.size(); i++)
		result += static_cast<int>(str[i]);
	return result;

}

class HashTable :
	public Table
{
private:
	void Initilization()
	{
		for (int i = 0; i < sizeTable; i++)
		{
			table[i].name = "empty";
			table[i].strPolinom = "empty";
			
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
	//virtual void Delete(std::string _name) ;
	//virtual  TRecord* search(std::string _name) ;
	virtual ~HashTable()
	{
		delete[] used;
	}
};

