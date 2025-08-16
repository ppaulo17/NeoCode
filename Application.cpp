#include <wx/image.h>
#include "Application.h"
#include "wxfb_project.h"
#include "FrameBase.h"
#include "Menu.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	mainController = new MainController();
	menu = new Menu(mainController);
	menu->Show();
	return true;
}


