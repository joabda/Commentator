#include "Directory.h"

Directory::Directory(const vector<string>& extensions)
{
    directories_ = {"./"};
    extensions_ = extensions;
    for(int index = 0; index < directories_.size(); ++index)
        findFilesInsideDirectory(directories_[index]);
}

void Directory::findFilesInsideDirectory(const fs::path& currentPath)
{
    for(const auto& currentEntry : fs::directory_iterator(currentPath))
    {
        if(validateExtension(currentEntry.path().extension()))
            files_.insert(make_pair<string, string>(extractName(currentEntry.path().string()), currentEntry.path()));
        if(currentEntry.is_directory())
            directories_.push_back(currentEntry);
    }
}

string Directory::extractName(string path) const
{
    int lastPosition = 0;
    int position = path.find('/');
    while(position != string::npos)
    {
        lastPosition = position;
        path = path.substr(lastPosition + 1);
        position = path.find('/');
    }
    return path;
}

bool Directory::validateExtension(const fs::path& currentEntry) const
{
    for(auto currentExtension : extensions_)
        if(currentEntry == currentExtension)
            return true;
    return false;
}

map<string, string> Directory::getFiles() const
{
    return files_;
}