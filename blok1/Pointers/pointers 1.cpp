#include <iostream>

using namespace std;


int main()
{
	char letter = 97;
	char *letterpointer;

	cout << "Inhoud van de variabele letter: ";
	cout << letter << endl;

	letterpointer = &letter;
	cout << "Inhoud van de pointer letterpointer: ";
	cout << (unsigned long)letterpointer << endl;

	cout << "Inhoud van waar de pointer letterpointer naar wijst: ";
	cout << *letterpointer << endl;

	*letterpointer = 'b';
	cout << "De variabele letter heeft via letterpointer een nieuwe waarde gekregen: ";
	cout << *letterpointer << endl;

	cout << "Inhoud van de variabele letter: ";
	cout << letter << endl;

	// OEFENINGEN
	unsigned short year = 2013;
	unsigned short *yearpointer = &year;

	cout << "Inhoud van de variabele year: " << year << endl;
	cout << "Inhoud van de pointer yearpointer: " << (unsigned long)yearpointer << endl;
	cout << "Inhoud van waar de pointer yearpointer naar wijst: " << *yearpointer << endl;
	// geef year via de pointer een nieuwe waarde
	*yearpointer = 5145;
	cout << "Inhoud van de variabele year: " << year << endl;

	// maak nog een pointer genaamd anotheryearpointer en laat deze ook naar
	// year wijzen
	unsigned short *anotheryearpointer = yearpointer;
	cout << "Inhoud van de pointer anotheryearpointer: " << (unsigned long)anotheryearpointer << endl;
	cout << "Inhoud van waar de pointer anotheryearpointer naar wijst: " << *anotheryearpointer << endl;
	// geef year via de pointer een nieuwe waarde
	*anotheryearpointer = 666;
	cout << "Inhoud van de variabele year: " << year << endl;
	cout << "Inhoud van waar de pointer yearpointer naar wijst: " << *yearpointer;

	cin.get();
} // main()
