#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#endif
#include <string>
#include <vector>
#include "EditorManager.h"


class FileManager {
public:
	FileManager();
	bool openFile(const std::string& fileName);
	bool saveFile(const std::string& fileName);
	bool save();
	bool saveAs(const std::string& newFileName);
	void setContent(const std::string &newContent);
	std::string getContent();
	std::vector<std::string> listFilesWindows(const std::string &directory);
	std::vector<std::string> listFilesLinux(const std::string &directory);
	std::vector<std::string> listFiles(const std::string &directory);
	std::string getCurrentFile() const;
	void setCurrentFile(const std::string fileName);
	void loadIntoEditor(EditorManager &editor);
	void saveFromEditor(const EditorManager &editor);
	
	
	
private:
	std::string FileName;
	std::string currentFileName;
	std::string FileContent;
	
};

#endif

