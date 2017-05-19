#pragma once
#include<string>
#include<string.h>
#include"TList.h"
using namespace std;
class TPolinom
{

private:
	void createPolinom(const char *str);
	
	
public:
	TList *list;
	double Calculate(double X = 0.0, double Y = 0.0, double Z = 0.0);
	std::string ToString();
		
	
	
	static int p;
	
	TPolinom(const char *str);
	TPolinom(string str);
	TPolinom();
	~TPolinom();
	
	TPolinom operator+(const TPolinom& polinom);
	TPolinom operator*(double c);
	friend ostream& operator<<(ostream& stream, const TPolinom& polinom)
	{
		if (polinom.list->pHead->pNext->monom.coef == 0)
		{
			stream << "0";
			return stream;
		}
		int degreeX = 0;
		int degreeY = 0;
		int degreeZ = 0;
		int k = 0;
		TLink *p = new TLink;
		p = polinom.list->pHead->pNext;
		do {

			int coef_m = p->monom.coef;
			degreeX = (p->monom.degree) / (polinom.p * polinom.p);
			degreeY = ((p->monom.degree) - (degreeX * polinom.p * polinom.p)) / polinom.p;
			degreeZ = (p->monom.degree) - ((degreeX * polinom.p * polinom.p) + (degreeY * polinom.p));
			
			if (coef_m == 1)
				stream << "";

			else if (coef_m == -1)
				stream << "-";
			else
				stream << coef_m;
			
			if (degreeX > 0)
			{
				if (degreeX > 1)
					stream << "X" << degreeX;
				else
					stream << "X";
			}


			if (degreeY > 0)
			{
				if (degreeY > 1)
					stream << "Y" << degreeY;
				else
					stream << "Y";
			}
			

			if (degreeZ > 0)
			{
				if (degreeZ > 1)
					stream << "Z" << degreeZ;
				else
					stream << "Z";
			}


			


			p = p->pNext;
			if (p->monom.coef > 0)
				stream << "+";
			
			
			
				
		} while (p != polinom.list->pHead);
		
		return stream;
	}
};

