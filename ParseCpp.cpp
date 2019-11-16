#include "ParseCpp.h"

ParseCpp::ParseCpp()
{

}

void ParseCpp::goToNextFunction()
{
    cout << "CPP next funct" << endl;
}

vector<string> ParseCpp::getExtensions() const
{
    return {".cpp", ".h", ".hpp"};
}