#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "FileManager.h"
#include "CompilerManager.h"
#include "EditorManager.h"
#include <unordered_map>


class MainController {
public:
	MainController();
	bool openFile(const std::string &fileName);
	bool saveFile(const std::string &fileName);
	bool saveFileAs(const std::string &fileName);
	bool saveCurrentFile();
	bool compileCurrentFile();
	bool runExecutable();
	void editContent(const std::string& newContent);
	std::string getContent();
	bool switchFile(const std::string& fileName);
	bool closeFile(const std::string& fileName);
	void createNewFile(const std::string &fileName);
	void setFileContent(const std::string &content);
	
	
	
	
private:
	FileManager fileManager;
	CompilerManager compilerManager;
	EditorManager editorManager;
	
	std::unordered_map<std::string, std::string> openFiles;
	std::string currentFile;
	
};

#endif

