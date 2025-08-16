#ifndef FRAMEBASE_H
#define FRAMEBASE_H
#include "wxfb_project.h"
#include "MainController.h"
#include <vector>
#include <wx/notebook.h>
#include <wx/stc/stc.h>

class FrameBase : public Frame {
	
private:
	wxStyledTextCtrl* m_scintilla1;
	MainController *m_Controller;
protected:
	void OnIndentation( wxKeyEvent& event )  override;
	void OnGuardarComo( wxCommandEvent& event )  override;
	void OnNuevo( wxCommandEvent& event )  override;
	void OnAbrir( wxCommandEvent& event )  override;
	void OnGuardar( wxCommandEvent& event )  override;
	void OnUndo( wxCommandEvent& event )  override;
	void OnRedo( wxCommandEvent& event )  override;
	void OnCompilar( wxCommandEvent& event )  override;
	void OnEjecutar( wxCommandEvent& event )  override;
	
	
public:
	FrameBase(MainController *mainController);
	~FrameBase();
	wxStyledTextCtrl* getScintilla( ) ;
	void setupShortcuts();
};

#endif

