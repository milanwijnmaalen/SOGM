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

void roteer(string nouhetkannietophiermetdiearrays[], int size)
{
	string eerste = nouhetkannietophiermetdiearrays[0];

	for (int i = 1; i < size; i++)
	{
		nouhetkannietophiermetdiearrays[i - 1] = nouhetkannietophiermetdiearrays[i];
	}
	nouhetkannietophiermetdiearrays[size - 1] = eerste;
}

void roteerdeanderekantop(string ikhebechtnognooitinmijnHELELEVENzoveelarraysgezien[], int size)
{
	string laatste = ikhebechtnognooitinmijnHELELEVENzoveelarraysgezien[size - 1];

	for (int i = size - 2; i > -1; i--)
	{
		ikhebechtnognooitinmijnHELELEVENzoveelarraysgezien[i + 1] = ikhebechtnognooitinmijnHELELEVENzoveelarraysgezien[i];
	}
	ikhebechtnognooitinmijnHELELEVENzoveelarraysgezien[0] = laatste;
}

int main()
{
	string ditiseenarray[] = { "hallo", "bla", "ditus", "hobba", "diee" };
	
	cout << endl << "Origineel: " << endl;
	printarray(ditiseenarray, 5);
	
	cout << endl << "Roteer naar links(?) :" << endl;
	roteer(ditiseenarray, 5);
	printarray(ditiseenarray, 5);
	
	cout << endl << "Roteer naar links(?) :" << endl;
	roteer(ditiseenarray, 5);
	printarray(ditiseenarray, 5);
	
	cout << endl << "Roteer naar rechts(?) :" << endl;
	roteerdeanderekantop(ditiseenarray, 5);
	printarray(ditiseenarray, 5);
	
	cout << endl << "Roteer naar rechts(?), terug bij origineel:" << endl;
	roteerdeanderekantop(ditiseenarray, 5);
	printarray(ditiseenarray, 5);
}