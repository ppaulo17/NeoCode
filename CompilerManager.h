#ifndef COMPILERMANAGER_H
#define COMPILERMANAGER_H
#include <string>
#include <vector>
#include "FileManager.h"

class CompilerManager {
public:
	CompilerManager();
	bool compile(const std::string &sourceFile, const std::string &outputFile, const std::vector<std::string> &flags={});
	bool compileCurrentFile(FileManager& fileManager, const std::vector<std::string> &flags={});
	bool run(const std::string &executableFile);
	std::string getLastOutput() const;
	
private:
	std::string lastOutput;
};

#endif

