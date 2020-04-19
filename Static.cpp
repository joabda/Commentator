#include "Static.h"

string Static::extractName(string path) 
{
    int lastPosition = 0;
    unsigned position = path.find('/');
    while(position != string::npos && position < path.length())
    {
        lastPosition = position;
        path = path.substr(lastPosition + 1);
        position = path.find('/');
    }
    return path;
}


int Static::isDigit(const string& input)
{
    string::const_iterator iterator = input.begin();
    for (; iterator != input.end() && isdigit(*iterator); ++iterator);
    if(!input.empty() && iterator == input.end())
        return stoi(input);
    return 0;
}


int Static::findLastSpace(const string& line, unsigned comma)
{
    unsigned position = 0, temp = 0;
    while(temp != string::npos)
    {
        temp = line.find(" ", position + 1);
        if(temp < comma && temp >= 0)
            position = temp;
        else
            break;
    }
    return position + 1;
}

unsigned Static::getNextUpperCaseIndex(const string& line)
{
	for(unsigned i = 0; i < line.length(); ++i)
		if(isupper(line[i]))
			return i;
	return string::npos;	
}

void Static::toLower(string& mixed)
{
    transform(
        mixed.begin(), mixed.end(), mixed.begin(),
        []( unsigned char c ) { 
            return tolower(c); 
        }
    );
}

bool isDelimiter(char c)
{
    auto const isAllowedInName = isalnum(c) || c == ':';
    return !isAllowedInName;
}

string Static::parseLowerCamelCaseWord(const string& line)
{
    auto beginWord = find_if_not(begin(line), end(line), isDelimiter);
    auto words = vector<string>{};
    while (beginWord != end(line))
    {
        auto endWord = find_if(next(beginWord), end(line), [](char c){ return isDelimiter(c) || isupper(c); });
        words.emplace_back(beginWord, endWord);
        beginWord = find_if_not(endWord, end(line), isDelimiter);
    }
    string toReturn = "";
    for(auto& word: words)
    {
        word[0] = tolower(word[0]);
        toReturn += word + " ";
    }
    return toReturn;
}