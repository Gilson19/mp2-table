#include<iostream>
#include "TPolinom.h"


#include "HashTable.h"

using namespace std;
int main(int argc, char *argv[])
{
	TPolinom p1("3X");
	TPolinom p2("2X+3Y2Z");
	TPolinom p3("7Y+10X");
	TPolinom p4("2X+3Y2Z");
	TPolinom n5("2X+3Z");
	
	HashTable t(6);
	t.insert(string("p1"), p1.ToString(), &p1);
	t.insert(string("p4"), p4.ToString(), &p4);
	t.insert(string("p3"), p3.ToString(), &p3);
	t.insert(string("p2"), p2.ToString(), &p2);
	t.insert(string("n5"), n5.ToString(), &n5);

	t.ShowTable();

	cout <<"\n\n\n" << "n5 is " << *(t.search("n5")->polinom) << endl;

	if (t.search("n3") == nullptr)
		cout << "n3 not found" << "\n\n\n";


	t.Delete("p3");
	t.Delete("n5");

	t.ShowTable();


	////t.Delete("p3");
	////cout << "\n\n\n";
	////t.ShowTable();





	///*cout << "n\n\n" <<  *(t.search("p1")) << endl;
	//
	//TPolinom *pol = t.search("p4");

	//if (pol == nullptr)
	//	cout << "not found";
	//else
	//	cout << *pol;*/
	



	

	

	


	return 0;
}
