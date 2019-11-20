#include "ParseJava.h"

ParseJava::ParseJava()
{

}

vector<string> ParseJava::getExtensions() const
{
    return {".java"};
}


string ParseJava::goToNextFunction(istream& currentFile, vector<string>& fileLines)
{
    return "";
}

void ParseJava::documentFunction(const string& function)
{
        
}