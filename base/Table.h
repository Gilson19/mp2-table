
#pragma once
#include <string>
#include "TPolinom.h"
#define MAX_SIZE_OF_TABLE 1000000
typedef unsigned int ui;
typedef unsigned long ul;


//int sumOfChar(std::string str)
//{
//	int result = 0;
//	for (int i = 0; i < str.size(); i++)
//		result += static_cast<int>(str[i]);
//	return result;
//
//}


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
		TRecord() = default;
	};
	virtual void clearRecord(TRecord& rec)
	{
		rec.name = "empty";
		rec.polinom = nullptr;
		rec.strPolinom = "empty";
	}
	virtual bool isEmpty() const { return curentSize == 0; } 
	virtual bool isFull() const { return curentSize == MAX_SIZE_OF_TABLE; }
	TRecord *table;
	ul sizeTable;
	ul curentSize;

public:
	virtual void insert(std::string _name, std::string _str, TPolinom *_p) = 0;
	//virtual void Delete(std::string _name) = 0;
	//virtual  TRecord* search(std::string _name) = 0;                                                                                                                   
	virtual void ShowTable() ;
	Table(ul _sizeTable)
	{
		curentSize = 0;
		if(_sizeTable >= MAX_SIZE_OF_TABLE)
			throw "too large size of table";

		sizeTable = _sizeTable;

		//_sizeTable < MAX_SIZE_OF_TABLE ? sizeTable = _sizeTable : throw "too large size of table";
		table = new TRecord[sizeTable];
	}
	virtual ~Table()
	{
		delete[] table;
	};
};

