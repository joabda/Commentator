#include <iostream>
#include <string>
#include <vector>

#include "Header.h"
#include "Parse.h"
#include "ParseCpp.h"
#include "ParseJava.h"   
#include "Directory.h"
#include "Menu.h"
#include "Indenter.h"
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

    if(system("cd commented"))
        system("mkdir commented");
    Directory projectDir(Menu::getSourcePath(), parser->getExtensions());


    for(pair<string, string> element: projectDir.getFiles())
    {
        cout << "Commenting: " << element.first << endl;
        parser->generateDocumentation(element.second, headerSettings);
    }
    return 0;
}