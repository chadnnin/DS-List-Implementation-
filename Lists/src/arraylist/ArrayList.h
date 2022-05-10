#pragma once
#include "../SimpleList.h"

class ArrayList : public SimpleList
{

public:
	int size();
	bool isEmpty();
	bool add(string value);
	bool insert(string value, int atIndex);
	string get(int atIndex);
	string remove(int atIndex);
	void clear();
	string set(int atIndex, string value);
	bool contains(string value);
	bool remove(string value);
	int indexOf(string value);
	int lastIndexOf(string value);

private:
	string* storage;
	int c; 
};
