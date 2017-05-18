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
	virtual ~UnorderedTable()
	{

	}
};

