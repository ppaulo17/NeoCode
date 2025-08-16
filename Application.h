#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "MainController.h"
#include "Menu.h"

class Application : public wxApp {
	MainController *mainController;
	Menu* menu;
public:
	virtual bool OnInit();
};

#endif
