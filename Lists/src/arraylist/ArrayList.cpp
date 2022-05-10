#include "ArrayList.h"
#include <iostream>
#include <string>
using namespace std;



bool ArrayList::isEmpty()
{
	if (storage == NULL)
		return true; 
			else 
				return false; 
}

int ArrayList::size()
{
	return c;
}

bool ArrayList::add(string value)
{
	string *tmpVar;
	tmpVar = new string[c + 1];
	c++; 

	for (int i = 0; i < c - 1; i++)
		tmpVar[i] = storage[i];

	tmpVar[c - 1] = value;
	delete[] storage;
	storage = tmpVar;

	return true;
}

string ArrayList::get(int atIndex)
{
	if (atIndex >= 0 && atIndex < c)
		return storage[atIndex];
			else
		return "";
	
}

bool ArrayList::insert(string value, int atIndex)
{
	if (atIndex >= 0 && atIndex < c)
	{
		string *tmpVar1;
		tmpVar1 = new string[c + 1];

		for (int i = 0; i < c; i++) {
			if (i < atIndex) {
				tmpVar1[i] = storage[i];
			}

			else {
				tmpVar1[i + 1] = storage[i];
			}
		}

		tmpVar1[atIndex] = value;
		delete[] storage;

		storage = tmpVar1;
		c++;

		return true;
	}

	else {
		return false;
	}
}

string ArrayList::remove(int atIndex)
{
	if (atIndex >= c || atIndex < 0)
	{
		return "";
	}
	
	string tmpString = storage[atIndex];

	if(c == 1)
	{
		this->clear(); 
		return tmpString;
	}

	string *tmpVar4;
	tmpVar4 = new string[c - 1];

	for (int i = 0; i < c; i++)
	{
		if (i < atIndex)
		{
			tmpVar4[i] = storage[i];
		}

		else if (i > atIndex)
		{
			tmpVar4[i - 1] = storage[i];
		}
	}

	delete[] storage;
	storage = tmpVar4;
	c--;
	return tmpString;
}

void ArrayList::clear()
{
	if (storage != NULL)
	{
		delete[] storage;
	}

	storage = NULL;
	c = 0;
}

string ArrayList::set(int atIndex, string value)
{
	if (atIndex >= c || atIndex < 0)
	{
		return "";
	}

	string tmpString2 = storage[atIndex];
	storage[atIndex] = value;
	return tmpString2;
}

bool ArrayList::contains(string value)
{
	for (int i = 0; i < c; i++)
	{
		if (storage[i] == value)
		{
			return true;
		}
	}

	return false;
}

bool ArrayList::remove(string value)
{
	for (int i = 0; i < c; i++)
	{
		if (storage[i] == value)
		{
			this->remove(i);
			return true;
		}
	}

	return false;
}

int ArrayList::indexOf(string value)
{
	for (int i = 0; i < c; i++)
	{
		if (storage[i] == value)
		{
			return i;
		}
	}

	return -1;
}

int ArrayList::lastIndexOf(string value)
{
	for (int i = c - 1; i >= 0; i--)
	{
		if (storage[i] == value)
		{
			return i;
		}
	}

	return -1;
}
