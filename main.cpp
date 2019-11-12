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

void testDir()
{
    vector<string> testExtentions = {".h", ".cpp"};
    Directory dir(testExtentions);

    for(auto file: dir.getFiles())
        cout << file.first << " located in : " << file.second << endl;
}

int main(int argc, char *argv[])
{
    testDir();
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

    return 0;
}