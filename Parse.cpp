#include "Parse.h"

Parse::Parse()
{
    return_ = "void";
}

bool Parse::contains(const vector<string>& functions, const string& aFunction)
{
    for(string element: functions)
        if(element == aFunction)
            return true;
    return false;
}

void Parse::generateDocumentation(const string& file, const Header& header)
{
    string signature;
    ifstream sourceFile(file);
    string line = "";
    vector<string> lines;
    vector<string> functions;

    if(sourceFile.is_open())
    {
        while(sourceFile.good())
        {
            getline(sourceFile, line);
            lines.push_back(line);
            string functionLine = goToNextFunction(sourceFile, lines);
            if(functionLine != "")
                functions.push_back(functionLine);
        }
        ofstream commented("commented/" + Static::extractName(file) );
        commented << header.getText();
        for(const string& element: lines)
        {
            if(isSource(file) && contains(functions, element))
            {
                documentFunction(element);
                commented << generateFunctionDocumentation();
            }
            commented << element << endl;
        }
    }
    else 
        cout << "File " << file << " is not open" << endl;
}

void Parse::isGetterOrSetter(string& doc) const
{
    int index = functionName_.find("get");
    if(index != int(string::npos))
    {
        string attribute = functionName_.substr(index + 3);
        attribute[0] = tolower(attribute[0]);
        doc += "Getter function for " + attribute; // 3 length of "get"
    }
    else 
    {
        index = functionName_.find("set");
        if(index != int(string::npos))
        {
            string attribute = functionName_.substr(index + 3);
            attribute[0] = tolower(attribute[0]);
            doc += "Setter function for " + attribute; // 3 length of "set"
        }
    }
}

string Parse::generateFunctionDocumentation()
{      
    cout << functionName_ << endl;
    string doc = findNameMeaning();
    if(return_ == "Constructor")
    {
        doc = "/*\n *";
        return_ = "void";
        if(parameters_.size() > 0)
            doc += "Constructor with parameters";
        else
            doc += "Default Constructor";
        doc += " \n *\n";
    }

    for(const string& param: parameters_)
        doc += " *@param " + param + "\n";
    if(!parameters_.empty())
        doc += " *\n";
    if(return_.substr(0,4) != "void")
    {
        doc += " *@returns a";
        if(Static::isVowel(return_[0]))
            doc += "n";
        doc += " " + return_ + "\n";
    }
    doc += " */\n";
    return doc;
}

void Parse::documentFunction(const string& function)
{
    // Return type
    reset();
    findReturn(function);

    // Name
    findName(function);

    // Parameters
    int start = function.find("(");
    int end = function.find(")");
    if(start != int(string::npos) && end != int(string::npos))
    {
        string line = function.substr(start + 1, end - start - 1);
        end = line.find(","); 
        while( true )
        {
            end = line.find(","); 
            if(end != int(string::npos))
            {
                start = Static::findLastSpace(line, end);
                parameters_.push_back(line.substr(start , end - start));
                line = line.substr(end + 1);
            }
            else
            {
                end = line.length();
                if(end == 0)
                    break;
                start = Static::findLastSpace(line, end - 2);
                parameters_.push_back(line.substr(start , end - start));
                break;            
            }  
        }
    }
}

void Parse::reset()
{
    parameters_.clear();
    exceptions_.clear();
    templateParameters_.clear();
    return_ = "";
    fileName_ = "";
    type_ = "";
}

bool Parse::isComment(const string& line)
{
    int parentheses = line.find("(");
    int comment = line.find("//");
    if(parentheses != int(string::npos) && comment != int(string::npos) && comment < parentheses)
        return true;
    return false;
}
    