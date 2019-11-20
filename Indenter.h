#pragma once

#include <string>
#include <fstream>
#include <memory>
#include <vector>

#include <iostream>

using namespace std;

class Indenter
{
    public:
        static void source(const string& fileName);
        static void source(ostream& commented, const vector<string>& hold);
        static void header(const string& fileName);
        static void header(ostream& commented, const vector<string>& hold);

    private:
        static void writeInFile(ostream& commented, vector<string>& indents, 
            const vector<string>& hold, vector<int>& bracketCount);
        static vector<string> readFile(istream& sourceFile);

        template<typename T> static vector<T> initializeEmpty(const int& numberOfElementsNeeded, const T& initValue);
};
