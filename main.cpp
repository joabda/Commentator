#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>

#include "Header.h"
#include "Parse.h"
#include "ParseCpp.h"
#include "ParseJava.h"   
#include "Directory.h"
#include "Menu.h"
#include "Indenter.h"
#include "ThreadManager.h"
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
    if(system("cd test/commented"))
    {
        system("mkdir test/commented");
        system("cd test/commented");
    }
    Directory projectDir(Menu::getSourcePath(), parser->getExtensions());

    for(auto& element: projectDir.getFiles())
        parser->generateDocumentation(element.second, headerSettings);
    // ThreadManager threads(parser.get(), projectDir.getFiles(), headerSettings);
    return 0;
}