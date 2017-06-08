#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>


using namespace std;

class MyString
{
private:
	char cTime[10];							//строка для хранения времени посл. изм.
	char cDate[10];							//строка для хранения даты посл. изм.
	char *str;								//строка для хранения основной строки объекта
	int maxL = 100;							//переменная - максимальная длина строки
	
	char* strLenToString(const char *tStr);

public:
	MyString();								//конструктор объекта класса по умолчанию
	MyString(const char *tStr);				//конструктор объекта класса с параметром
	MyString(const MyString &t);			//конструктор копироывания объекта класса 
	~MyString();							//деструктор объекта класса
	
//	const char const * intToStr();
	
	void printString();						//метод вывода данных об объекте
	void editString(const char *tStr);		//метод редактирования строки объекта
	void removeString();					//метод удаления содержимого строки объекта
	int searchString(const char *tStr);		//метод поиска подстроки в строке объекта
											//возвращает указатель на первое вхождение
	int getStringLength();					//метод возвращает фактическую длину строки 
	char getCharN(int charN);				//метод возвращает n-ный символ строки
	const char const * getString();			//метод возвращает строку объекта
	void editChar(char tC, int charN);		//метод заменяет n-ый элемент на указанный
	void editatoA();						//метод заменяет строчные символы прописными
	void editAtoa();						//метод заменяет прописные символы строчными
	

	///////////////////////Lab_02

	MyString operator + (const MyString &rhs);		//класс+класс
	MyString operator + (const char* tStr);			//класс+строка
	MyString& operator = (const MyString &rhs);		//присвоение
	bool operator == (const MyString &rhs);
	bool operator > (const MyString &rhs);
	bool operator < (const MyString &rhs);
	bool operator != (const MyString &rhs);
	operator int();
	MyString operator ++();					//префиксный инкремент
	MyString operator ++(int);				//постфиксный инкремент
	MyString operator --();
	MyString operator --(int);
	friend MyString operator + (const char* lhs, const MyString &rhs);	//строка + класс
	friend ostream& operator << (ostream &out, const MyString &obj);
	friend istream& operator >> (istream &in, MyString &obj);

	friend ofstream& operator << (ofstream &ofs, MyString &obj);
	friend ifstream& operator >> (ifstream &ifs, MyString &obj);

};

	//////////////////////lab_03

class BinString :public MyString
{
	long binVal;
	void binToVal();						//

public:
	BinString();						//
	BinString(const char* tStr);		//
//	BinString(const BinString &t);		//
	~BinString();						//
					
	long getBinVal();					//
	void printString();					//
	void editString(const char* tStr);	//
	void setVal(int val);				//
};

class ToDo : public MyString
{

};