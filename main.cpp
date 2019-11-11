#include <iostream>
#include "Header.h"

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


int main(int argc, char *argv[])
{
    int language = languageChoice();
    Header headerSettings;

    Parse parser;
    switch(language)
    {
        case 1: 
            parser = ParseCpp;
            break;
        case 2: 
            parser = ParseJava;
            break;
    }

    return 0;
}