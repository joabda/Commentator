#include "Menu.h"

int Menu::getLanguage()
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