#include <iostream>
#include <string>
#include <array>

using namespace std;

float optellen(float a, float b)
{
	return a + b;
}

int main()
{
	cout << endl;
	cout << "1 + 1 = " << optellen(1, 1) << endl;
	cout << "2 + 2 = " << optellen(2, 2) << endl;
	cout << "9859348759,394093249 + 87928752435,02394 = " << optellen(9859348759.394093249, 87928752435.02394) << endl;
	return 0;
}