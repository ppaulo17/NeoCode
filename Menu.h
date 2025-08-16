#ifndef MENU_H
#define MENU_H
#include "wxfb_project.h"
#include "MainController.h"
#include "FrameBase.h"
#include <wx/event.h>
#include <wx/window.h>

class Menu : public MyFrame8 {
	
private:
	MainController *m_Controller;
	FrameBase *ventanaPrincipal;
protected:
	void OnAbrir( wxCommandEvent& event )  override;
	void OnNuevo( wxCommandEvent& event )  override;
	
public:
	Menu(MainController* mainController);
	~Menu();
};

#endif

