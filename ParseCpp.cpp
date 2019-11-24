#include "ParseCpp.h"

ParseCpp::ParseCpp()
{

}   

vector<string> ParseCpp::getExtensions() const
{
    return {".cpp", ".h", ".hpp"};
}

string ParseCpp::goToNextFunction(istream& currentFile, vector<string>& fileLines)
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
        if(line.find("::") != string::npos && line.find("(") != string::npos
                && (line.find(")") != string::npos || lineNext.find(")") != string::npos) 
                && line.find("=") == string::npos)
            return line;
    } 
    return "";
}

int findLastSpace(const string& line, const unsigned& comma)
{
    unsigned position = 0, temp = 0;
    while(temp != string::npos)
    {
        temp = line.find(" ", position + 1);
        if(temp < comma && temp >= 0)
            position = temp;
        else
            break;
    }
    return position + 1;
}

void ParseCpp::documentFunction(const string& function)
{
    cout << function << endl;
    reset();
        // RETURN
    int end = findLastSpace(function, function.find("::"));
    if(end < function.find("::") && end > 1)
        return_ = function.substr(0, end);
    else
        return_ = "void";

        // PARAMETERS
    int start = function.find("(");
    end = function.find(")");
    if(start != string::npos && end != string::npos)
    {
        string line = function.substr(start + 1, end - start - 1);
        end = line.find(","); 
        while( true )
        {
            end = line.find(","); 
            if(end != string::npos)
            {
                start = findLastSpace(line, end);
                parameters_.push_back(line.substr(start , end - start));
                line = line.substr(end + 1);
            }
            else
            {
                end = line.length();
                if(end == 0)
                    break;
                start = findLastSpace(line, end);
                parameters_.push_back(line.substr(start , end - start));
                break;            
            }  
        }
    }
}