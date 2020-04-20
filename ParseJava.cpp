#include "ParseJava.h"

static const string access[] = {"public", "protected", "private"};

vector<string> ParseJava::getExtensions() const
{
    return {".java"};
}

bool ParseJava::isSource(const string &fileName) const
{
    if (fileName.find(".java"))
        return true;
    return false;
}

string ParseJava::goToNextFunction(istream &currentFile, vector<string> &fileLines)
{
    string line;
    string lineNext;
    getline(currentFile, lineNext);
    fileLines.push_back(lineNext);
    while (currentFile.good())
    {
        line = lineNext;
        getline(currentFile, lineNext);
        fileLines.push_back(lineNext);
        if (line.find("(") != string::npos && containsAccessibility(line) && !isComment(line))
        {
            if (line.find(")") != string::npos)
                return line;
            if (lineNext.find(")") != string::npos)
                return line + lineNext;
        }
    }
    return "";
}

bool ParseJava::containsAccessibility(const string &line)
{
    if (line.find(access[0]) != string::npos || line.find(access[1]) != string::npos || line.find(access[2]) != string::npos)
        return true;
    return false;
}

string ParseJava::findNameMeaning()
{
    string doc = "/*\n *";
    const unsigned initialLength = doc.length();
    unsigned returnTypeIndex = functionName_.find(return_);
    int index = functionName_.find("get");
    isGetterOrSetter(doc);
    unsigned start = functionName_.find("(");
    unsigned end = functionName_.find(")");
    if (doc.length() == initialLength && return_ != "Constructor")
    {
        // functionName_ = functionName_.substr();
        doc += "Function to " + Static::parseLowerCamelCaseWord(functionName_);
    }
    doc += " \n *\n";
    return doc;
}

void ParseJava::findReturn(const string &function)
{
    int index = Static::findLastSpace(function, function.find("("));
    if (index != int(string::npos))
        for (const auto &element : access)
        {
            unsigned position = function.find(element);
            if (position != string::npos)
            {
                int start = position + element.length() + 1;
                string returnType = function.substr(start, index - start);
                if (returnType.length() == 0)
                    returnType = "Constructor";
                return_ = returnType;
                cout << return_ << endl;
                break;
            }
        }
}

void ParseJava::findName(const string& function)
{
    unsigned index = function.find(return_);
    if(index != string::npos)
    {
        index += return_.length();
        unsigned end = function.find("(");
        functionName_ = function.substr(index, end - index);
    }
}