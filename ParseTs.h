#pragma once

#include <string>
#include "Parse.h"
using namespace std;

class ParseTypescript : public Parse
{
public:
    ParseTypescript() {}
    vector<string> getExtensions() const override;
    ~ParseTypescript() {}

protected:
    string goToNextFunction(istream& currentFile, vector<string>& fileLines) override;
    void findReturn(const string& function) override;
    void findName(const string& function) override;
    bool isSource(const string& fileName) const override;
    string findNameMeaning() override;

private:
    static bool containsAccessibility(const string& line);
};