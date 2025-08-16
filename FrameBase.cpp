#include "FrameBase.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/textdlg.h>
#include <wx/filedlg.h>
#include <wx/stc/stc.h>

FrameBase::FrameBase(MainController *mainController) : Frame(nullptr), m_Controller(mainController) {
<<<<<<< HEAD
	m_scintilla1 = (wxStyledTextCtrl*)this->FindWindowById(wxID_TEXT);
	if (m_scintilla1) {	
		m_scintilla1->SetLexer(wxSTC_LEX_CPP); 
		m_scintilla1->SetKeyWords(0, "auto break case catch char class const continue default delete do double else enum extern float for friend goto if inline int long namespace new operator private protected public register return short signed sizeof static struct switch template this throw try typedef union unsigned using virtual void volatile while bool"); 
		m_scintilla1->SetKeyWords(1, "#"); 
		m_scintilla1->StyleSetForeground(wxSTC_C_DEFAULT, wxColour(0, 0, 0)); 
		m_scintilla1->StyleSetForeground(wxSTC_C_WORD, wxColour(128, 0, 128)); 
		m_scintilla1->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColour(255, 0, 0)); 
		m_scintilla1->StyleSetForeground(wxSTC_C_STRING, wxColour(0, 0, 255));
		
		wxFont font(10, wxDEFAULT, wxNORMAL, wxBOLD);
		m_scintilla1->StyleSetFont(wxSTC_C_WORD, font);
		m_scintilla1->StyleSetFont(wxSTC_C_PREPROCESSOR, font);
		
		m_scintilla1->SetUseTabs(true);
		m_scintilla1->SetIndent(4); 
		m_scintilla1->SetTabWidth(4); 
		m_scintilla1->SetIndentationGuides(true);
		m_scintilla1->SetBackSpaceUnIndents(true);
	}
	
	setupShortcuts();
	Bind(wxEVT_MENU, &FrameBase::OnGuardar, this, wxID_SAVE);
	Bind(wxEVT_MENU, &FrameBase::OnAbrir, this, wxID_OPEN);
	Bind(wxEVT_MENU, &FrameBase::OnNuevo, this, wxID_NEW);
	Bind(wxEVT_MENU, &FrameBase::OnEjecutar, this, wxID_EXECUTE);
	Bind(wxEVT_MENU, &FrameBase::OnCompilar, this, wxID_REFRESH);
	Bind(wxEVT_MENU, &FrameBase::OnUndo, this, wxID_UNDO);
	Bind(wxEVT_MENU, &FrameBase::OnRedo, this, wxID_REDO);
=======
	Layout();
>>>>>>> 6e0ee9b4ffc3ccfbef719fd24ed60c3719987bfe
}

void FrameBase::OnNuevo( wxCommandEvent& event )  {
	wxTextEntryDialog dialog(this, "Ingrese el nombre del nuevo archivo:", "Nuevo Archivo");
	if (dialog.ShowModal() == wxID_OK) {
		std::string fileName = dialog.GetValue().ToStdString();
		m_Controller->createNewFile(fileName);
		
		
		wxString contenido = wxString::FromUTF8(m_Controller->getContent().c_str());
		m_scintilla1->SetValue(contenido); 
		
		m_Controller->saveFile(fileName);
	}
}

void FrameBase::OnAbrir( wxCommandEvent& event )  {
	wxString filePath = wxFileSelector("Selecciona un archivo para abrir");
	
	if (!filePath.IsEmpty()) {
		std::string fileName = std::string(filePath.mb_str()); 
		
		if (m_Controller->openFile(fileName)) { 
			wxString contenido = wxString::FromUTF8(m_Controller->getContent().c_str()); 
			m_scintilla1->SetValue(contenido); 
		} else {
			wxMessageBox("No se pudo abrir el archivo", "Error", wxICON_ERROR);
		}
	}
}

void FrameBase::OnGuardar( wxCommandEvent& event )  {
	wxString contenido = getScintilla()->GetText(); 
	
	m_Controller->setFileContent(std::string(contenido.mb_str()));
	if (!m_Controller->saveCurrentFile()) {
		wxMessageBox("No hay archivo abierto o error al guardar", "Error", wxICON_ERROR);
	}
}

void FrameBase::OnUndo( wxCommandEvent& event )  {
	if (m_scintilla1 && m_scintilla1->CanUndo()) {
		m_scintilla1->Undo();	
	}
}

void FrameBase::OnRedo( wxCommandEvent& event )  {
	if (m_scintilla1 && m_scintilla1->CanRedo()) {
		m_scintilla1->Redo();
	}
}

void FrameBase::OnCompilar( wxCommandEvent& event )  {
	if (!m_Controller->compileCurrentFile()) {
		wxMessageBox("Error en la compilación", "Error", wxICON_ERROR);
	} else {
		wxMessageBox("Compilación exitosa", "Compilación", wxICON_INFORMATION);
	}
}

void FrameBase::OnEjecutar( wxCommandEvent& event )  {
	if (!m_Controller->runExecutable()) {
		wxMessageBox("Error al ejecutar el programa", "Error", wxICON_ERROR);
	}
}

FrameBase::~FrameBase() {
	
}

void FrameBase::OnGuardarComo( wxCommandEvent& event )  {
	wxFileDialog saveFileDialog(this, "Guardar archivo como", "", "", "Archivos C++ (*.cpp)|*.cpp|Todos los archivos (*.*)|*.*", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	
	if (saveFileDialog.ShowModal() == wxID_CANCEL) {
		return; 
	}
	
	std::string filePath = saveFileDialog.GetPath().ToStdString();
	
	
	if (m_Controller->saveFileAs(filePath)) {
		wxMessageBox("Archivo guardado exitosamente", "Éxito", wxICON_INFORMATION);
	} else {
		wxMessageBox("Error al guardar el archivo", "Error", wxICON_ERROR);
	}
	
}


wxStyledTextCtrl* FrameBase::getScintilla ( ) {
	return m_scintilla1;
}

void FrameBase::OnIndentation( wxKeyEvent& event )  {
	if (event.GetKeyCode() == WXK_RETURN) {
		int pos = m_scintilla1->GetCurrentPos();
		int line = m_scintilla1->LineFromPosition(pos);
		wxString text = m_scintilla1->GetLine(line);
		if (text.Find('{')!= wxNOT_FOUND && text.Last() == '{') {
			m_scintilla1->InsertText(pos + 1, "\n    "); 
			m_scintilla1->GotoPos(pos + 5); 
		}
	}
	event.Skip();
}


void FrameBase::setupShortcuts ( ) {
	wxAcceleratorEntry entries[7];  
	
	entries[0].Set(wxACCEL_CTRL, (int)'S', wxID_SAVE);         
	entries[1].Set(wxACCEL_CTRL, (int)'O', wxID_OPEN);         
	entries[2].Set(wxACCEL_CTRL, (int)'N', wxID_NEW);          
	entries[3].Set(wxACCEL_NORMAL, WXK_F9, wxID_EXECUTE);      
	entries[4].Set(wxACCEL_SHIFT, WXK_F9, wxID_REFRESH);       
	entries[5].Set(wxACCEL_CTRL, (int)'Z', wxID_UNDO);         
	entries[6].Set(wxACCEL_CTRL, (int)'Y', wxID_REDO);         
	
	wxAcceleratorTable accel(sizeof(entries) / sizeof(wxAcceleratorEntry), entries);
	this->SetAcceleratorTable(accel);
}

