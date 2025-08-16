///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

MyFrame8::MyFrame8( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_staticText3 = new wxStaticText( this, wxID_BIENVENIDO, wxT("NEOCODE"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 50, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Bookman Old Style") ) );
	m_staticText3->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	m_staticText3->SetBackgroundColour( wxColour( 32, 32, 32 ) );

	bSizer3->Add( m_staticText3, 0, wxALL|wxEXPAND, 5 );

	ABRIRBUTTON = new wxBitmapToggleButton( this, wxID_ABR, wxBitmap( wxT("Assets/abrir-documento.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );

	ABRIRBUTTON->SetBitmap( wxBitmap( wxT("Assets/abrir-documento.png"), wxBITMAP_TYPE_ANY ) );
	ABRIRBUTTON->SetFont( wxFont( 30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	ABRIRBUTTON->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	ABRIRBUTTON->SetBackgroundColour( wxColour( 32, 32, 32 ) );

	bSizer3->Add( ABRIRBUTTON, 0, wxALL|wxEXPAND, 5 );

	NUEVOBUTTON = new wxBitmapToggleButton( this, wxID_NUE, wxBitmap( wxT("Assets/registro.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );

	NUEVOBUTTON->SetBitmap( wxBitmap( wxT("Assets/registro.png"), wxBITMAP_TYPE_ANY ) );
	NUEVOBUTTON->SetFont( wxFont( 30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	NUEVOBUTTON->SetBackgroundColour( wxColour( 32, 32, 32 ) );

	bSizer3->Add( NUEVOBUTTON, 0, wxALL|wxEXPAND, 5 );

	m_bitmap6 = new wxStaticBitmap( this, wxID_ABR, wxBitmap( wxT("Assets/logo.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	m_bitmap6->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("@MS Gothic") ) );
	m_bitmap6->SetBackgroundColour( wxColour( 32, 32, 32 ) );

	bSizer3->Add( m_bitmap6, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	ABRIRBUTTON->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame8::OnAbrir ), NULL, this );
	NUEVOBUTTON->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame8::OnNuevo ), NULL, this );
}

MyFrame8::~MyFrame8()
{
	// Disconnect Events
	ABRIRBUTTON->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame8::OnAbrir ), NULL, this );
	NUEVOBUTTON->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame8::OnNuevo ), NULL, this );

}

Frame::Frame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_scintilla1 = new wxStyledTextCtrl( this, wxID_TEXT, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	m_scintilla1->SetUseTabs( true );
	m_scintilla1->SetTabWidth( 4 );
	m_scintilla1->SetIndent( 4 );
	m_scintilla1->SetTabIndents( true );
	m_scintilla1->SetBackSpaceUnIndents( true );
	m_scintilla1->SetViewEOL( false );
	m_scintilla1->SetViewWhiteSpace( false );
	m_scintilla1->SetMarginWidth( 2, 0 );
	m_scintilla1->SetIndentationGuides( true );
	m_scintilla1->SetReadOnly( false );
	m_scintilla1->SetMarginType( 1, wxSTC_MARGIN_SYMBOL );
	m_scintilla1->SetMarginMask( 1, wxSTC_MASK_FOLDERS );
	m_scintilla1->SetMarginWidth( 1, 16);
	m_scintilla1->SetMarginSensitive( 1, true );
	m_scintilla1->SetProperty( wxT("fold"), wxT("1") );
	m_scintilla1->SetFoldFlags( wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED );
	m_scintilla1->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
	m_scintilla1->SetMarginWidth( 0, m_scintilla1->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("_99999") ) );
	{
		wxFont font = wxFont( 11, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Bahnschrift Light") );
		m_scintilla1->StyleSetFont( wxSTC_STYLE_DEFAULT, font );
	}
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	m_scintilla1->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	m_scintilla1->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	m_scintilla1->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	m_scintilla1->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	m_scintilla1->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	m_scintilla1->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	m_scintilla1->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	m_scintilla1->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	m_scintilla1->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_scintilla1->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	m_scintilla1->SetFont( wxFont( 11, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Bahnschrift Light") ) );
	m_scintilla1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );
	m_scintilla1->SetBackgroundColour( wxColour( 48, 48, 48 ) );

	bSizer4->Add( m_scintilla1, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	Archivo = new wxMenu();
	wxMenuItem* NuevoArchivo;
	NuevoArchivo = new wxMenuItem( Archivo, wxID_NUEVOARCHI, wxString( wxT("Nuevo Archivo") ) , wxEmptyString, wxITEM_NORMAL );
	Archivo->Append( NuevoArchivo );

	wxMenuItem* AbrirArchivo;
	AbrirArchivo = new wxMenuItem( Archivo, wxID_ABRIRARCHI, wxString( wxT("Abrir Archivo") ) , wxEmptyString, wxITEM_NORMAL );
	Archivo->Append( AbrirArchivo );

	wxMenuItem* GuardarArchivo;
	GuardarArchivo = new wxMenuItem( Archivo, wxID_GUARDARARCHI, wxString( wxT("Guardar Archivo") ) , wxEmptyString, wxITEM_NORMAL );
	Archivo->Append( GuardarArchivo );

	m_menubar1->Append( Archivo, wxT("Archivo") );

	this->SetMenuBar( m_menubar1 );

	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL|wxTB_HORZ_LAYOUT|wxTB_TEXT, wxID_TOOLBAR );
	m_toolBar1->SetToolSeparation( 4 );
	m_toolBar1->SetMargins( wxSize( -2,-2 ) );
	m_toolBar1->SetToolPacking( 2 );
	m_toolBar1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_toolBar1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	Nuevo = m_toolBar1->AddTool( wxID_NUEVO, wxT("Nuevo"), wxBitmap( wxT("Assets/registro.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	Abrir = m_toolBar1->AddTool( wxID_ABRIR, wxT("Abrir"), wxBitmap( wxT("Assets/abrir-documento.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	Guardar = m_toolBar1->AddTool( wxID_GUARDAR, wxT("Guardar"), wxBitmap( wxT("Assets/boton-guardar.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	GuardarComo = m_toolBar1->AddTool( wxID_GUARDARCOMO, wxT("Guardar Como"), wxBitmap( wxT("Assets/guardar-como.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar1->AddSeparator();

	Deshacer = m_toolBar1->AddTool( wxID_DESHACER, wxT("Deshacer"), wxBitmap( wxT("Assets/deshacer.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	Rehacer = m_toolBar1->AddTool( wxID_REHACER, wxT("Rehacer"), wxBitmap( wxT("Assets/rehacer.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar1->AddSeparator();

	Compilar = m_toolBar1->AddTool( wxID_COMPILAR, wxT("Compilar"), wxBitmap( wxT("Assets/compilador.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	Ejecutar = m_toolBar1->AddTool( wxID_EJECUTAR, wxT("Ejecutar"), wxBitmap( wxT("Assets/terminal.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar1->Realize();


	this->Centre( wxBOTH );

	// Connect Events
	m_scintilla1->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( Frame::OnIndentation ), NULL, this );
	Archivo->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::OnNuevo ), this, NuevoArchivo->GetId());
	Archivo->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::OnAbrir ), this, AbrirArchivo->GetId());
	Archivo->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame::OnGuardar ), this, GuardarArchivo->GetId());
	this->Connect( Nuevo->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnNuevo ) );
	this->Connect( Abrir->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnAbrir ) );
	this->Connect( Guardar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnGuardar ) );
	this->Connect( GuardarComo->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnGuardarComo ) );
	this->Connect( Deshacer->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnUndo ) );
	this->Connect( Rehacer->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnRedo ) );
	this->Connect( Compilar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnCompilar ) );
	this->Connect( Ejecutar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnEjecutar ) );
}

Frame::~Frame()
{
	// Disconnect Events
	m_scintilla1->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( Frame::OnIndentation ), NULL, this );
	this->Disconnect( Nuevo->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnNuevo ) );
	this->Disconnect( Abrir->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnAbrir ) );
	this->Disconnect( Guardar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnGuardar ) );
	this->Disconnect( GuardarComo->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnGuardarComo ) );
	this->Disconnect( Deshacer->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnUndo ) );
	this->Disconnect( Rehacer->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnRedo ) );
	this->Disconnect( Compilar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnCompilar ) );
	this->Disconnect( Ejecutar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame::OnEjecutar ) );

}
