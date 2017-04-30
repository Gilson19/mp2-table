#include <iostream>
#include"TList.h"
#include"TPolinom.h"
#include <stdio.h>
#include <string.h>





using namespace std;
int main()
{
	
	
	string p1, p2;
	
	

	cout << "Enter polinom 1 ";
	getline(cin, p1);
	
	TPolinom *polinom1 = new TPolinom(p1);
	cout << "Enter polinom 2 ";
	getline(cin, p2);
	TPolinom *polinom2 = new TPolinom(p2);

	cout << "polinom1 : " << *polinom1 << endl;

	cout << "polinom2 : " << *polinom2 << endl;

	

	cout << "sum : " << *polinom1 + *polinom2 << endl;

	int coef;
	cout << "Enter coef" << endl;
	cin >> coef;
	cout << "polinom1 * "<<coef <<" : " << *polinom1 * coef << endl;

	int X, Y, Z;
	cout << "Enter X Y Z : " << endl;
	cin >> X >> Y >> Z;


	cout << "result polinom2: " << polinom2->Calculate(X, Y, Z) <<"\nX = "<<X<<"\nY = "<<Y<<"\nZ = "<<Z<<"\n" << endl;

	
	
	return 0;
}












