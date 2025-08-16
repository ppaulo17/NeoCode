#include "Menu.h"
#include <wx/textdlg.h>
#include <wx/string.h>
#include <wx/filedlg.h>
#include <string>
#include <wx/msgdlg.h>


Menu::Menu(MainController *mainController) : MyFrame8(nullptr), m_Controller(mainController) {}

void Menu::OnAbrir( wxCommandEvent& event )  {
	wxString filePath = wxFileSelector("Selecciona un archivo para abrir");
	
	if (!filePath.IsEmpty()) {
		std::string fileName = std::string(filePath.mb_str()); 
		
		if (m_Controller->openFile(fileName)) { 
			wxString contenido = wxString::FromUTF8(m_Controller->getContent().c_str()); 
			
			if(!this->ventanaPrincipal){
				this->ventanaPrincipal = new FrameBase(m_Controller);
			}
			this->ventanaPrincipal->getScintilla()->SetValue(contenido); 
		} else {
			wxMessageBox("No se pudo abrir el archivo", "Error", wxICON_ERROR);
			return;
		}
		
		ventanaPrincipal->Show();
		this->Close();
		
	}
}



void Menu::OnNuevo( wxCommandEvent& event )  {
	wxTextEntryDialog dialog(this, "Ingrese el nombre del nuevo archivo:", "Nuevo Archivo");
	if (dialog.ShowModal() == wxID_OK) {
		std::string fileName = dialog.GetValue().ToStdString();
		m_Controller->createNewFile(fileName);
		
		wxString contenido = wxString::FromUTF8(m_Controller->getContent().c_str());
		
		if(!this->ventanaPrincipal){
			this->ventanaPrincipal = new FrameBase(m_Controller);
		}
		
		this->ventanaPrincipal->getScintilla()->SetValue(contenido);
		
		m_Controller->saveFile(fileName);
		
		ventanaPrincipal->Show();
		this->Close();
	}
	
}

Menu::~Menu() {
	
}

