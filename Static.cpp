#include "Static.h"

string Static::extractName(string path) 
{
    int lastPosition = 0;
    unsigned position = path.find('/');
    while(position != string::npos && position < path.length())
    {
        lastPosition = position;
        path = path.substr(lastPosition + 1);
        position = path.find('/');
    }
    return path;
}


int Static::isDigit(const string& input)
{
    string::const_iterator iterator = input.begin();
    for (; iterator != input.end() && isdigit(*iterator); ++iterator);
    if(!input.empty() && iterator == input.end())
        return stoi(input);
    return 0;
}