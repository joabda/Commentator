#include "Parse.h"

Parse::Parse()
{

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
        for(string element: functions)
            cout << element << endl;

        ofstream commented("commented/" + file);
        commented << header.getText();
        for(const string& element: lines)
        {
            if(contains(functions, element))
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

string Parse::generateFunctionDocumentation() const
{      
    string doc =  "/* Function to \n *\n" ;
    for(const string& param: parameters_)
        doc += " *@param " + param + "\n";
    if(!parameters_.empty())
        doc += " *\n";
    if(return_ != "void")
        doc += " *@returns a " + return_ + "\n";
    doc += " */\n";
    return doc;
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
    