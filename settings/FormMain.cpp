///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "FormMain.h"

///////////////////////////////////////////////////////////////////////////

FormMain::FormMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	
	this->Centre( wxBOTH );
}

FormMain::~FormMain()
{
}

PanelMain::PanelMain( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("kodi host ip"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer1->Add( m_staticText10, 0, wxALL, 5 );
	
	m_textCtrl_ip = new wxTextCtrl( this, wxID_ANY, wxT("192.168.0.231"), wxDefaultPosition, wxSize( 200,-1 ), 0, wxDefaultValidator, wxT("kodiHostIp") );
	fgSizer1->Add( m_textCtrl_ip, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer1->Add( m_staticText9, 0, wxALL, 5 );
	
	m_staticText101 = new wxStaticText( this, wxID_ANY, wxT("port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	fgSizer1->Add( m_staticText101, 0, wxALL, 5 );
	
	m_textCtrl_port = new wxTextCtrl( this, wxID_ANY, wxT("8080"), wxDefaultPosition, wxSize( 200,-1 ), 0, wxDefaultValidator, wxT("port") );
	fgSizer1->Add( m_textCtrl_port, 0, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	fgSizer1->Add( m_staticText12, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("http timeout ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer1->Add( m_staticText13, 0, wxALL, 5 );
	
	m_textCtrl_http_timeout_ms = new wxTextCtrl( this, wxID_ANY, wxT("1000"), wxDefaultPosition, wxSize( 200,-1 ), 0, wxDefaultValidator, wxT("httpTimeOutMs") );
	fgSizer1->Add( m_textCtrl_http_timeout_ms, 0, wxALL, 5 );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	fgSizer1->Add( m_staticText14, 0, wxALL, 5 );
	
	m_staticText_video_dir = new wxStaticText( this, wxID_ANY, wxT("video dir"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_video_dir->Wrap( -1 );
	fgSizer1->Add( m_staticText_video_dir, 0, wxALL, 5 );
	
	m_textCtrl_video_dir = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0, wxDefaultValidator, wxT("videoDir") );
	fgSizer1->Add( m_textCtrl_video_dir, 0, wxALL, 5 );
	
	m_button_search_video_dir = new wxButton( this, wxID_ANY, wxT("otsi"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_button_search_video_dir, 0, wxALL, 5 );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer1->Add( m_staticText16, 0, wxALL, 5 );
	
	m_button_save_and_exit = new wxButton( this, wxID_ANY, wxT("salvesta ja lahku"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_button_save_and_exit, 0, wxALL, 5 );
	
	
	this->SetSizer( fgSizer1 );
	this->Layout();
	
	// Connect Events
	m_button_search_video_dir->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::btnSearchVideoDirClicked ), NULL, this );
	m_button_save_and_exit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::btnSaveAndExit ), NULL, this );
}

PanelMain::~PanelMain()
{
	// Disconnect Events
	m_button_search_video_dir->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::btnSearchVideoDirClicked ), NULL, this );
	m_button_save_and_exit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::btnSaveAndExit ), NULL, this );
	
}
