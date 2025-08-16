#include "FileManager.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "EditorManager.h"



FileManager::FileManager() {}


bool FileManager::openFile (const std::string& fileName) {
	std::string fixedFileName = fileName;
	std::ifstream file(fixedFileName);
	if(!file.is_open()){
		return false;
	}
	
	std::stringstream buffer;
	buffer << file.rdbuf();
	FileContent = buffer.str();
	currentFileName = fixedFileName;
	file.close();
	return true;
}

bool FileManager::saveFile (const std::string & fileName) {
	std::string fixedFileName = fileName;
	if (fileName.find(".cpp") == std::string::npos) {
		fixedFileName += ".cpp";
	}
	std::ofstream file(fixedFileName, std::ios::trunc);
	if(!file.is_open()){
		return false;
	}
	file << FileContent;
	file.close();
	return true;
}

bool FileManager::save ( ) {
	if(currentFileName.empty()){
		return false;
	}
	return saveFile(currentFileName);
}

bool FileManager::saveAs(const std::string& newFileName) {
	if (newFileName.empty()) {
		return false;
	}
	currentFileName = newFileName; 
	return saveFile(currentFileName);
}

void FileManager::setContent (const std::string & newContent) {
	FileContent = newContent;
}

std::string FileManager::getContent ( ) {
	return FileContent;
}

#ifdef _WIN32	//uso de la API de windows, busca archivos y los agrega al vector
std::vector<std::string> FileManager::listFilesWindows (const std::string & directory) {
	std::vector<std::string> files;
	
	WIN32_FIND_DATAA findFileData;
	HANDLE hFind = FindFirstFileA((directory + "\\*").c_str(), &findFileData); 
	
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				files.push_back(findFileData.cFileName);
			}
		} while (FindNextFileA(hFind, &findFileData)); 
		FindClose(hFind);
	}
	return files;
}

#else //uso en linux
std::vector<std::string> FileManager::listFilesLinux (const std::string & directory) {
	std::vector<std::string> files;
	DIR* dir = opendir(directory.c_str());
	if(dir){
		struct dirent* entry;
		while((entry = readdir(dir)) != nullptr){
			if(entry->d_type ==DT_REG){
				files.push_back(entry->d_name);
			}
		}
		closedir(dir);
	}
	return files;
}
#endif

std::vector<std::string> FileManager::listFiles (const std::string & directory) {
#ifdef _WIN32
	return listFilesWindows(directory);
#else
	return listFilesLinux(directory);
#endif
}

std::string FileManager::getCurrentFile ( ) const {
	return currentFileName;
}

void FileManager::setCurrentFile (const std::string fileName) {
	currentFileName = fileName;
}


void FileManager::loadIntoEditor (EditorManager &editor) {
	editor.setText(FileContent);
}

void FileManager::saveFromEditor (const EditorManager &editor) {
	FileContent = editor.getText();
	saveFile(currentFileName);
}

