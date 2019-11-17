#include "Parse.h"

Parse::Parse()
{

}

void Parse::generateDocumentation(const string& file, const Header& header)
{
    string signature;
    ifstream sourceFile(file);
    ofstream commented(file + ".txt");
    string line;


    // WORK TO DO HERE

    if(sourceFile.is_open())
    {
        commented << header.getText();
        while(!ws(sourceFile).eof())
        {
            getline(sourceFile, line);
            commented << line << "\n";
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
    