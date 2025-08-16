#include "EditorManager.h"
#include <string>


EditorManager::EditorManager() {
}


void EditorManager::setText (const std::string & text) {
	currentText = text;
}

std::string EditorManager::getText ( ) const {
	return currentText;
}

void EditorManager::clear ( ) {
	currentText.clear();
}






