///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/tglbtn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/stc/stc.h>
#include <wx/menu.h>
#include <wx/toolbar.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_MENUFRAME 6100
#define wxID_BIENVENIDO 6101
#define wxID_ABR 6102
#define wxID_NUE 6103
#define wxID_FRAME 6104
#define wxID_TEXT 6105
#define wxID_MENUBAR 6106
#define wxID_NUEVOARCHI 6107
#define wxID_ABRIRARCHI 6108
#define wxID_GUARDARARCHI 6109
#define wxID_TOOLBAR 6110
#define wxID_NUEVO 6111
#define wxID_ABRIR 6112
#define wxID_GUARDAR 6113
#define wxID_GUARDARCOMO 6114
#define wxID_DESHACER 6115
#define wxID_REHACER 6116
#define wxID_COMPILAR 6117
#define wxID_EJECUTAR 6118

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame8
///////////////////////////////////////////////////////////////////////////////
class MyFrame8 : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxBitmapToggleButton* ABRIRBUTTON;
		wxBitmapToggleButton* NUEVOBUTTON;
		wxStaticBitmap* m_bitmap6;

		// Virtual event handlers, override them in your derived class
		virtual void OnAbrir( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNuevo( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame8( wxWindow* parent, wxWindowID id = wxID_MENUFRAME, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1920,1080 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );

		~MyFrame8();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Frame
///////////////////////////////////////////////////////////////////////////////
class Frame : public wxFrame
{
	private:

	protected:
		wxStyledTextCtrl* m_scintilla1;
		wxMenuBar* m_menubar1;
		wxMenu* Archivo;
		wxToolBar* m_toolBar1;
		wxToolBarToolBase* Nuevo;
		wxToolBarToolBase* Abrir;
		wxToolBarToolBase* Guardar;
		wxToolBarToolBase* GuardarComo;
		wxToolBarToolBase* Deshacer;
		wxToolBarToolBase* Rehacer;
		wxToolBarToolBase* Compilar;
		wxToolBarToolBase* Ejecutar;

		// Virtual event handlers, override them in your derived class
		virtual void OnIndentation( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnNuevo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbrir( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGuardar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGuardarComo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUndo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRedo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCompilar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEjecutar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Frame( wxWindow* parent, wxWindowID id = wxID_FRAME, const wxString& title = wxT("CodeHex"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1920,1080 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxRESIZE_BORDER|wxTAB_TRAVERSAL );

		~Frame();

};

