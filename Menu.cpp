#include "Menu.h"

int Menu::getLanguage()
{
    int choice = 0;
    string input;
    while(choice < 1 || choice > 3)
    {
        cout << "Pleaser enter what language you are using: " << endl;
        cout << "1- C++" << endl;
        cout << "2- Java" << endl;
        cout << "3- Typescript" << endl;
        getline(cin, input);
        choice = Static::isDigit(input);
    }
    return choice;
}

bool Menu::verifyPath(string userInput)
{
    bool exists = false;
    if(userInput[0] != '\'')
        exists = Directory::validatePath(userInput);
    else
        exists = !system(string("cd " + userInput).c_str());
    return exists;
}

string Menu::getSourcePath()
{
    string userInput = "";
    while(!verifyPath(userInput))
    {
        cout << "Enter your project's path" << endl;
        getline(cin, userInput);
    }
    return userInput;
}