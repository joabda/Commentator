#pragma once

#include <string>
#include <vector>
using namespace std;

class Parse 
{
public:
    Parse(const string& fileName);

protected:
    vector<string> exceptions_;
    vector<string> parameters_;
    vector<string> templateParameters_;
    string return_;

    virtual void goToNextFunction() = 0;
    string getFunctionDocumentation();
    void addParameter(const string& parameter);
    void addException(const string& exception);
    void addTemplateParameter(const string& templateParameter);
    void setReturn(const string& functionReturn);
};