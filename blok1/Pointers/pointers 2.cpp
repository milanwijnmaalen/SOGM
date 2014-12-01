#include <iostream>

using namespace std;


void telopbypointer(int* pointer)
{
	*pointer = *pointer + 7;
}

int telopbyvalue(int value)
{
	return value + 7;
}

int main()
{
	int x = 5;

	//doorgeven by value: x nog steeds 5 output functie 5 + 7
	int byvalue = telopbyvalue(x);
	cout << "Na doorgeven by value: x=" << x << ", y=" << byvalue << endl;

	//doorgeven via pointer: de oorspronkelijke variabele wordt veranderd.
	telopbypointer(&x);
	cout << "Na doorgeven via een pointer: x=" << x << endl;


	cin.get();
}
