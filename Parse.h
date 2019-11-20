#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Header.h"
#include "Indenter.h"
using namespace std;

class Parse 
{
public:
    Parse();
    void generateDocumentation(const string& file, const Header& header);
    string generateFunctionDocumentation() const;
    virtual vector<string> getExtensions() const { return {}; }
    virtual ~Parse() {}

protected:
    vector<string> exceptions_;
    vector<string> parameters_;
    vector<string> templateParameters_;
    string return_;
    string fileName_;
    string type_;

    virtual string goToNextFunction(istream& currentFile, vector<string>& fileLines) {}
    bool contains(const vector<string>& functions, const string& aFunction);
    virtual void documentFunction(const string& function) {}
    void reset();
};