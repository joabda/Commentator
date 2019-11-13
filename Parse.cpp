#include "Parse.h"

Parse::Parse()
{

}

void Parse::generateDocumentation(const string& file, const Header& header)
{
    string signature;
    fstream sourceFile(file, ios::in | ios::out);
    if(sourceFile.is_open())
    {
        sourceFile.seekp(0, ios::beg);
        sourceFile << header.getText();
        while(!ws(sourceFile).eof())
        {
            goToNextFunction();
            getline(sourceFile, signature);
        }
    }
    else 
        cout << "File " << file << " is not open" << endl;
}

void Parse::addParameter(const string& parameter)
{
    
}

void Parse::addException(const string& exception)
{

}

void Parse::addTemplateParameter(const string& templateParameter)
{

}

void Parse::setReturn(const string& functionReturn)
{

}
    