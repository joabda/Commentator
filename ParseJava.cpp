#include "ParseJava.h" 

vector<string> ParseJava::getExtensions() const
{
    return {".java"};
}

bool ParseJava::isSource(const string& fileName) const
{
    if(fileName.find(".java"))
        return true;
    return false;
}


string ParseJava::goToNextFunction(istream& currentFile, vector<string>& fileLines)
{
    string line;
    string lineNext;
    getline(currentFile, lineNext);
    fileLines.push_back(lineNext);
    while(currentFile.good())
    {
        line = lineNext;
        getline(currentFile, lineNext);
        fileLines.push_back(lineNext);
        if(line.find("(") != string::npos && containsAccessibility(line)
                && !isComment(line))
        {
            if(line.find(")") != string::npos)
                return line;
            if(lineNext.find(")") != string::npos)
                return line + lineNext;
        }
    }
    return "";
}

bool ParseJava::containsAccessibility(const string& line)
{
    if(line.find("public") != string::npos
            || line.find("private") != string::npos
            || line.find("protected") != string::npos)
        return true;
    return false;
}

void ParseJava::findReturn(const string& function)
{
    reset();
}