#pragma once
#include <string>
using namespace std;

class Static
{
public:
    static string extractName(string path);
    static int isDigit(const string& input);
    static int findLastSpace(const string& line, unsigned comma);
};