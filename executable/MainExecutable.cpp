///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainExecutable.h"

///////////////////////////////////////////////////////////////////////////

FrameMain::FrameMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	
	this->Centre( wxBOTH );
}

FrameMain::~FrameMain()
{
}

PanelMain::PanelMain( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Videode nimekiri"), wxDefaultPosition, wxSize( 400,-1 ), 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 18, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer3->Add( m_staticText3, 0, wxALL, 5 );
	
	m_buttonExit = new wxButton( this, wxID_ANY, wxT("välju"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonExit, 0, wxALL, 5 );
	
	
	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );
	
	m_listBox2 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 500,150 ), 0, NULL, 0 ); 
	bSizer1->Add( m_listBox2, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_toggleBtnPlayPause = new wxToggleButton( this, wxID_ANY, wxT("|> vaata"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_toggleBtnPlayPause, 0, wxALL, 5 );
	
	m_btn_stop = new wxButton( this, wxID_ANY, wxT("katkesta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_btn_stop, 0, wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	m_slider1 = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxSize( 500,-1 ), wxSL_HORIZONTAL );
	bSizer1->Add( m_slider1, 0, wxALL, 5 );
	
	m_staticTextTime = new wxStaticText( this, wxID_ANY, wxT("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTime->Wrap( -1 );
	bSizer1->Add( m_staticTextTime, 0, wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_buttonExit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::btnExitClick ), NULL, this );
	m_toggleBtnPlayPause->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PanelMain::toggleBtnPlayPauseClick ), NULL, this );
	m_btn_stop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::btnStopClick ), NULL, this );
}

PanelMain::~PanelMain()
{
	// Disconnect Events
	m_buttonExit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::btnExitClick ), NULL, this );
	m_toggleBtnPlayPause->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PanelMain::toggleBtnPlayPauseClick ), NULL, this );
	m_btn_stop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::btnStopClick ), NULL, this );
	
}
