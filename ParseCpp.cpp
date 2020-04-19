#include "ParseCpp.h"

vector<string> ParseCpp::getExtensions() const
{
    return {".cpp", ".h", ".hpp"};
}

bool ParseCpp::isSource(const string& fileName) const
{
    if(fileName.find(".cpp") != string::npos)
        return true;
    return false;
}

string ParseCpp::goToNextFunction(istream& currentFile, vector<string>& fileLines)
{
    string line;
    string lineNext;
    getline(currentFile, lineNext);
    fileLines.push_back(lineNext);
    int parenthese, doublePoints, equalSign;
    while(currentFile.good())
    {
        line = lineNext;
        getline(currentFile, lineNext);
        fileLines.push_back(lineNext);
        parenthese = line.find("(");
        doublePoints = line.find("::");
        if(parenthese != int(string::npos) && doublePoints != int(string::npos) && doublePoints < parenthese
                && !isComment(line))
        {
            equalSign = line.find("=");
            if(equalSign != int(string::npos) && equalSign < parenthese)
                continue;
            if(line.find(")") != string::npos)
                return line;
            if(lineNext.find(")") != string::npos)
                return line + lineNext;
        }
    } 
    return "";
}

void ParseCpp::findReturn(const string& function)
{
    reset();
    unsigned end = Static::findLastSpace(function, function.find("::"));
    if(end < function.find("::") && end > 1)
        return_ = function.substr(0, end);
    else
        return_ = "void";
}