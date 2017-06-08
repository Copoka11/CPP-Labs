#include "MyString.h"

MyString::MyString()
{
	str = new char[maxL];
	strcpy(str, "000");
	_strdate(cDate);
	_strtime(cTime);
}

char* MyString::strLenToString(const char *tStr)
{
	char tmp[4];
	int len = strlen(tStr);
	tmp[0] = '0' + len / 100;
	tmp[1] = '0' + len % 100 / 10;
	tmp[2] = '0' + len % 10;
	tmp[3] = '\0';
	return tmp;
}


MyString::MyString(const char* tStr)
{
	str = new char[maxL];
//	strLenToString(tStr);
	strcpy(str, strLenToString(tStr));
	strcat(str, tStr);
	_strdate(cDate);
	_strtime(cTime);
}

MyString::MyString(const MyString &t)
{
	str = new char[maxL];
	strcpy(str, t.str);
	_strdate(cDate);
	_strtime(cTime);
}

MyString::~MyString()
{
	delete[] str;
}

void MyString::printString()
{
	cout << (str+3) << "  (" << str[0] << str[1] << str[2] << ")" << endl;
	cout << "Last edit: " << cTime << "  " << cDate << endl;
}

void MyString::editString(const char* tStr)
{

//	strLenToString(tStr);
	strcpy(str, strLenToString(tStr));
	strcat(str, tStr);
	_strdate(cDate);
	_strtime(cTime);
}

void MyString::removeString()
{
	strcpy(str, "000");
	_strdate(cDate);
	_strtime(cTime);
}

int MyString::searchString(const char* tStr)
{
	int entry = -1;
	char *tmp;
	
	tmp = strstr((str+3), tStr);
	if (tmp != NULL)
		entry = (int)(tmp - str - 3);
	return entry;
}

int MyString::getStringLength()
{
	int strLen = 0;
	strLen = (str[0]-'0')*100 + (str[1]-'0')*10 + (str[2]-'0') ;
	return strLen;
}

char MyString::getCharN(int charN)
{
	char c;
	c = str[charN+3-1];
	return c;
}

const char const * MyString::getString()
{
	return (str+3);
}

void MyString::editChar(char tC, int charN)
{
	str[charN+3-1] = tC;
	_strdate(cDate);
	_strtime(cTime);
}

void MyString::editatoA()
{
	int shift = 'a' - 'A';
	for (int i = 3; i < getStringLength()+3; i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z')) str[i] -= shift;
	}
	_strdate(cDate);
	_strtime(cTime);
}

void MyString::editAtoa()
{
	int shift = 'a' - 'A';
	for (int i = 3; i < getStringLength()+3; i++)
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z')) str[i] += shift;
	}
	_strdate(cDate);
	_strtime(cTime);
}

//////////////////////////// lab_02

MyString MyString::operator + (const MyString &rhs)
{
	MyString tmp;
	char* strLen;
	strcat(tmp.str, str + 3);
	strcat(tmp.str, rhs.str + 3);
	strLen = strLenToString(tmp.str+3);
	strncpy(tmp.str, strLen, 3);
	_strdate(cDate);
	_strtime(cTime);
	return tmp;
}

MyString MyString::operator + (const char* tStr)
{
	MyString tmp;
	char* strLen;
	strcat(tmp.str, str + 3);
	strcat(tmp.str, tStr);
	strLen = strLenToString(tmp.str+3);
	strncpy(tmp.str, strLen, 3);
	_strdate(cDate);
	_strtime(cTime);
	return tmp;
}

MyString& MyString::operator = (const MyString &rhs)
{
	if (*this == rhs)
		return *this;
	strcpy(str, rhs.str);
	strcpy(cDate, rhs.cDate);
	strcpy(cTime, rhs.cTime);
	return *this;
}

MyString operator + (const char* lhs, const MyString &rhs)
{
	MyString tmp;
	char* strLen;
	strcat(tmp.str, lhs);
	strcat(tmp.str, rhs.str+3);
	strLen = tmp.strLenToString(tmp.str+3);
	strncpy(tmp.str, strLen, 3);
	_strdate(tmp.cDate);
	_strtime(tmp.cTime);
	return tmp;
}

bool MyString::operator == (const MyString &rhs)
{
	if (strcmp(str, rhs.str) == 0) return true;
	else return false;
}

bool MyString::operator > (const MyString &rhs)
{
	if (strcmp(str, rhs.str) > 0) return true;
	else return false;
}

bool MyString::operator < (const MyString &rhs)
{
	if (strcmp(str, rhs.str) < 0) return true;
	else return false;
}

bool MyString::operator != (const MyString &rhs)
{
	if (strcmp(str, rhs.str) != 0) return true;
	else return false;
}

MyString::operator int()
{
	return getStringLength();
}

ostream& operator << (ostream& out, const MyString& obj)
{
	out << (obj.str + 3) << "  (" << obj.str[0] << obj.str[1] << obj.str[2] << ")" << endl;
	return out;
}

istream& operator >> (istream& in, MyString& obj)
{

	char tStr[100];
	fflush(stdin);
	in.getline(tStr, 100);
	obj.editString(tStr);
	return in;
}

MyString MyString::operator ++ ()
{
	*this = "#" + *this;
	return *this;
}

MyString MyString::operator ++ (int)
{
	*this = *this + "#";
	return *this;
}

MyString MyString::operator--()
{
	char tmp[4];
	strcpy(str + 3, str + 4);
	strcpy(tmp, strLenToString(str + 3));
	strncpy(str, tmp, 3);
	return *this;
}

MyString MyString::operator--(int)
{
	str[strlen(str) - 1] = '\0';
	char tmp[4];
	strcpy(tmp, strLenToString(str+3));
	strncpy(str, tmp, 3);
	return *this;
}

ofstream& operator << (ofstream &ofs, MyString &obj)
{
	ofs << obj.cDate << obj.cTime << obj.str << endl;
	return ofs;
}

ifstream& operator >> (ifstream &ifs, MyString &obj)
{
	char buff[255];
	ifs.getline(buff, 255);
	strncpy(obj.cDate, buff, 8);
	strncpy(obj.cTime, buff+8, 8);
	strncpy(obj.str, buff+16, obj.maxL);
	return ifs;
}

////////////////////////////// lab_03

void BinString::binToVal()
{
	char* tmp;
	binVal = strtol(getString(), &tmp, 2);
}


BinString::BinString() :MyString()
{
	binVal = 0;
}

BinString::BinString(const char* tStr) : MyString(tStr)
{
	for (int i = 0; tStr[i] != '\0'; i++)
	{
		if ((tStr[i] != '0') && (tStr[i] != '1'))
		{
			throw exception("String is not bin");
		}
	}
	binToVal();
}

BinString::~BinString()
{
	~MyString();
}

void BinString::printString()
{
	MyString::printString();
	cout << binVal << endl;
}

long BinString::getBinVal()
{
	return binVal;
}

void BinString::editString(const char* tStr)
{
	for (int i = 0; tStr[i] != '\0'; i++)
	{
		if ((tStr[i] != '0') && (tStr[i] != '1'))
		{
			throw exception("String is not bin");
		}
	}
	MyString::editString(tStr);
	binToVal();
}

void BinString::setVal(int val)
{
	binVal = val;
	char tmp[100];
	editString(_ltoa(val, tmp, 2));
}