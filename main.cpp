#include <iostream>
#include <string>
#include <vector>

#include "Header.h"
#include "Parse.h"
#include "ParseCpp.h"
#include "ParseJava.h"   
#include "Directory.h"
#include "Menu.h"
using namespace std;

int main(int argc, char *argv[])
{
    int language = Menu::getLanguage();
    Header headerSettings;

    unique_ptr<Parse> parser(new Parse());
    switch(language)
    {
        case 1: 
            parser.reset(new ParseCpp());
            break;
        case 2: 
            parser.reset(new ParseJava());
            break;
    }

    Directory projectDir(Menu::getSourcePath(), parser->getExtensions());

    // TEST
    cout << "Current Directory contains: " << endl;
    for(pair<string, string> element: projectDir.getFiles())
        cout << "   " << element.first << endl;
    //


    for(pair<string, string> element: projectDir.getFiles())
    {
        cout << "Commenting: " << element.first << endl;
        parser->generateDocumentation(element.second, headerSettings);
    }
    return 0;
}