#pragma once

#include <iostream>
#include <string>
#include <filesystem>
#include <map>

using namespace std;
namespace fs = std::filesystem;

class Directory
{
public: 
    Directory(const string& source, const vector<string>& extensions);
    map<string, string> getFiles() const;
    static bool validatePath(const string& paths);
    static string extractName(string path);

private:
    string source_;
    vector<string> extensions_;
    map<string, string> files_;
    vector<fs::path> directories_;

    bool validateExtension(const fs::path& currentEntry) const;
    void findFilesInsideDirectory(const fs::path& currentPath);
    
};