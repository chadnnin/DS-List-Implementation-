#pragma once
#include "../SimpleList.h"

class RecursiveLinkedList : public SimpleList
{
public:
	RecursiveLinkedList(); 
	~RecursiveLinkedList(); 
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
	class Node 
	{

	public:
		string value; 
		Node* next; 
	};

	int counter; 
	string tmpVar; 
	Node* head; 
	Node* tail; 

	bool insertInternal(string value, int atIndex, Node* node); 
	string getInternal(int atIndex, Node* node);
	bool containsInternal(string value, Node* node); 
	int indexOfInternal(string value, Node* node, int cnt); 
	string setInternal(int atIndex, string value, Node* node); 
	int lastIndexOfInternal(string value, Node* node, int cnt, int lastNode); 
	string removeInternal(int atIndex, Node* node);
	bool removeInternal(string value, Node* node);
};
