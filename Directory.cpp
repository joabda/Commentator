#include "Directory.h"


void print(const map<string, string>& files_)
{
    cout << "All files are " << endl;
    for(auto element: files_)
        cout << "Name " << element.first <<  " path " << element.second << endl;   
}

Directory::Directory(const string& source, const vector<string>& extensions)
{
    source_ = source;
    directories_ = {source_};
    extensions_ = extensions;
    for(auto&& element: directories_) // Old unsigned index = 0; index < directories_.size(); ++index
        findFilesInsideDirectory(element);
    print(files_);
}

void Directory::findFilesInsideDirectory(const fs::path& currentPath)
{
    for(const auto& currentEntry : fs::directory_iterator(currentPath))
    {
        if(validateExtension(currentEntry.path().extension()))
            files_.insert(make_pair<string, string>(Static::extractName(currentEntry.path().string()), currentEntry.path()));
        if(currentEntry.is_directory())
            directories_.push_back(currentEntry);
    }
}

bool Directory::validateExtension(const fs::path& currentEntry) const
{
    for(const auto& currentExtension : extensions_)
        if(currentEntry == currentExtension)
            return true;
    return false;
}

map<string, string> Directory::getFiles() const
{
    return files_;
}

bool Directory::validatePath(const string& path)
{
    fs::directory_entry toValidate(path);
    return toValidate.exists();
}