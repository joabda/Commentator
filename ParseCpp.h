#pragma once

#include <string>
#include <vector>
#include "Parse.h"
using namespace std;

class ParseCpp : public Parse
{
public:
    ParseCpp() {}
    vector<string> getExtensions() const override;
    ~ParseCpp() {}

protected:
    string goToNextFunction(istream& currentFile, vector<string>& fileLines) override;
    void documentFunction(const string& function) override;
    bool isSource(const string& fileName) const override;
};