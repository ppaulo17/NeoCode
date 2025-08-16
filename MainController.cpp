#include "MainController.h"
#include <iostream>

MainController::MainController() {}


bool MainController::openFile (const std::string & fileName) {
	if(fileManager.openFile(fileName)){
		fileManager.loadIntoEditor(editorManager);
		openFiles[fileName] = fileManager.getContent();
		currentFile = fileName;
		return true;
	}
	return false;
}

bool MainController::saveFile (const std::string & fileName) {
	if(fileName.empty()){
		std::cerr << "Nombre de archivo vacio, no se puede guardar" << std::endl;
		return false;
	}
	
	fileManager.saveFromEditor(editorManager);
	
	if(fileManager.saveFile(fileName)){
		openFiles[fileName] = fileManager.getContent();
		fileManager.setCurrentFile(fileName);
		std::cout << "Archivo guardado exitosamente" <<std::endl;
		return true;
	}
	std::cerr << "Error al guardar el archivo " << std::endl;
	return false;
}

bool MainController::saveCurrentFile ( ) {
	std::string fileName = fileManager.getCurrentFile();
	if (fileName.empty()) {
		std::cerr << "No hay archivo para guardar" << std::endl;
		return false;
	}
//	fileManager.saveFromEditor(editorManager);
	return fileManager.saveFile(fileName);
}

bool MainController::compileCurrentFile ( ) {
	
	fileManager.saveFile(currentFile);
	if(currentFile.empty()){
		std::cerr << "No hay archivo abierto para guardar" << std::endl;
		return false;
	}


	std::string outputBinary = currentFile;
	size_t dotPos = currentFile.find_last_of('.');
	
	if (dotPos != std::string::npos && currentFile.substr(dotPos) == ".cpp") {
		outputBinary = currentFile.substr(0, dotPos); 
	}
	outputBinary += ".exe";
	
	std::string errors;
	if (compilerManager.compile(currentFile, outputBinary, {})) {
		std::cout << "Compilacion exitosa" << std::endl;
		return true;
	}
	std::cerr << "Error en la compilacion: " << compilerManager.getLastOutput() << std::endl;
	return false;
}

bool MainController::runExecutable ( ) {
	if (currentFile.empty()) {
		std::cerr << "No hay archivo seleccionado para ejecutar" << std::endl;
		return false;
	}
	
	
	std::string executableFile = currentFile;
	size_t dotPos = currentFile.find_last_of('.');
	if (dotPos != std::string::npos && currentFile.substr(dotPos) == ".cpp") {
		executableFile = currentFile.substr(0, dotPos); 
	}
	executableFile += ".exe";
	
	std::cout << "Ejecutando: " << executableFile << std::endl;
	std::string command = "cmd /c start cmd /k \"" + executableFile + "\"";
	
	if (wxExecute(command, wxEXEC_ASYNC) != 0) {
		std::cout << "Ejecucion exitosa!" << std::endl;
		return true;
	} else {
		std::cerr << "Error en la ejecucion" << std::endl;
		return false;
	}
}	

void MainController::editContent (const std::string & newContent) {
	editorManager.setText(newContent);
	if(!currentFile.empty()){
		openFiles[currentFile] = newContent;
	}
	std::cout << "Contenido editado" << std::endl;
}


bool MainController::switchFile (const std::string & fileName) {
	if(openFiles.find(fileName)==openFiles.end() || currentFile == fileName){
		std::cerr << "El archivo no esta abierto" << std::endl;
		return false;
	}
	currentFile = fileName;
	editorManager.setText(openFiles[fileName]);
	return true;
}

bool MainController::closeFile (const std::string & fileName) {
	auto it = openFiles.find(fileName);
	if (it == openFiles.end()) {
		return false;
	}
	if (it->second != fileManager.getContent()) {
		return false; // indica que hay cambios no guardados
	}
	openFiles.erase(it);
	if (currentFile == fileName) {
		currentFile.clear();
	}
	return true;
}


std::string MainController::getContent () {
	if(currentFile.empty()){
		return "Archivo sin contenido";
	}
	return editorManager.getText();
}

void MainController::createNewFile (const std::string &fileName) {
	std::string fixedFileName = fileName;
	if (fixedFileName.find(".cpp") == std::string::npos) {
		fixedFileName += ".cpp";  
	}
	std::string defaultContent = "#include <iostream>\nusing namespace std;\n\nint main(){\n\nreturn 0;\n}\n ";
	currentFile = fixedFileName;
	fileManager.setContent(defaultContent);
	fileManager.saveFile(fixedFileName);
	
	fileManager.openFile(fixedFileName);
	fileManager.loadIntoEditor(editorManager);
	
	openFiles[fixedFileName] = defaultContent;
	std::cout << "Archivo " << fixedFileName << " creado exitosamente" << std::endl;
}


bool MainController::saveFileAs (const std::string & fileName) {
	if (fileName.empty()) {
		std::cerr << "Nombre de archivo vacío. No se puede guardar." << std::endl;
		return false;
	}
	
	if (fileManager.saveAs(fileName)) {
		fileManager.setCurrentFile(fileName);
		return true;
	}
	
	return false;
}


void MainController::setFileContent (const std::string & content) {
	fileManager.setContent(content);
}

