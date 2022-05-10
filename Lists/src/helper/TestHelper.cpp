#include <string>
#include <iostream>
#include <vector>

//#include <algorithm>
using namespace std;

string checkEquals(string actual, string expected, string input, string message)
{
    if (actual == expected)
    {
    	return "";
    } else
    {
        return message + " your code returned \"" + actual + "\" but I expected \"" + expected + "\" for the input \"" + input + "\"\n";
    }
}

string checkEquals(int actual, int expected, string input, string message)
{
    if (actual == expected)
    {
    	return "";
    } else
    {
        return message + " your code returned " + to_string(actual) + " but I expected " + to_string(expected) + " for the input " + input + "\n";
    }
}

string checkEquals(double actual, double expected, double threshold, string input, string message)
{
    if (actual < expected + threshold && actual > expected - threshold)
    {
    	return "";
    } else
    {
        return message + " your code returned " + to_string(actual) + " but I expected " + to_string(expected) + " for the input " + input + "\n";
    }
}

string checkEquals(double actual, double expected, int input[], int size, string message)
{
	string inputs;
	for (int i = 0; i < size; i++)
	{
		inputs += to_string(input[i]);
		if (i < size - 1)
		{
			inputs += ", ";
		}
	}
	inputs += "]\n";
	return checkEquals(actual, expected, 0.001, inputs, message);
}

string checkTrue(bool actual, string input, string message)
{
    if (actual)
    {
    	return "";
    } else
    {
        return message + " your code returned false but I expected true for the input " + input + "\n";
    }
}

string checkFalse(bool actual, string input, string message)
{
    if (actual)
    {
        return message + " your code returned true but I expected false for the input " + input + "\n";
    } else
    {
    	return "";
    }
}

string checkEquals(vector<char> actual, vector<char> expected, string input, string message)
{
	bool success = true;
	if (expected.size() == actual.size())
	{
		for (int i = 0; i < expected.size(); i++)
		{
			success &= actual[i] == expected[i];
		}
	} else
	{
		return "You returned a vector of size " + to_string(actual.size()) + " but I expected it to be " + to_string(expected.size());
	}

    if (success)
    {
    	return "";
    } else
    {
    	string actualArray = "[";
    	for (int i = 0; i < actual.size(); i++)
    	{
    		actualArray += to_string(actual[i]);
    		if (i < actual.size() - 1)
    		{
    			actualArray += ", ";
    		}
    	}
    	actualArray += "]\n";

    	string expectedArray = "[";
    	for (int i = 0; i < expected.size(); i++)
    	{
    		expectedArray += to_string(expected[i]);
    		if (i < expected.size() - 1)
    		{
    			expectedArray += ", ";
    		}
    	}
    	expectedArray += "]\n";

    	return message + " your code returned \"" + actualArray + "\" but I expected \"" + expectedArray + "\" for the input \"" + input + "\"\n";
    }
}

string checkEquals(vector<int> actual, vector<int> expected, string input, string message)
{
	bool success = true;
	if (expected.size() == actual.size())
	{
		for (int i = 0; i < expected.size(); i++)
		{
			success &= actual[i] == expected[i];
		}
	} else
	{
		return "You returned a vector of size " + to_string(actual.size()) + " but I expected it to be " + to_string(expected.size());
	}

    if (success)
    {
    	return "";
    } else
    {
    	string actualArray = "[";
    	for (int i = 0; i < actual.size(); i++)
    	{
    		actualArray += to_string(actual[i]);
    		if (i < actual.size() - 1)
    		{
    			actualArray += ", ";
    		}
    	}
    	actualArray += "]\n";

    	string expectedArray = "[";
    	for (int i = 0; i < expected.size(); i++)
    	{
    		expectedArray += to_string(expected[i]);
    		if (i < expected.size() - 1)
    		{
    			expectedArray += ", ";
    		}
    	}
    	expectedArray += "]\n";

    	return message + " your code returned \"" + actualArray + "\" but I expected \"" + expectedArray + "\" for the input \"" + input + "\"\n";
    }
}
