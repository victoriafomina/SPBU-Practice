#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set* tree = createSet();
	add(tree, 1);
	add(tree, 2);
	add(tree, -5);
	add(tree, 0);
	add(tree, -7);
	cout << remove(tree, 2) << endl;
	cout << remove(tree, -5) << endl;
	cout << remove(tree, 0) << endl;
	cout << remove(tree, 1) << endl;
	cout << remove(tree, -7) << endl;
	cout << remove(tree, 1) << endl;
	

	return 0;
}