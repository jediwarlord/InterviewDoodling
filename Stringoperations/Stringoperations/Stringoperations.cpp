// Stringoperations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void stringreverse(TCHAR* _reverse);
bool stringpermuation(TCHAR* _string1, TCHAR* _string2);

int _tmain(int argc, _TCHAR* argv[])
{
	bool permresult = NULL;

	TCHAR stringtoreverse[] = _T("Reverse this string");

	TCHAR firststring[] = _T("this my");
	TCHAR secondstring[] = _T("tym shi");

	permresult = stringpermuation(firststring, secondstring);
	stringreverse(stringtoreverse);
	return 0;
}

void stringreverse(TCHAR* _reverse)
{
	//lets get string length.

	int length = 0;
	TCHAR temp = ' ';
	TCHAR* temppointer = NULL;

	temppointer = _reverse;

	while (*_reverse++ != NULL)
	{

		length++;
	}

	_reverse--;
	_reverse--;

	while (temppointer < _reverse)
	{
		temp = *_reverse;
		
		*_reverse = *temppointer;
		*temppointer = temp;
		*temppointer++; _reverse--;

	}
	//now start from the last part of the string and g


}

void bubblesort(TCHAR* _string)
{
	bool swapped = true;
	int length = 0;
	TCHAR* temppointer = _string;

	while (*temppointer++ != NULL)
	{
		length++;
	}


	while (swapped)
	{
		swapped = false;
		for (int i = 0; i < length; i++)
		{
			if (_string[i + 1] == _T('\0'))
			{
				break;
			}
			if (_string[i] > _string[i + 1])
			{
				TCHAR temp = ' ';
				temp = _string[i + 1];
				_string[i + 1] = _string[i];
				_string[i] = temp;
				swapped = true;
			}
		}
		
		
	}
	
}

bool stringpermuation(TCHAR* _string1, TCHAR* _string2)
{
	bool permutation = false;

	//we need to sort the strings first
	bubblesort(_string1);
	bubblesort(_string2);

	//check if they are a permutation.
	while (*_string1 != _T('\0') || *_string2 != _T('\0'))
	{
		if (*_string1 == *_string2)
		{
			_string1++; _string2++;
			continue;
		}
		 else
		 {
			 return false;
		 }
	}

	if (*_string1 == _T('\0') && *_string2 == _T('\0'))
	{
		return true;
	}
	return false;
}

