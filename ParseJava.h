#pragma once

#include <string>
#include "Parse.h"
using namespace std;

class ParseJava : public Parse
{
public:
    ParseJava();
    void goToNextFunction() override;

    ~ParseJava();
};