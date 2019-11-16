#pragma once

#include <fstream>
#include <filesystem>
#include "Directory.h"

using namespace std;
namespace fs = std::filesystem;

static string QUOTE = "\"";

class LinuxNotifyManager
{
public:
    LinuxNotifyManager(const string& imagePath = "NULL", const string& appName = "NetworkTool");
    bool notifyEvent(fs::directory_entry currentEntry);
    ~LinuxNotifyManager() {}

private:
    string baseCommand_;
    string imagePath_;
    string appName_;
    string addImage();
    string addAppName() const;
    string addFileInfos(fs::directory_entry currentEntry) const;
};