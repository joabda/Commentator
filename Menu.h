#pragma once

#include <iostream>
#include <string>
#include "Directory.h"
#include "Header.h"

using namespace std;

class Menu
{
public: 
    Menu();
    static int getLanguage();
    static string getSourcePath();

private:
    static bool verifyPath(string userInput);
};