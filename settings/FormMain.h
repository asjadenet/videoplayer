///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FORMMAIN_H__
#define __FORMMAIN_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FormMain
///////////////////////////////////////////////////////////////////////////////
class FormMain : public wxFrame 
{
	private:
	
	protected:
	
	public:
		
		FormMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("videopleierei seaded"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 725,470 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~FormMain();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PanelMain
///////////////////////////////////////////////////////////////////////////////
class PanelMain : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* m_staticText10;
		wxTextCtrl* m_textCtrl_ip;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText101;
		wxTextCtrl* m_textCtrl_port;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_textCtrl_http_timeout_ms;
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText_video_dir;
		wxTextCtrl* m_textCtrl_video_dir;
		wxButton* m_button_search_video_dir;
		wxStaticText* m_staticText16;
		wxButton* m_button_save_and_exit;
		
		// Virtual event handlers, overide them in your derived class
		virtual void btnSearchVideoDirClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnSaveAndExit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PanelMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~PanelMain();
	
};

#endif //__FORMMAIN_H__
