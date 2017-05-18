#include<iostream>
#include "TPolinom.h"
#include "UnorderedTable.h"

using namespace std;
int main(int argc, char *argv[])
{
	TPolinom p1("3X");
	TPolinom p2("2X+3Y2Z");
	TPolinom p3("7Y+10X");
	TPolinom p4("2X+3Y2Z+3Z");
	
	UnorderedTable t(6);
	t.insert(string("p1"), "1424124124", &p1);
	t.insert(string("p2"), "1424124124", &p2);
	t.insert(string("p3"), "1424124124", &p3);
	t.insert(string("p4"), "1424124124", &p4);

	t.ShowTable();

	return 0;
}
