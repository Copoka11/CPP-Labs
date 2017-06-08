
#include "functions_01.h"

void main()
{
	MyString A;
	MyString B("Test1 string");
	MyString C("Test2 hello world");
	MyString D("Test3 world wide web");
	MyString E("Test4 hello again");
	MyString F("Test5 good evening");

	MyString **S = new MyString*[6];
	S[0] = &A;
	S[1] = &B;
	S[2] = &C;
	S[3] = &D;
	S[4] = &E;
	S[5] = &F;
	
	/// lab_02 tests
	/*
	cout << "+ class test" << endl;
	MyString G = E + F;
	G.printString();
	system("pause");
	///////////////////////////////////////
	cout << "+ string test" << endl;
	MyString H = E + " and again";
	H.printString();
	system("pause");
	////////////////////////////////////////
	cout << "= test" << endl;
	MyString I("Before = ");
	I.printString();
	I = E;
	I.printString();
	system("pause");
	////////////////////////////////////////
	cout << "== test" << endl;
	MyString J("Test1 string");
	B.printString();
	J.printString();
	if (J == B)
		cout << "J==B" << endl;
	else
	cout << "not ==" << endl;
	system("pause");
	////////////////////////////////////////
	cout << "> test" << endl;
	MyString K("Test2 string");
	B.printString();
	K.printString();
	if (K > B)
		cout << "K>B" << endl;
	else
		cout << "not ==" << endl;
	system("pause");
	////////////////////////////////////////
	
	
	cout << "test string + class" << endl;
	MyString L;
	L = ("Test" + C);
	L.printString();
	system("pause");
	///////////////////////////////////////////////
	cout << "test (int)" << endl;
	cout << (int)C << endl;
	system("pause");

	///////////////////////////////////////////////
	cout << "test  << " << endl;
	cout << C << endl;
	system("pause");

	///////////////////////////////////////////////
	cout << "test  >> " << endl;
	cin >> D;
	cout << D << endl;
	system("pause");

	

	///////////////////////////////////////////////
	cout << "test ++C " << endl;
	cout << C;
	++C;
	cout << C;
	C++;
	cout << C;
	++C;
	cout << C;
	C++;
	cout << C;
	C--;
	cout << C;
	C--;
	cout << C;
	C--;
	cout << C;
	--C;
	cout << C;
	--C;
	cout << C;
	--C;
	cout << C;

	system("pause");
	/////////////////////////////////

	ofstream ofs("lab02.txt");
	ofs << C;
	ofs << D;
	ofs << E;
	ofs.close();
	cout << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "String N" << (i + 1) << ": "; S[i]->printString();
	}

	cout << endl;
	
	//////////////////////////////////////

	ifstream ifs("lab02.txt");
	ifs >> A;
	ifs >> B;
	ifs >> F;
	ifs.close();
	cout << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "String N" << (i + 1) << ": "; S[i]->printString();
	}

	cout << endl;

	///////////////////////////////
	*/

	/// lab_03 tests
	//////////////////
	
	cout << "Exception test" << endl;
	
	try
	{
		BinString BS1("00110011");
		BS1.printString();
		
		BinString BS2("not bin");
		BS2.printString();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	
	cout << endl;

	/////////////////////

	cout << "BinToInt Test " << endl;

	BinString BS3("00100001111");
	BS3.printString();
	cout << endl << endl;
	
	/////////////////////

	cout << "edit Test" << endl;
	BS3.editString("000111011100001100111");
	BS3.printString();
	cout << endl << endl;

	////////////
	
	cout << "set Value Test" << endl;
	BS3.setVal(206);
	BS3.printString();
	cout << endl << endl;

/////////////////////////////

	int ans = -1;
	int entry = -1;
	int strNum = 0;
	char buff[100];
	
	while (1)
	{
		printMenu();
		cin >> ans;
		
		if ((ans > 20) || (ans < 0))
		{
			cout << "Wrong input, try again" << endl << endl;
		}
		if (ans == 0) break;
		if (ans == 1)
		{
			cout << endl;
			for (int i = 0; i < 6; i++)
			{
				cout << "String N" << (i + 1) << ": "; S[i]->printString();
			}
	
			cout << endl;
		}
		if (ans == 2)							
		{
			strNum = editOptions(buff);			  
			if ((strNum > 0) || (strNum < 7))
				S[strNum-1]->editString(buff);
			strNum = 0;
		}
		if (ans == 3)
		{
			strNum = removeOptions();
			if ((strNum > 0) || (strNum < 7))
				S[strNum - 1]->removeString();
			strNum = 0;

		}
		if (ans == 4)
		{
			strNum = searchOptions(buff);
			
			if ((strNum > 0) || (strNum < 7))
			{
				entry = S[strNum - 1]->searchString(buff);
				if (entry != -1)
				{
					printSearchResult(buff, entry);
					S[strNum-1]->printString();
				}
				else cout << "not found" << endl;
			}
		}
		if (ans == 5)
		{
			cout << "String 3 length: " << S[2]->getStringLength() << endl << endl;
		}
		if (ans == 6)
		{
			S[2]->printString();
			cout << "String 3 symbol 7: " << S[2]->getCharN(7) << endl << endl;
		}
		if (ans == 7)
		{
			cout << "String 3: " << S[2]->getString() << endl;
		}
		if (ans == 8)
		{
			S[2]->printString();
			cout << "Replace char N 5: " << endl;
			S[2]->editChar('Y', 7);
			S[2]->printString();
		}
		if (ans == 9)
		{
			S[2]->editatoA();
			S[2]->printString();
		}
		if (ans == 10)
		{
			S[2]->editAtoa();
			S[2]->printString();
		}
	}
	system("pause");
	delete[] S;
}