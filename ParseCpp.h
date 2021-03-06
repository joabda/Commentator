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
    void findReturn(const string& function) override;
    void findName(const string& function) override;
    bool isSource(const string& fileName) const override;
    string findNameMeaning() override;
};