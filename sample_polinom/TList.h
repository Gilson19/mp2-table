#pragma once
#include <iostream>
using namespace std;

struct TMonom
{
	double coef;
	int degree;
};


struct TLink
{
	TMonom monom;
	TLink *pNext;
};



class TPolinom;



class TList
{
	friend TPolinom;
private:
	TLink *pHead;
	void printList();

public:
	
	TLink *getHead() { return pHead; }
	void addMonom(TMonom mon);
	TList();
	~TList();
	friend ostream& operator<<(ostream& stream, const TPolinom& polinom);
};

