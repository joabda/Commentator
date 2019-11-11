#pragma once

#include <string>
#include "Parse.h"
using namespace std;

class ParseJava : public Parse
{
public:
    ParseJava(const string& fileName);
    void goToNextFunction();
};