#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

LinkedList::LinkedList()
{
	head = NULL; 
	tail = NULL;
	counter = 0;
}

LinkedList::~LinkedList()
{
	clear();
}

bool LinkedList::add(string value)
{
	Node *addNode = new Node;

	addNode->value = value;
	addNode->next = NULL;

	if (head == NULL)
	{
		head = addNode;  
		tail = addNode;
		counter++;
	}

	else
	{
		tail->next = addNode;
		tail = addNode;
		counter++;
	}

	return true;
}

int LinkedList::size()
{
	return counter;
}

bool LinkedList::isEmpty()
{
	return head == NULL; 
}

string LinkedList::get(int atIndex)
{
	Node *tmpHead = head;
	int cntNode = -1;

	if (atIndex < 0 || atIndex > counter - 1)
	{
		return "";
	}

	while (tmpHead != NULL)
	{
		cntNode++;

		if (cntNode == atIndex)
		{
			return tmpHead->value;
		}

		else
		{
			tmpHead = tmpHead->next;
		}
	}

	return "";
}

bool LinkedList::insert(string value, int atIndex)
{
	Node *tmpHead = head;
	int cntNode = -1;

	if (atIndex < 0 || atIndex > counter - 1)
	{
		return false;
	}

	Node *addVal = new Node;
	addVal->value = value;

	if (atIndex == 0)
	{
		addVal->next = head;
		head = addVal;
		counter++;
		return true;
	}

	while (tmpHead != NULL)
	{
		cntNode++;

		if (cntNode == atIndex - 1)
		{
			addVal->next = tmpHead->next;
			tmpHead->next = addVal;
			counter++;
			return true;
		}

		else
		{
			tmpHead = tmpHead->next;
		}
	}

	return false;
}

string LinkedList::remove(int atIndex)
{
	Node *tmpHead = head;
	string tmpStr;
	int cntNode = -1;

	if (atIndex < 0 || atIndex > counter - 1)
	{
		return "";
	}

	if (atIndex == 0)
	{
		tmpStr = tmpHead->value;
		head = head->next;
		delete tmpHead;
		counter--;

		if (head == NULL)
		{
			tail = NULL;
		}

		return tmpStr;
	}

	while (tmpHead != NULL)
	{
		cntNode++;

		if (cntNode == atIndex - 1)
		{
			tmpStr = tmpHead->next->value;
			delete tmpHead->next;
			tmpHead->next = tmpHead->next->next;         
			counter--;

			if (tmpHead->next == NULL)
			{
				tail = tmpHead;
			}

			return tmpStr;
		}

		else
		{
			tmpHead = tmpHead->next;
		}
	}

	return "";
}

void LinkedList::clear()
{
	if (head != NULL)
	{
		counter = 0;
		tail = NULL;
		Node *tmpPtr = head;
		Node *tmpNext;
		head = NULL;

		while (tmpPtr != NULL)
		{
			if (tmpPtr->next != NULL)
			{
				tmpNext = tmpPtr->next;
				delete tmpPtr;
				tmpPtr = tmpNext;
			}

			else
			{
				delete tmpPtr;
				tmpPtr = NULL;
			}
		}
	}
}

string LinkedList::set(int atIndex, string value)
{
	Node *tmpHead = head;
	int cntNode = -1;
	string tmpVal;

	if (atIndex < 0 || atIndex > counter - 1)
	{
		return "";
	}

	while (tmpHead != NULL)
	{
		cntNode++;

		if (cntNode == atIndex)
		{
			tmpVal = tmpHead->value;
			tmpHead->value = value;
			return tmpVal;
		}

		else
		{
			tmpHead = tmpHead->next;
		}
	}

	return "";
}

bool LinkedList::contains(string value)
{
	Node *tmpHead = head;
	string tmpVal;

	while (tmpHead != NULL)
	{
		if (tmpHead->value == value)
		{
			return true;
		}

		else
		{
			tmpHead = tmpHead->next;
		}
	}

	return false;
}

bool LinkedList::remove(string value)
{
	Node *tmpHead = head;
	string tmpStr;
	int cntNode = -1;

	if (tmpHead == NULL)
	{
		return false;
	}

	if (tmpHead->value == value)
	{
		head = head->next;
		delete tmpHead;
		counter--;

		if (head == NULL)
		{
			tail = NULL;
		}

		return true;
	}

	while (tmpHead != NULL)
	{
		cntNode++;

		if (tmpHead->next != NULL && tmpHead->next->value == value)
		{
			tmpStr = tmpHead->next->value;
			delete tmpHead->next;
			tmpHead->next = tmpHead->next->next;
			counter--;

			if (tmpHead->next == NULL)
			{
				tail = tmpHead;
			}

			return true;
		}

		else
		{
			tmpHead = tmpHead->next;
		}
	}

	return false;
}

int LinkedList::indexOf(string value)
{
	Node *tmpHead = head;
	int cntNode = -1;
	int tmpCnt = -1;
	string tmpVal;

	while (tmpHead != NULL)
	{
		cntNode++;
		if (tmpHead->value == value)
		{
			tmpCnt = cntNode;
			return tmpCnt;
		}

		tmpHead = tmpHead->next;
	}

	return tmpCnt;
}

int LinkedList::lastIndexOf(string value)
{
	Node *tmpHead = head;
	int cntNode = -1;
	int tmpCnt = -1;


	while (tmpHead != NULL)
	{
		cntNode++;
		if (tmpHead->value == value)
		{
			tmpCnt = cntNode;
		}

		tmpHead = tmpHead->next;
	}

	return tmpCnt;
}
