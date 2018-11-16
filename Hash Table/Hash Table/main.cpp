#include <iostream>
#include "Hash Table.h"

using namespace std;

int main()
{
	Set s;
	constructor(s);
	add(s, "lalala");
	cout << exists(s, "lalala") << endl;
	deleteElement(s, "lalala");
	cout << exists(s, "lalala") << endl;


	return 0;
}