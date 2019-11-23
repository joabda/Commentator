#pragma once

#include <iostream>
#include <string>
#include "Directory.h"

using namespace std;

class Menu
{
public: 
    Menu();
    static int getLanguage();
    static string getSourcePath();
    static int isDigit(const string& input);

private:
    static bool verifyPath(string userInput);
};