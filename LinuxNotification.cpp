#include "LinuxNotification.h"

LinuxNotifyManager::LinuxNotifyManager(const string& imagePath, const string& appName)
/*
	@det 		Constructor of a Notification (default values available for both arguments)
	@param 		string  Path to an image 
                string  Application's name
	@return 	void
*/
{
    baseCommand_ = "notify-send ";
    imagePath_ = imagePath;
    appName_ = appName;
}

string LinuxNotifyManager::addFileInfos(fs::directory_entry currentEntry) const
/*
	@det 		Adding a commented file's information to the notification's body
	@param 		directory_entry  file that has been commented 
	@return 	void
*/
{
    return QUOTE + "<b>" + Directory::extractName(currentEntry.path()) + "</b>" +
        " has been commented from " + currentEntry.path().c_str() + QUOTE + " ";
}

string LinuxNotifyManager::addImage()
/*
	@det 		Adding a an image to the notification
	@param 		void
	@return 	void
*/
{
    system("pwd > currentDirectory.txt");
    ifstream pathFile("currentDirectory.txt");
    pathFile >> imagePath_;
    imagePath_ += "/warning.png";
	system("rm currentDirectory.txt");
    return "-i " + imagePath_ + " ";
}

string LinuxNotifyManager::addAppName() const
/*
	@det 		Adding the application's name
	@param 		void
	@return 	void
*/
{
    return "-a " + QUOTE + appName_ + QUOTE + " ";
}

bool LinuxNotifyManager::notifyEvent(fs::directory_entry currentEntry)
/*
	@det 		Create the notification and execute it 
	@param 		directory_entry*    file that will be showed 
	@return 	bool                true if executed successfully, else: false
*/
{
    string fullCommand = baseCommand_;
    fullCommand += QUOTE + "New Device on Network" + QUOTE + " ";
    fullCommand += addFileInfos(currentEntry);
    fullCommand += addImage();
    fullCommand += addAppName();

    int systemReturn = system( fullCommand.c_str() );

    if (WIFEXITED(systemReturn))
        return true;
    return false;
}