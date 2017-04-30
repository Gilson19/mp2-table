#include "TPolinom.h"

int TPolinom::p = 10;

double TPolinom::Calculate(double X, double Y, double Z )
{
	
	int degreeX = 0;
	int degreeY = 0;
	int degreeZ = 0;

	double result = 0.0;
	TLink *tmp = new TLink;
	tmp = list->pHead->pNext;
	do {

		degreeX = (tmp->monom.degree) / (p * p);
		degreeY = ((tmp->monom.degree) - (degreeX * p * p)) / p;
		degreeZ = (tmp->monom.degree) - ((degreeX * p * p) + (degreeY * p));

		result += tmp->monom.coef * pow(X, degreeX) * pow(Y, degreeY) * pow(Z, degreeZ);
		tmp = tmp->pNext;
	} while (tmp != list->pHead);
	return result;



}

void TPolinom::createPolinom(const  char *str)
{
	char *number = "1234567890";

	int i = 0;
	char *stringVal = new char[50];
	int k = 0;
	int j = 0;
	int monomCoef = 1;
	int monomDegree = 0;
	int localMonomCoef = 1;
	char symbolPolinom;
	while (str[i] != '\0') {

		monomCoef = 1;
		monomDegree = 0;


		// вычисл€ем коэф очередного монома
		
		for (; isdigit(str[i]) != 0 || str[i] == '-'; i++)
		{
			stringVal[j++] = str[i];
		}
		stringVal[j] = '\0';
		
		if (stringVal[0] == '-' && stringVal[1] == '\0') {
			stringVal[1] = '1';
			stringVal[2] = '\0';
		}
		
		localMonomCoef = atoi(stringVal);
		if (localMonomCoef == 0)
			monomCoef = 1;
		else
			monomCoef = localMonomCoef;



		j = 0;
		int degree;
		stringVal[j] = '\0';



		// вычисл€ем степени монома
		while (str[i] != '+' && str[i] != '-' && str[i] != '\0') {



			symbolPolinom = str[i++];
			for (; isdigit(str[i]) != 0; i++)
			{
				stringVal[j++] = str[i];
			}
			stringVal[j] = '\0';
			j = 0;

			if (atoi(stringVal) == 0)
				degree = 1;
			else
				degree = atoi(stringVal);



			if (symbolPolinom == 'X' || symbolPolinom == 'x')
				monomDegree += pow(p, 2) * degree;
			else if (symbolPolinom == 'Y' || symbolPolinom == 'y')
				monomDegree += p * degree;
			else if (symbolPolinom == 'Z' || symbolPolinom == 'z')
				monomDegree += degree;

			j = 0;
			stringVal[j] = '\0';


		}
		// создаем и записывам моном в лист
		TMonom mon;
		mon.coef = monomCoef;
		mon.degree = monomDegree;
		list->addMonom(mon);
		if (str[i] != '-' && str[i] != '\0')
			i++;
	}
}

TPolinom::TPolinom( const char *str) : TPolinom()
{
	createPolinom(str);
}

TPolinom::TPolinom(string str) : TPolinom()
{
	createPolinom(str.c_str());
	
}

TPolinom::TPolinom()
{
	list = new TList();
}

TPolinom::~TPolinom()
{
	delete list;
}

TPolinom TPolinom::operator*(double c)
{
	TPolinom *resultPolinom = new TPolinom();

	TLink *p = new TLink();
	p = list->pHead->pNext;
	do {
		TMonom monom;
		monom.coef = p->monom.coef * c;
		monom.degree = p->monom.degree;
		resultPolinom->list->addMonom(monom);
		p = p->pNext;
	} while (p != list->pHead);

		return *resultPolinom;
	

}

TPolinom TPolinom::operator+(const TPolinom &polinom)
{
	TLink *p1 = new TLink;
	TLink *p2 = new TLink;

	p1 = list->pHead->pNext;
	p2 = polinom.list->pHead->pNext;
	
	TPolinom *resultPolinom = new TPolinom();

	while (p1 != list->pHead || p2 != polinom.list->pHead)
	{
		if ((p1->monom.degree) > (p2->monom.degree))
		{
			resultPolinom->list->addMonom(p1->monom);
			p1 = p1->pNext;
				
		}
		else if ((p1->monom.degree) < (p2->monom.degree))
		{
			resultPolinom->list->addMonom(p2->monom);
			p2 = p2->pNext;
		}

		else
		{
			TMonom monom;
			monom.coef = (p1->monom.coef) + (p2->monom.coef);
			
			monom.degree = p1->monom.degree;
			resultPolinom->list->addMonom(monom);
			
			
			
			p1 = p1->pNext;
			p2 = p2->pNext;
		}
	}
	
	return *resultPolinom;


}


