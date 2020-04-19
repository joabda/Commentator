#pragma once
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Static
{
public:
    static string extractName(string path);
    static int isDigit(const string& input);
    static int findLastSpace(const string& line, unsigned comma);
    static unsigned getNextUpperCaseIndex(const string& line);
    static void toLower(string& mixed);
    static string parseLowerCamelCaseWord(const string& line);
};