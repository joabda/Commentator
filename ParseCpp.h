#pragma once

#include <string>
#include <vector>
#include "Parse.h"
using namespace std;

class ParseCpp : public Parse
{
public:
    ParseCpp();
    void goToNextFunction() override;
    vector<string> getExtensions() const;

    ~ParseCpp();
};