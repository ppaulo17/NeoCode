#include "CompilerManager.h"
#include <string>
#include <array>
#include <sstream>
#include <memory>
#include <vector>

CompilerManager::CompilerManager() {}


bool CompilerManager::compile (const std::string &sourceFile, const std::string &outputFile, const std::vector<std::string> &flags) { /* (g++ sourceFile -o outputFile) compila el archivo sourceFile y genera un ejecutable outputFile.*/
	std::ostringstream command;
	command << "g++ " << sourceFile << " -o " << outputFile;
	
	for(const auto &flag:flags){
		command << " " << flag;
	}
	
	command << " 2>&1";
	
	std::vector<char> buffer(256);
	std::string result;
	
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.str().c_str(), "r"), pclose); //popen ejecuta el comando en la terminal y captura la salida 
	if(!pipe){ 	//pipe almacena la conexion del proceso del compiador
		lastOutput = "Error al ejecutar el compilador"; // si falla es pq hubo un error, obvio no?
		return false;
	}
	while(fgets(buffer.data(), buffer.size(), pipe.get()) !=nullptr){
		result.append(buffer.data());
	}		// este while lee la salida de g++ linea por linea y la almacena en result, osea los errores 
	
	int exitCode = pclose(pipe.release());
	if(exitCode != 0) {
		lastOutput = "Error en la compilacion (codigo " + std::to_string(exitCode) + "):\n" + result;
		return false;
	}
	
	lastOutput =result;
	return result.empty(); // si no hay salida es porque todo compilo bien 
}


std::string CompilerManager::getLastOutput ( ) const {
	return lastOutput;
}
//devuelve el mensaje del compilador

bool CompilerManager::run (const std::string & executableFile) {
	std::ostringstream command;
	if (access(executableFile.c_str(), F_OK) == -1) {
		std::string path = getenv("PATH");
		size_t pos = 0;
		while ((pos = path.find(":"))!= std::string::npos) {
			std::string dir = path.substr(0, pos);
			std::string fullPath = dir + "/" + executableFile;
			if (access(fullPath.c_str(), F_OK)!= -1) {
				command << fullPath << " 2>&1";
				break;
			}
			path.erase(0, pos + 1);
		}
	} else {
		command << "\"" << executableFile << " 2>&1";
	}
	
	std::vector<char> buffer(256);
	std::string result;
	
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.str().c_str(), "r"), pclose); //popen ejecuta el comando en la terminal y captura la salida 
	if(!pipe){ 	//pipe almacena la conexion del proceso del compiador
		lastOutput = "Error al ejecutar el programa"; // si falla es pq hubo un error, obvio no?
		return false;
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get())!= nullptr) {
		result.append(buffer.data());
		std::cout << buffer.data();
	}
	int exitCode = pclose(pipe.release()); // Captura del código de salida
	if (exitCode!= 0) {
		lastOutput = "Error en la ejecución (código " + std::to_string(exitCode) + "):\n" + result;
		return false;
	}
	lastOutput = result;
	std::cout << "Salida final: " << lastOutput << std::endl;
	return true;
}

bool CompilerManager::compileCurrentFile (FileManager & fileManager, const std::vector<std::string> & flags) {
	const std::string currentFile = fileManager.getCurrentFile();
	if(currentFile.empty()){
		lastOutput = "No hay archivo para compilar";
		return false;
	}
	return compile(currentFile, "output", flags);
}

