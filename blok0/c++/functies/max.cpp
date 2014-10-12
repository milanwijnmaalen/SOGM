#include <iostream>
#include <string>
#include <array>

using namespace std;

void printarray(int doemijeenarray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i << ": " << doemijeenarray[i] << endl;
	}
}

int max(int heyikwilookeenarray[], int size)
{
	int maximum;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			maximum = heyikwilookeenarray[i];
		}
		else if (maximum < heyikwilookeenarray[i])
		{
			maximum = heyikwilookeenarray[i];
		}
	}
	return maximum;
}


int main()
{
	cout << endl;

	int wederomeenarray[] = { 1, 2, 3, 5, 2, 6, 3 };
	int ditisookeenarray[] = { 4, 2, 4, 3, 8, 2 };
	
	cout << "Inhoud array 1: " << endl;
	printarray(wederomeenarray, 7);
	cout << "Het hoogste getal is " << max(wederomeenarray, 7) << endl << endl;
	
	cout << "Inhoud array 2: " << endl;
	printarray(ditisookeenarray, 6);
	cout << "Het hoogste getal is " << max(ditisookeenarray, 6) << endl;
	
	return 0;
}