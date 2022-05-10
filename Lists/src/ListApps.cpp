#include <iostream>
#include "arraylist/ArrayList.h"
#include "linkedlist/LinkedList.h"
#include "recursivelinkedlist/RecursiveLinkedList.h"
#include "tests/ListTests.h"

const int ARRAY_LIST = 1;
const int LINKED_LIST = 2;
const int RECURSIVE_LINKED_LIST = 3;

////////////////////////////////////////////////////////////////////////////////
// Set the data structure you are working on here to one of the choices above
int currentAssignment = RECURSIVE_LINKED_LIST;
// "all" runs every test or you can focus on one test by changing it to
// one of the names within main
string subtest = "all";

void processParamters(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	processParamters(argc, argv);

	SimpleList *uut;
	switch (currentAssignment)
	{
		case ARRAY_LIST:            uut = new ArrayList(); break;
		case LINKED_LIST:           uut = new LinkedList(); break;
		case RECURSIVE_LINKED_LIST: uut = new RecursiveLinkedList(); break;
	}

    string results;
    if (subtest == "all")
    {
    	cout << "-------Test Add----------------------------" << endl;
		results += testAdd(uut);
		uut->clear();
    	cout << "-------Test Clear----------------------------" << endl;
		results += testClear(uut);
		if (results.size() > 0)
		{
			results += "Without add and clear the other tests are not accurate, fix these and then continue\n";
		} else
		{
			uut->clear();
	    	cout << "-------Test Get----------------------------" << endl;
			results += testGet(uut);
			uut->clear();
	    	cout << "-------Test Contains----------------------------" << endl;
			results += testContains(uut);
			uut->clear();
	    	cout << "-------Test Insert----------------------------" << endl;
			results += testInsert(uut);
			uut->clear();
	    	cout << "-------Test Set----------------------------" << endl;
			results += testSet(uut);
			uut->clear();
	    	cout << "-------Test Remove----------------------------" << endl;
			results += testRemove(uut);
			uut->clear();
	    	cout << "-------Test Edge Cases----------------------------" << endl;
			results += testEdgeCases(uut);
			uut->clear();
	    	cout << "-------Test Index Of----------------------------" << endl;
			results += testIndexOf(uut);
			uut->clear();
	    	cout << "-------Test Last Index Of----------------------------" << endl;
			results += testLastIndexOf(uut);
			uut->clear();
	    	cout << "-------Test Remove Value----------------------------" << endl;
			results += testRemoveObject(uut);
			uut->clear();
	    	cout << "-------Test Empty----------------------------" << endl;
			results += testEmpty(uut);
			uut->clear();
	    	cout << "-------Test Load----------------------------" << endl;
			results += testLoad(uut);
		}
    } else if (subtest == "add")          { results += testAdd(uut);
    } else if (subtest == "clear")        { results += testClear(uut);
    } else if (subtest == "get")          { results += testGet(uut);
    } else if (subtest == "contains")     { results += testContains(uut);
    } else if (subtest == "insert")       { results += testInsert(uut);
    } else if (subtest == "set")          { results += testSet(uut);
    } else if (subtest == "remove")       { results += testRemove(uut);
    } else if (subtest == "edge")         { results += testEdgeCases(uut);
    } else if (subtest == "indexOf")      { results += testIndexOf(uut);
    } else if (subtest == "lastIndexOf")  { results += testLastIndexOf(uut);
    } else if (subtest == "removeObject") { results += testRemoveObject(uut);
    } else if (subtest == "empty")        { results += testEmpty(uut);
	} else if (subtest == "load")         { results += testLoad(uut);}

    if(results.size() == 0)
    {
    	cout << "All Test Passed!";
    } else
    {
    	cout << results;
    }
}

void processParamters(int argc, char *argv[])
{
	if (argc == 1) {return;}
	if (string(argv[1]) == "arraylist")       currentAssignment = ARRAY_LIST;
	else if (string(argv[1]) == "linkedlist") currentAssignment = LINKED_LIST;
	else if (string(argv[1]) == "recursive")  currentAssignment = RECURSIVE_LINKED_LIST;

	if (argc > 2) subtest = argv[2];
}
