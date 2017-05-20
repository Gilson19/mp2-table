#pragma once
#include "Table.h"
class UnorderedTable :
	public Table
{
public:

	UnorderedTable(ul _sizeTable) : Table(_sizeTable) {};
	virtual void insert(std::string _name, std::string _str, TPolinom *_p)
	{
		if (curentSize >= sizeTable)
			return;
		table[curentSize++] =  TRecord(_name,_str, _p);
	}
	virtual void Delete(std::string _name);
	virtual  TRecord* search(std::string _name)
	{
		for (int i = 0; i < curentSize; i++)
		{
			if (_name == table[i].name)
				return &table[i];
		}
		return nullptr;
	}
	virtual ~UnorderedTable()
	{

	}
};

