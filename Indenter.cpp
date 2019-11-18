#include <string>
#include <fstream>
#include <memory>
#include <vector>

using namespace std;

void writeInFile(const string& fileName, vector<string>& indents, const vector<string>& hold, 
		vector<int>& bracketCount)
{
	ofstream commented(fileName);
	int length;
	for(int currentLineNumber = 0, count = 0; currentLineNumber < hold.size(); currentLineNumber++)
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
                for(int charPosition = 0; charPosition < (length - count); charPosition++)
                    commented << hold[currentLineNumber][charPosition + count];
                commented << endl;
            }
	}
}

vector<string> readFile(istream& sourceFile)
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
vector<T> initializeEmpty(const int& numberOfElementsNeeded, const T& initValue)
{
	vector<T> bracketCount;
	for(int i = 0; i < numberOfElementsNeeded; i++)
		bracketCount.push_back(initValue);
	return bracketCount;
}

void source(const string& fileName)	
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
	writeInFile("temp.txt", indents, hold, bracketCount);
}

void header(const string& fileName)
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
	writeInFile("temp222.txt", indents, hold, bracketCount);
}


int main()
{
    header("hello1.txt");
}