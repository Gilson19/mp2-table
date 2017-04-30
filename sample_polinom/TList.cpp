#include "TList.h"

void TList::addMonom(TMonom mon)
{

	if (mon.coef == 0)
		return;

	TLink *tmp = new TLink;
	TLink *p = new TLink;
	TLink *p1 = new TLink;
	p = pHead;
	p1 = pHead->pNext;
	tmp->monom.coef = mon.coef;
	tmp->monom.degree = mon.degree;
	do {
		
		if (p1->monom.degree < tmp->monom.degree)
		{
			p->pNext = tmp;
			tmp->pNext = p1;
			return;
		}
		p = p1;
		p1 = p1->pNext;
	} while (p != pHead);


	
	
}

void TList::printList()
{
	TLink *p;
	p = pHead;
	do {
		p = p->pNext;
		cout << p->monom.coef << " " << p->monom.degree << endl;                                 // голова первая но выводится со второго эллемента для наглядности что заканчивается все снова головой



	} while (p != pHead);

}

TList::TList()
{
	pHead = new TLink;
	pHead->monom.coef = 0;
	pHead->monom.degree = -1;
	pHead->pNext = pHead;
}

TList::~TList()
{
	TLink *p = pHead->pNext;
	TLink *tmp = p;
	while (p != pHead)
	{
		tmp = tmp->pNext;
		delete p;
		p = tmp;
	}
	/*do {
		tmp = tmp->pNext;
		delete p;
		p = tmp;
	} while (p != pHead);*/
	delete pHead;

}

