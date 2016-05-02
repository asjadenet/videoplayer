///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINEXECUTABLE_H__
#define __MAINEXECUTABLE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/listbox.h>
#include <wx/tglbtn.h>
#include <wx/slider.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FrameMain
///////////////////////////////////////////////////////////////////////////////
class FrameMain : public wxFrame 
{
	private:
	
	protected:
	
	public:
		
		FrameMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 625,515 ), long style = wxCAPTION|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxRESIZE_BORDER|wxSTAY_ON_TOP|wxTAB_TRAVERSAL );
		
		~FrameMain();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PanelMain
///////////////////////////////////////////////////////////////////////////////
class PanelMain : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* m_staticText3;
		wxButton* m_buttonExit;
		wxListBox* m_listBox2;
		wxToggleButton* m_toggleBtnPlayPause;
		wxButton* m_btn_stop;
		wxSlider* m_slider1;
		wxStaticText* m_staticTextTime;
		
		// Virtual event handlers, overide them in your derived class
		virtual void btnExitClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void toggleBtnPlayPauseClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnStopClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PanelMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 522,300 ), long style = wxTAB_TRAVERSAL ); 
		~PanelMain();
	
};

#endif //__MAINEXECUTABLE_H__
