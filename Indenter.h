#include <string>
#include <fstream>
#include <memory>
#include <vector>

using namespace std;

class Indenter
{
    public:
        static void source(const string& fileName);
        static void header(const string& fileName);

    private:
        static void writeInFile(const string& fileName, vector<string>& indents, 
            const vector<string>& hold, vector<int>& bracketCount);
        static vector<string> readFile(istream& sourceFile);

        template<typename T>
        static vector<T> initializeEmpty(const int& numberOfElementsNeeded, const T& initValue);
};
