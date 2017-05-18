
#pragma once
#include <string>
#include "TPolinom.h"
#define MAX_SIZE_OF_TABLE 1000000
typedef unsigned long ul;
class Table
{
protected:
	struct TRecord
	{
		std::string name;
		std::string strPolinom;
		TPolinom *polinom;
		TRecord(std::string _name, std::string _strPolinom, TPolinom *_polinom) : name(_name), strPolinom(_strPolinom)
		{
			_polinom = !nullptr ? polinom = _polinom : throw bad_alloc();
		}
		TRecord() : name(nullptr), strPolinom(nullptr), polinom(nullptr) {};
	};
	TRecord *table;
	ul sizeTable;

public:
	virtual void insert(std::string _name, std::string _str, TPolinom *_p) = 0;
	virtual void Delete(std::string _name) = 0;
	virtual TRecord search(std::string _name) = 0;
	Table(ul _sizeTable)
	{
		_sizeTable < MAX_SIZE_OF_TABLE ? sizeTable = _sizeTable : throw "too large size of table";
		table = new TRecord[sizeTable];
	}
	virtual ~Table()
	{
		delete[] table;
	};
};

