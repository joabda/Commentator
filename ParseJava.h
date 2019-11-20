#pragma once

#include <string>
#include "Parse.h"
using namespace std;

class ParseJava : public Parse
{
public:
    ParseJava();
    vector<string> getExtensions() const override;
    ~ParseJava() {}

protected:
    string goToNextFunction(istream& currentFile, vector<string>& fileLines) override;
    void documentFunction(const string& function) override;
};