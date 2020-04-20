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
    unsigned parenthese, doublePoints, equalSign;
    while(currentFile.good())
    {
        line = lineNext;
        getline(currentFile, lineNext);
        fileLines.push_back(lineNext);
        parenthese = line.find("(");
        doublePoints = line.find("::");
        if(parenthese != string::npos && doublePoints != string::npos && doublePoints < parenthese
                && !isComment(line))
        {
            equalSign = line.find("=");
            if(equalSign != string::npos && equalSign < parenthese)
                continue;
            findReturn(line);
            if(return_ == "Error")
                continue;
            if(line.find(")") != string::npos)
                return line;
            if(lineNext.find(")") != string::npos)
                return line + lineNext;
        }
    } 
    return "";
}

string ParseCpp::findNameMeaning() 
{
    string doc = "/*\n *";
    const unsigned initialLength = doc.length();
    isGetterOrSetter(doc);
    if(doc.length() == initialLength)
        doc += "Function to " + Static::parseLowerCamelCaseWord(functionName_);
    doc += " \n *\n";
    return doc;
}

void ParseCpp::findReturn(const string& function)
{
    unsigned doublePoints = function.find("::");
    unsigned end = Static::findLastSpace(function, doublePoints);
    if(end < doublePoints && end > 1)
    {
        const string toReturn = function.substr(0, end);
        if(Static::countSpaces(toReturn) < 2)
            return_ = toReturn;
        else 
            return_ = "Error";
    }
    else
    {
        const unsigned parenthese = function.find("(");
        if(function.substr(0, doublePoints) == function.substr(doublePoints + 2, parenthese - (doublePoints + 2)))
            return_ = "void";
        else
            return_ = "Error";
    }
}

void ParseCpp::findName(const string& function)
{
    int end = function.find("(");
    int start;
    if(end != int(string::npos))
    {
        start = function.find("::");
        functionName_ = function.substr(start + 2, end - start - 2); //  2 length of "::"
    }
}