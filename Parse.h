#pragma once

#include <string>
#include <vector>
using namespace std;

class Parse 
{
public:
    Parse();
    void setFile(const string& fileName);
    virtual ~Parse();

protected:
    vector<string> exceptions_;
    vector<string> parameters_;
    vector<string> templateParameters_;
    string return_;
    string fileName_;

    virtual void goToNextFunction();
    string getFunctionDocumentation();
    void addParameter(const string& parameter);
    void addException(const string& exception);
    void addTemplateParameter(const string& templateParameter);
    void setReturn(const string& functionReturn);
};