#include <iostream>
#include <list>
#include "../SimpleList.h"
#include "../helper/TestHelper.h"
using namespace std;

string testValues[]     = { "a", "b", "c", "d", "e" };
int testValuesLength = sizeof(testValues) / sizeof(testValues[0]);
string advancedValues[] = { "a", "b", "a", "d", "b" };
int advancedValuesLength = sizeof(advancedValues) / sizeof(advancedValues[0]);

string testEmpty(SimpleList *uut)
{
	string results;
    try
    {
    	results += checkEquals(uut->size(), 0, "n/a", "Empty Test - list size incorrect");
    	results += checkTrue(uut->isEmpty(), "n/a", "Empty Test - list should have been empty");
    	results += checkEquals(uut->get(1), "", "1", "Empty Test - get from an empty list should return \"\"");
    	results += checkEquals(uut->remove(1), "", "1", "Empty Test - removing from an empty list should return \"\"");
    } catch (const exception& e)
    {
        results += "Empty Test failed got Exception\n";
    }
    return results;
}

/**
 * Fills the provided list with the test values.
 * Should be classed after the Happy Path test of add is confirmed
 * @param list the list to fill
 */
void fillList(SimpleList *uut, string with[], int n)
{
    for (int i = 0; i < n; i++)
    {
        uut->add(with[i]);
    }
}

string testAdd(SimpleList *uut)
{
	string results;
    try
    {
        int expectedCount = 0;
        for (string value : testValues)
        {
            bool actual = uut->add(value);
            expectedCount = expectedCount + 1;
            results += checkTrue(actual, value, "Add Test - add() returned false when expected true");
            int actualSize = uut->size();
            results += checkEquals(actualSize, expectedCount, value, "Add Test - size() did not match expected after add");
        }
    }
    catch (const exception& e)
    {
        results+= "Happy Path Test - add() failed\n";
    }
    return results;
}

string testGet(SimpleList *uut)
{
	string results;
    try
    {
        fillList(uut, testValues, testValuesLength);
        for (int i = 0; i < testValuesLength; i++)
        {
            string value = uut->get(i);
            results += checkEquals(value, testValues[i], to_string(i), "Get Test - get() failed");
        }
    }
    catch (const exception& e)
    {
        results += "Get Test failed- got Exception\n";
    }
    return results;
}

string testInsert(SimpleList *uut)
{
	string results;
    try
    {
    	for (int insertAt = 0; insertAt < testValuesLength; insertAt++)
    	{
			fillList(uut, testValues, testValuesLength);
			uut->insert("x", insertAt);
			results += checkEquals(uut->get(insertAt), "x", to_string(insertAt), "The inserted value was not found");
			results += checkEquals(uut->size(), testValuesLength + 1, "n/a", "The size did not increase after insert");
			for (int i = 0; i < insertAt; i++)
			{
				results += checkEquals(uut->get(i), testValues[i], to_string(i), "The values before the insert are incorrect");
			}
			for (int i = insertAt + 1; i < testValuesLength + 1; i++)
			{
				results += checkEquals(uut->get(i), testValues[i-1], to_string(i), "The values after the insert are incorrect");
			}
			uut->clear();

			if (results.size() > 0)
			{
				break;
			}
    	}
    }
    catch (const exception& e)
    {
        results += "Set Test failed- got Exception\n";
    }
    return results;
}

string testSet(SimpleList *uut)
{
	string results;
    try
    {
        fillList(uut, testValues, testValuesLength);
        for (int i = 0; i < testValuesLength; i++)
        {
            int reverseValue = testValuesLength - 1 - i;
            string actual = uut->set(i, testValues[reverseValue]);
            results += checkEquals(actual, testValues[i], to_string(i), "Set Test - set() did not return the expected replacement value");

            actual = uut->get(i);
            results += checkEquals(actual, testValues[reverseValue], to_string(i), "Set Test - get() after set() did not return the new value");
        }
    }
    catch (const exception& e)
    {
        results += "Set Test failed- got Exception\n";
    }
    return results;
}

string testClear(SimpleList *uut)
{
	string results;
    try
    {
    	results += testAdd(uut);
        uut->clear();
        int size = uut->size();
        results += checkEquals(size, 0, "n/a", "Clear Test - size was not zero after clear");
        results += checkTrue(uut->isEmpty(), "n/a", "Clear Test - isEmpty was not true after clear");
    }
    catch (const exception& e)
    {
        results += "Clear Test failed- got Exception\n";
    }
    return results;
}

string testRemove(SimpleList *uut)
{
	string results;
    try
    {
        fillList(uut, testValues, testValuesLength);
        for (int i = 0; i < testValuesLength; i++)
        {
            string actual = uut->remove(0);
            results += checkEquals(actual, testValues[i], to_string(i), "Remove Test - in order remove did not return the expected value");
            results += checkEquals(uut->size(), testValuesLength - i - 1, to_string(i), "Remove Test - in order remove - size did not match the expected value");
        }

        fillList(uut, testValues, testValuesLength);
        for (int i = testValuesLength - 1; i >= 0; i--)
        {
            string actual = uut->remove(i);
            results += checkEquals(actual, testValues[i], to_string(i), "Remove Test - reverse order remove did not return the expected value");
            results += checkEquals(uut->size(), i, to_string(i), "Remove Test - reverse order remove - size did not match the expected value");
        }

        fillList(uut, testValues, testValuesLength);
        std::list<string> exemplar;
        for (int i = 0; i < testValuesLength; i++)
        {
            exemplar.push_back(testValues[i]);
        }
        int safetyCount = testValuesLength;
        while (! uut->isEmpty())
        {
            if (safetyCount < 0)
            {
            	results += "Remove Test - from the middle remove - isEmpty() was not true after removing all elements";
            	break;
            }
            int index = uut->size() / 2;
            string actual = uut->remove(index);
            string expected;
            { // This goes to get and then remove the next item on the exemplar C++ list
                std::list<string>::iterator i = exemplar.begin();
                advance(i, index);
                expected = *i;
                exemplar.remove(expected);
            }
            results += checkEquals(actual, expected, to_string(index), "Remove Test - from the middle remove did not return the expected value");
            results += checkEquals(uut->size(), exemplar.size(), to_string(index), "Remove Test - from the middle remove - size did not match the expected value");
            safetyCount--;
        }
    }
    catch (const exception& e)
    {
        results += "Remove Test failed- got Exception\n";
    }
    return results;
}

string testEdgeCases(SimpleList *uut)
{
	string results;
    try
    {
    	results += testAdd(uut);
        string actual = uut->get(-1);
        results += checkEquals(actual, "", "-1", "Edge Case Test - get returned a value for an invalid index");
        actual = uut->get(6);
        results += checkEquals(actual, "", "6", "Edge Case Test - get returned a value for an invalid index");
    }
    catch (const exception& e)
    {
        results += "Edge Cases Test failed- got Exception\n";
    }
    return results;
}

string testContains(SimpleList *uut)
{
	string results;
    try
    {
        fillList(uut, advancedValues, advancedValuesLength);
        results += checkTrue(uut->contains("a"), "a", "Test Contains - did not contain the expected value");
        results += checkTrue(uut->contains("b"), "b", "Test Contains - did not contain the expected value");
        results += checkFalse(uut->contains("c"), "c", "Test Contains - contained a value not expected");
    }
    catch (const exception& e)
    {
    	results += "Contains Test failed - got Exception\n";
    }
    return results;
}

string testIndexOf(SimpleList *uut)
{
	string results;
    std::list<string> exemplar;
    for (int i = 0; i < advancedValuesLength; i++)
    {
        exemplar.push_back(advancedValues[i]);
    }

    try
    {
        fillList(uut, advancedValues, advancedValuesLength);
        int actual = uut->indexOf("a");
        std::size_t expected = 0;
        { // Go find the first example in a C++ list
            for (std::list<string>::iterator i = exemplar.begin(); i != exemplar.end(); i++)
            {
                if (*i == "a")
                {
                    break;
                }
                expected = expected + 1;
            }
            if (expected == exemplar.size())
            {
                expected = -1;
            }
        }
        results += checkEquals(actual, expected, "a", "Index Of Test Failed, did not find the correct index");
        actual = uut->indexOf("c");
        results += checkEquals(actual, -1, "c", "Index Of Test Failed, returned an index for a non-existing element");
    }
    catch (const exception& e)
    {
    	results += "Index Of failed - got Exception\n";
    }
    return results;
}
    
string testLastIndexOf(SimpleList *uut)
{
	string results;
    std::list<string> exemplar;
    for (int i = 0; i < advancedValuesLength; i++)
    {
        exemplar.push_back(advancedValues[i]);
    }
    try
    {
        fillList(uut, advancedValues, advancedValuesLength);
        int actual = uut->lastIndexOf("a");
        int expected = exemplar.size() - 1;
        { // Go find the last example in a C++ list
            for (std::list<string>::iterator i = exemplar.end(); i != exemplar.begin();)
            {
                i--; // must do this first on this one
                if (*i == "a")
                {
                    break;
                }
                expected = expected - 1;
            }
        }
        results += checkEquals(actual, expected, "a", "Last Index Of Test Failed, did not find the correct index");
        actual = uut->lastIndexOf("c");
        results += checkEquals(actual, -1, "c", "Last Index Of Test Failed, returned an index for a non-existing element");
    } catch (const exception& e)
    {
        results += "Last Index Of failed- got Exception\n";
    }
    return results;
}

string testRemoveObject(SimpleList *uut)
{
	string results;
    try
    {
        fillList(uut, advancedValues, advancedValuesLength);
        for (int i = 0; i < advancedValuesLength; i++)
        {
        	results += checkTrue(uut->remove(advancedValues[i]), advancedValues[i], "Remove Object (in order) failed, did not remove expected object");
        	results += checkEquals(uut->size(), advancedValuesLength - i - 1, "n/a", "Remove Object (in order) failed, size did not reduce");
        }

        fillList(uut, advancedValues, advancedValuesLength);
        for (int i = advancedValuesLength - 1; i >= 0; i--)
        {
        	results += checkTrue(uut->remove(advancedValues[i]), advancedValues[i], "Remove Object (reverse order) failed, did not remove expected object");
        	results += checkEquals(uut->size(), i, "n/a", "Remove Object (in order) failed, size did not reduce");
        }
    }
    catch (const exception& e)
    {
        results += "Remove object failed- got Exception\n";
    }
    return results;
}

string testLoad(SimpleList *uut)
{
	string results;
    try
    {
        for (int i = 0; i < 5000; i++)
        {
        	uut->add(to_string(i));
        	results += checkEquals(uut->size(), i + 1, "n/a", "Test Load - Added an item but the size did not match");
        	if (results.size() > 0)
        	{
        		break;
        	}
        }
    }
    catch (const exception& e)
    {
        results += "Test Load failed- got Exception\n";
    }
    return results;
}
