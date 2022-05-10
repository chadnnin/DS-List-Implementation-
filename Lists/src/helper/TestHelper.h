#pragma once
#include <string>
#include <vector>
using namespace std;

string checkEquals(string actual, string expected, string input, string message);
string checkEquals(int actual,    int expected,    string input, string message);
string checkEquals(double actual, double expected, double threshold, string input, string message);
string checkEquals(double actual, double expected, int input[], int size, string message);
string checkTrue(bool actual, string input, string message);
string checkFalse(bool actual, string input, string message);
string checkEquals(vector<char> actual, vector<char> expected, string input, string message);
string checkEquals(vector<int> actual, vector<int> expected, string input, string message);
