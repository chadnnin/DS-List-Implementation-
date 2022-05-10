#include "RecursiveLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

RecursiveLinkedList::RecursiveLinkedList()
{
	head = NULL;
	tail = NULL;
	counter = 0;
}

RecursiveLinkedList::~RecursiveLinkedList()
{
	this->clear();
}

bool RecursiveLinkedList::add(string value)
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

int RecursiveLinkedList::size()
{
	return counter;
}

bool RecursiveLinkedList::isEmpty()
{
	return head == NULL;
}

string RecursiveLinkedList::get(int atIndex)
{
	if (atIndex < 0 || atIndex > counter - 1)
	{
		return "";
	}

	return getInternal(atIndex, head);
}

string RecursiveLinkedList::getInternal(int atIndex, RecursiveLinkedList::Node *node)
{
	if (atIndex == 0)
	{
		return node->value;
	}

	else
	{
		return getInternal(atIndex - 1, node->next);
	}
}

bool RecursiveLinkedList::insert(string value, int atIndex)
{
	if (atIndex < 0 || atIndex > counter - 1)
	{
		return false;
	}

	if (atIndex == 0)
	{
		Node *addVal = new Node;
		addVal->value = value;
		addVal->next = head;
		head = addVal;
		counter++;
		return true;
	}

	return insertInternal(value, atIndex - 1, head);
}

bool RecursiveLinkedList::insertInternal(string value, int atIndex, RecursiveLinkedList::Node *node)
{
	if (atIndex == 0)
	{
		Node *insertNode = new Node;
		insertNode->value = value;
		insertNode->next = node->next;
		node->next = insertNode;
		counter++;
		return true;
	}

	else
	{
		return insertInternal(value, atIndex - 1, node->next);
	}
}

string RecursiveLinkedList::remove(int atIndex)
{
	Node *tmpHead = head;
	string tmpStr;

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

	return removeInternal(atIndex - 1, head);
}

string RecursiveLinkedList::removeInternal(int atIndex, RecursiveLinkedList::Node *node)
{
	string tmpStr;

	if (atIndex == 0)
	{
		tmpStr = node->next->value;
		delete node->next;
		node->next = node->next->next;
		counter--;

		if (node->next == NULL)
		{
			tail = node;
		}

		return tmpStr;
	}

	else
	{
		return removeInternal(atIndex - 1, node->next);
	}
}

void RecursiveLinkedList::clear()
{
	if (head != NULL)
	{
		Node *tmpPtr = head;
		head = tmpPtr->next;

		delete tmpPtr;
		this->clear();
	}

	else
	{
		counter = 0;
		tail = NULL;
	}
}

string RecursiveLinkedList::set(int atIndex, string value)
{
	if (atIndex < 0 || atIndex > counter - 1)
	{
		return "";
	}

	return setInternal(atIndex, value, head);
}

string RecursiveLinkedList::setInternal(int atIndex, string value, RecursiveLinkedList::Node *node)
{
	if (atIndex == 0)
	{
		tmpVar = node->value;
		node->value = value;
		return tmpVar;
	}

	else
	{
		return setInternal(atIndex - 1, value, node->next);
	}
}

bool RecursiveLinkedList::contains(string value)
{
	return containsInternal(value, head);
}

bool RecursiveLinkedList::containsInternal(string value, RecursiveLinkedList::Node *node)
{
	if (node == NULL)
	{
		return false;
	}

	else
	{
		if (node->value == value)
		{
			return true;
		}

		else
		{
			node = node->next;
			return containsInternal(value, node);
		}
	}
}

bool RecursiveLinkedList::remove(string value)
{
	Node *tmpHead = head;
	string tmpStr;

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

	return removeInternal(value, head);
}

bool RecursiveLinkedList::removeInternal(string value, RecursiveLinkedList::Node *node)
{
	if (node == NULL)
	{
		return false;
	}

	if (node->next != NULL && node->next->value == value)
	{
		delete node->next;
		node->next = node->next->next;
		counter--;

		if (node->next == NULL)
		{
			tail = node;
		}

		return true;
	}

	return removeInternal(value, node->next);
}

int RecursiveLinkedList::indexOf(string value)
{
	return indexOfInternal(value, head, -1);
}

int RecursiveLinkedList::indexOfInternal(string value, RecursiveLinkedList::Node *node, int cnt)
{
	if (node == NULL)
	{
		return -1;
	}

	else
	{
		cnt++;

		if (node->value == value)
		{
			return cnt;
		}

		else
		{
			node = node->next;
			return indexOfInternal(value, node, cnt);
		}
	}
}

int RecursiveLinkedList::lastIndexOf(string value)
{
	return lastIndexOfInternal(value, head, -1, -1);
}

int RecursiveLinkedList::lastIndexOfInternal(string value, RecursiveLinkedList::Node *node, int cnt, int lastNode)
{
	if (node == NULL)
	{
		return lastNode;
	}

	else
	{
		cnt++;

		if (node->value == value)
		{
			lastNode = cnt;
		}

		node = node->next;
		return lastIndexOfInternal(value, node, cnt, lastNode);
	}
}


