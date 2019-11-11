#pragma once

#include <string>
#include "Parse.h"
using namespace std;

class ParseCpp : public Parse
{
public:
    ParseCpp(const string& fileName);
    void goToNextFunction();
};