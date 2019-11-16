#include "ParseJava.h"

ParseJava::ParseJava()
{

}

void ParseJava::goToNextFunction()
{
    cout << "Java next funct" << endl;
}

vector<string> ParseJava::getExtensions() const
{
    return {".java"};
}