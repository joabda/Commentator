#include <iostream>
#include <string>
#include <vector>

#include "Header.h"
#include "Parse.h"
#include "ParseCpp.h"
#include "ParseJava.h"   
#include "Directory.h"
using namespace std;

int languageChoice()
{
    int choice = 0;
    while(choice < 1 || choice > 2)
    {
        cout << "Pleaser enter what language you are using: " << endl;
        cout << "1- C++" << endl;
        cin >> choice;
    }
    return choice;
}

bool verifyPath(string userInput)
{
    if(userInput[0] == '\'')
        cout << Directory::validatePath(userInput);
    return false;
}

string getSourcePath()
{
    string userInput = "";
    while(verifyPath(userInput))
    {
        cout << "Enter your project's path" << endl;
        getline(cin, userInput);
    }
    return userInput;
}

int main(int argc, char *argv[])
{
    getSourcePath();

    int language = languageChoice();
    Header headerSettings;

    Parse parser = Parse();
    switch(language)
    {
        case 1: 
            parser = ParseCpp();
            break;
        case 2: 
            parser = ParseJava();
            break;
    }
    Directory projectDir(getSourcePath(), parser.getExtensions());


    return 0;
}