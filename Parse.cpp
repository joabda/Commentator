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

    cout << "IN FILE " << file << endl;

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
        cout << "------------------FUNCTION OF FILE ------------------------" << endl;
        for(const string& element: functions)
            cout << element << endl;
        cout << "---------------THE END ----------------------------" << endl;
        ofstream commented("test/commented/" + Static::extractName(file) );
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

string Parse::generateFunctionDocumentation() const
{      
    string doc =  "/* Function to \n *\n" ;
    for(const string& param: parameters_)
        doc += " *@param " + param + "\n";
    if(!parameters_.empty())
        doc += " *\n";
    if(return_.substr(0,4) != "void")
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
    