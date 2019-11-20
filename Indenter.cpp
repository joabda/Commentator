#include "Indenter.h"

void Indenter::writeInFile(ostream& commented, vector<string>& indents, const vector<string>& hold, 
		vector<int>& bracketCount)
{
	int length;
	for(unsigned currentLineNumber = 0, count = 0; currentLineNumber < hold.size(); currentLineNumber++)
	{
		while((hold[currentLineNumber])[count] == '\t')
			count++;
		while(bracketCount[currentLineNumber] > 0)
		{
			bracketCount[currentLineNumber]--;
			indents[currentLineNumber] +="\t";
		}

		if(count == 0)
			commented << indents[currentLineNumber] << hold[currentLineNumber] << endl;
		else 
            if(count > 0)
            {
                commented << indents[currentLineNumber];
                length = hold[currentLineNumber].length();
                for(unsigned charPosition = 0; charPosition < (length - count); charPosition++)
                    commented << hold[currentLineNumber][charPosition + count];
                commented << endl;
            }
	}
}

vector<string> Indenter::readFile(istream& sourceFile)
{
	vector<string> lineContainer;
	int count = 0;
	string line;
	while(sourceFile.good())
	{
		getline(sourceFile, line);
		lineContainer.push_back(line);
		count++;
	}
	return lineContainer;
}

template<typename T>
vector<T> Indenter::initializeEmpty(const int& numberOfElementsNeeded, const T& initValue)
{
	vector<T> bracketCount;
	for(int i = 0; i < numberOfElementsNeeded; i++)
		bracketCount.push_back(initValue);
	return bracketCount;
}

void Indenter::source(const string& fileName)	
{
	ifstream sourceFile(fileName);
	vector<string> hold = readFile(sourceFile);
	int endline = hold.size();
	vector<int> bracketCount = initializeEmpty(endline, 0);

	int current, length;
	for(int count = 0; count < endline; count++)
	{
		length = hold[count].length();
		for(int charPosition = 0; charPosition <= length; charPosition++)
		{
			if(hold[count][charPosition] == '{')
            {
                current = count;
                while(current < endline)
                    bracketCount[++current]++;
            }
			if(hold[count][charPosition] == '}')
			{
				current = count;
				while(current < endline)
					bracketCount[current++]--;
			}
		}
	}
    vector<string> indents = initializeEmpty(endline, string(""));
	ofstream toComment(fileName);
	if(toComment.is_open())
		writeInFile(toComment, indents, hold, bracketCount);
	else
		cout << "Error, couldn't open " << fileName << " for indentation" << endl;
}

void Indenter::source(ostream& commented, const vector<string>& hold)
{
	int endline = hold.size();
	vector<int> bracketCount = initializeEmpty(endline, 0);
	int current = 0, length = 0;
	for(int count = 0; count < endline; count++)
	{
		length = hold[count].length();
		for(int charPosition = 0; charPosition <= length; charPosition++)
		{
			if(hold[count][charPosition] == '{')
            {
                current = count;
                while(current < endline)
                    bracketCount[++current]++;
            }
			if(hold[count][charPosition] == '}')
			{
				current = count;
				while(current < endline)
					bracketCount[current++]--;
			}
		}
	}
    vector<string> indents = initializeEmpty(endline, string(""));
	writeInFile(commented, indents, hold, bracketCount);
}

void Indenter::header(const string& fileName)
{
	ifstream sourceFile(fileName);
	vector<string> hold = readFile(sourceFile);
	int endline = hold.size();
	vector<int> bracketCount = initializeEmpty(endline, 0);

	int current, length;
	bool shouldIndent, previousClosed = true;
	for(int count = 0; count < endline; count++)
	{
		length = hold[count].length();
		for(int charPosition = 0; charPosition <= length; charPosition++)
		{
			shouldIndent = hold[count][charPosition] == ':';
			if(previousClosed)
			{
				if(hold[count][charPosition] == '{' || shouldIndent)
				{
					current = count;
					if(shouldIndent)
						previousClosed = false;
					while(current < endline)
						bracketCount[++current]++;
				}
				else
					if(hold[count][charPosition] == '}')
						bracketCount[count] = 0;
				
			}
			else
				if(shouldIndent)
				{
					current = count;
					while(current < endline)
						bracketCount[current++]--;
					if(shouldIndent)
					{
						current = count;
						previousClosed = true;
						while(current < endline)
							bracketCount[++current]++;
					}
				}
		}
	}
    vector<string> indents = initializeEmpty(endline, string(""));
	ofstream toComment(fileName);
	if(toComment.is_open())
		writeInFile(toComment, indents, hold, bracketCount);
	else
		cout << "Error, couldn't open " << fileName << " for indentation" << endl;
}

void Indenter::header(ostream& commented, const vector<string>& hold)
{
	int endline = hold.size();
	vector<int> bracketCount = initializeEmpty(endline, 0);

	int current, length;
	bool shouldIndent, previousClosed = true;
	for(int count = 0; count < endline; count++)
	{
		length = hold[count].length();
		for(int charPosition = 0; charPosition <= length; charPosition++)
		{
			shouldIndent = hold[count][charPosition] == ':';
			if(previousClosed)
			{
				if(hold[count][charPosition] == '{' || shouldIndent)
				{
					current = count;
					if(shouldIndent)
						previousClosed = false;
					while(current < endline)
						bracketCount[++current]++;
				}
				else
					if(hold[count][charPosition] == '}')
						bracketCount[count] = 0;
				
			}
			else
				if(shouldIndent)
				{
					current = count;
					while(current < endline)
						bracketCount[current++]--;
					if(shouldIndent)
					{
						current = count;
						previousClosed = true;
						while(current < endline)
							bracketCount[++current]++;
					}
				}
		}
	}
    vector<string> indents = initializeEmpty(endline, string(""));
	writeInFile(commented, indents, hold, bracketCount);
}