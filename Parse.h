#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Header.h"
#include "Static.h"
using namespace std;

class Parse 
{
public:
    Parse();
    void generateDocumentation(const string& file, const Header& header);
    string generateFunctionDocumentation();
    virtual vector<string> getExtensions() const { return {}; }
    virtual ~Parse() {}

protected:
    vector<string> exceptions_;
    vector<string> parameters_;
    vector<string> templateParameters_;
    string return_;
    string functionName_;
    string fileName_;
    string type_;

    virtual string goToNextFunction(istream& currentFile, vector<string>& fileLines) { return ""; }
    bool contains(const vector<string>& functions, const string& aFunction);
    void reset();
    virtual void findReturn(const string& function) {}
    virtual void findName(const string& function) {}
    virtual bool isSource(const string& fileName) const { return false; }
    bool isComment(const string& line);
    void isGetterOrSetter(string& doc) const;
    virtual string findNameMeaning() {}

private:
    void documentFunction(const string& function);
};