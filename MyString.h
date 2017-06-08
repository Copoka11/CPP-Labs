#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>


using namespace std;

class MyString
{
private:
	char cTime[10];							//������ ��� �������� ������� ����. ���.
	char cDate[10];							//������ ��� �������� ���� ����. ���.
	char *str;								//������ ��� �������� �������� ������ �������
	int maxL = 100;							//���������� - ������������ ����� ������
	
	char* strLenToString(const char *tStr);

public:
	MyString();								//����������� ������� ������ �� ���������
	MyString(const char *tStr);				//����������� ������� ������ � ����������
	MyString(const MyString &t);			//����������� ������������ ������� ������ 
	~MyString();							//���������� ������� ������
	
//	const char const * intToStr();
	
	void printString();						//����� ������ ������ �� �������
	void editString(const char *tStr);		//����� �������������� ������ �������
	void removeString();					//����� �������� ����������� ������ �������
	int searchString(const char *tStr);		//����� ������ ��������� � ������ �������
											//���������� ��������� �� ������ ���������
	int getStringLength();					//����� ���������� ����������� ����� ������ 
	char getCharN(int charN);				//����� ���������� n-��� ������ ������
	const char const * getString();			//����� ���������� ������ �������
	void editChar(char tC, int charN);		//����� �������� n-�� ������� �� ���������
	void editatoA();						//����� �������� �������� ������� ����������
	void editAtoa();						//����� �������� ��������� ������� ���������
	

	///////////////////////Lab_02

	MyString operator + (const MyString &rhs);		//�����+�����
	MyString operator + (const char* tStr);			//�����+������
	MyString& operator = (const MyString &rhs);		//����������
	bool operator == (const MyString &rhs);
	bool operator > (const MyString &rhs);
	bool operator < (const MyString &rhs);
	bool operator != (const MyString &rhs);
	operator int();
	MyString operator ++();					//���������� ���������
	MyString operator ++(int);				//����������� ���������
	MyString operator --();
	MyString operator --(int);
	friend MyString operator + (const char* lhs, const MyString &rhs);	//������ + �����
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