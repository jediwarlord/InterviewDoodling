#include "stdafx.h"
#include <iostream>
#include "Hashtable.h"
#include "Interfaces.h"

using namespace std;

bool isPalindromePermutation(string palindrome)
{
	bool _oddeven = 0; //0 for odd....1 for even..
	//create new hashtable to hold all the characters...
	Hashtable * CharFrequency = new Hashtable(30);
	const char * c_palindrome = palindrome.c_str();

	// go through each char and populate hashtable...
	for (int i = 0; i < palindrome.length(); i++)
	{
		Item * test1 = new Item;
		test1->next = nullptr;
		test1->Key = new char[2];
		memcpy(test1->Key, c_palindrome + i, 1);
		test1->Key[1] = '\0';
		CharFrequency->insertItem(test1);
	}

	//now that we've created our hashtable... 
	//lets check to see if we have even counts based on the 
	//length of the palindrome string
	char * keyholder = new char[2];

	//check if even..
	if ((palindrome.length() % 2) == 0)
	{ // is even...
		int length = 0;
		for (char c : palindrome)
		{
			memcpy(keyholder, &c, 1);
			keyholder[1] = '\0';
			length = CharFrequency->getLength(keyholder);
			if (length % 2 == 1)
			{
				return false; //found a rogue char..
			}
		}
	}
	else
	{// is odd..meaning only one char can have 1 ocurence.. others need 2
		int length = 0;
		int oddnumber = 0;
		for (char c : palindrome)
		{
			memcpy(keyholder, &c, 1);
			keyholder[1] = '\0';
			length = CharFrequency->getLength(keyholder);
			if (length % 2 == 1)
				oddnumber++;

			if (oddnumber > 1)
				return false;
		}
	}

	return true;
	


}

int main() 
{

    LinkedList test;
	string * replaceString = new string("This is another test");
    Hashtable * table = new Hashtable(13);
	string palindrome = "tact coa";
	string *testing = new string("booyeah");

	(*testing)[5] = 'X';
	(*testing).at(5) = 'P';

    Item * test1 = new Item;
    test1->next = nullptr;
    test1->Key = (char *)"Key1";
	Item * test2;
    test1->next = nullptr;
    test1->Key = (char *)"Key2";

    table->insertItem(test1);
	test2 = table->getItemByKey(static_cast<char *>("Key2"));

	//question 1.....unique characters...
	UniqueCharacters();
	isUniqueChars("there are several");
	isPermuation("booyeah", "booyeah");
	replacecharInString(&replaceString, "test");
	int length = (*replaceString).length();

	//question 1.4 
	isPalindromePermutation(palindrome);

    cout << "Hello, World!" << endl;
    return 0;
}

void replacecharInString(std::string ** _str, std::string str)
{
	int spaces = 0, newsize;
	string * newString = nullptr;
	int length = (*_str)->length();
	//first we will check to see how many spaces there are 
	for (int i = 0; i < (*_str)->length(); i++ )
	{
		if ((*_str)->at(i) == ' ')
		{
			spaces++;
		}
	}

	//allocate a new string memory space that can hold all that..
	(*_str)->resize(length + spaces * 2);
	newsize = (*_str)->length() - 1;

	for (int i = length - 1; i > 0; i--)
	{
		if((*_str)->at(i) == ' ')
		{//found .. lets replace with what we want...
			(*(*_str))[newsize] = '0';
			(*(*_str))[newsize -1] = '2';
			(*(*_str))[newsize -2] = '%';
			newsize = newsize - 3;
		}
		else
		{
			cout << (*_str)->at(i);
			(*(*_str))[newsize] = (*(*_str))[i];
			newsize--;
		}
	}
}




//question 3 in chapter 1

bool isPermuation(string str1, string str2)
{
	int charcount[256] = { 0 };

	for (int i = 0; i < str1.length(); i++)
	{
		charcount[str1[i]] += 1;
	}

	for (int i = 0; i < str2.length(); i++)
	{
		charcount[str2[i]]--;
		if (charcount[str2[i]] < 0)
			return false;
	}
	return true;
}

bool isUniqueChars(string str)
{	
	int checker = 0;
 	for (int i = 0; i < str.length(); i++)
	{
		int val = str[i];
		if ((checker & (1 << val)) > 0)
		{
			return false;
		}
		checker |= (1 << val);
	}
	return true;
}

void UniqueCharacters()
{
	char _cinput[256];
	string teststring = "This is a test";
	string testing;
	char * input;
	bool Bitarray[256] = { 0 };         

	//cout << "Enter in a string... ";
	//getline(cin, testing);

	//want to check if there are unique chars in this string..
	for (int i = 0; i < teststring.length(); i++)
	{
		if (Bitarray[teststring[i]])
		{
			// not unique anymore..
			cout << "Not unique..\n";
			return;
		}
		Bitarray[teststring[i]] = 1;
	}

	

}