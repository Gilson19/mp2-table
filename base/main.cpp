#include<iostream>
#include "TPolinom.h"
#include "UnorderedTable.h"
#include "OrderedTable.h"

using namespace std;
int main(int argc, char *argv[])
{
	TPolinom p1("3X");
	TPolinom p2("2X+3Y2Z");
	TPolinom p3("7Y+10X");
	TPolinom p4("2X+3Y2Z");
	
	OrderedTable t(6);
	t.insert(string("p1"), p1.ToString(), &p1);
	t.insert(string("p4"), p4.ToString(), &p4);
	t.insert(string("p3"), p3.ToString(), &p3);
	t.insert(string("p2"), p2.ToString(), &p2);

	t.ShowTable();

	cout <<"\n\n\n" << "p3 is " << *(t.search("p3")->polinom) << endl;

	t.Delete("p3");
	cout << "\n\n\n";
	t.ShowTable();





	/*cout << "n\n\n" <<  *(t.search("p1")) << endl;
	
	TPolinom *pol = t.search("p4");

	if (pol == nullptr)
		cout << "not found";
	else
		cout << *pol;*/
	



	

	

	


	return 0;
}
