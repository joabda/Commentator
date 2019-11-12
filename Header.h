#pragma once

#include <string>
#include <iostream>

using namespace std;

class Header 
{
public:
    Header();
    string getText() const;

private:
    string company_;
    string license_;
    string owner_;
    string project_;

    void copyrights();
};