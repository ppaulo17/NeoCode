#ifndef EDITORMANAGER_H
#define EDITORMANAGER_H
#include <string>
#include <stack>
#include <unordered_set>
#include <wx/stc/stc.h>

class EditorManager {
public:
	EditorManager();
	void setText(const std::string &text);
	std::string getText() const;
	void clear();
private:
	std::string currentText;
};

#endif

