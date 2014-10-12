#include <iostream>
#include <string>
#include <array>

using namespace std;

void printarray(string doemijeenarray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i << ": " << doemijeenarray[i] << endl;
	}
}

int main()
{
	string ditiseenarray[] = { "hallo", "bla", "ditus", "hobba", "diee" };
	string nogeenarray[] = {"bla", "die", "bla", "die", "bla", "die", "bla" };
	string noudelaatstedan[] = {"Dit", "is", "echt", "de", "laatste"};
	
	cout << endl << "Array 1:" << endl;
	printarray(ditiseenarray, 5);
	cout << endl << "Array 2:" << endl;
	printarray(nogeenarray, 7);
	cout << endl << "Array 3:" << endl;
	printarray(noudelaatstedan, 5);
	
	return 0;
}