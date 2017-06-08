#include "functions_01.h"


void printMenu()
{
	cout << "Lab 01" << endl << endl;
	cout << "1 - Show all strings" << endl;
	cout << "2 - Edit string" << endl;
	cout << "3 - Remove string" << endl;
	cout << "4 - Search" << endl;
	cout << "5 - Get string length" << endl;
	cout << "6 - Get string Char" << endl;
	cout << "7 - Get String (char*)" << endl;
	cout << "8 - Edit Char" << endl;
	cout << "9 - a to A" << endl;
	cout << "10 - A to a" << endl;


}

int editOptions(char* buff)
{
	int ans = -1;
	cout << "Input Srting number: " << endl;
	cin >> ans;
	cout << "Input new text: " << endl;
	fflush(stdin);
	cin.getline(buff, 100);
	return ans;
}

int removeOptions()
{
	int ans = -1;
	cout << "Input Srting number: " << endl;
	cin >> ans;
	fflush(stdin);
	return ans;
}

int searchOptions(char* buff)
{
	int ans = -1;
	cout << "Input Srting number: " << endl;
	cin >> ans;
	cout << "Search: " << endl;
	fflush(stdin);
	cin.getline(buff, 100);
	return ans;
}

void printSearchResult(char* buff, int entry)
{
	for (int i = 0; i < entry; i++) cout << " ";
	for (int i = entry; i < (strlen(buff) + entry); i++) cout << "V";
	cout << endl;
}