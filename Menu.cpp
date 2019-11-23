#include "Menu.h"

int Menu::getLanguage()
{
    int choice = 0;
    string input;
    while(choice < 1 || choice > 2)
    {
        cout << "Pleaser enter what language you are using: " << endl;
        cout << "1- C++" << endl;
        getline(cin, input);
        choice = isDigit(input);
    }
    return choice;
}

int Menu::isDigit(const string& input)
{
    string::const_iterator iterator = input.begin();
    for (; iterator != input.end() && isdigit(*iterator); ++iterator);
    if(!input.empty() && iterator == input.end())
        return stoi(input);
    return 0;
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
    cin.clear();
    cin.ignore(INT32_MAX, '\n');
    while(!verifyPath(userInput))
    {
        cout << "Enter your project's path" << endl;
        getline(cin, userInput);
    }
    return userInput;
}