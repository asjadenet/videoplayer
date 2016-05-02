#ifndef MYGREATPROJECT_MAINFRAME_H
#define MYGREATPROJECT_MAINFRAME_H

#include <wx/timer.h>
//#include <boost/filesystem/path.hpp>
//#include <HttpConf.h>
#include "MainExecutable.h"
#include "MainExecutablePanelMain.h"
//#include "MainExecutablePanelMain.h"

#define TIMER_ID 1000

static const int timer_ms = 1000;

class FrameMainDerived : public FrameMain {

public:
    FrameMainDerived( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxCAPTION|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxRESIZE_BORDER|wxSTAY_ON_TOP|wxTAB_TRAVERSAL);
    void OnTimer(wxTimerEvent& event);

private:
    wxTimer m_timer;
    MainExecutablePanelMain *m_panel1;
    wxDECLARE_EVENT_TABLE();
};







#endif //MYGREATPROJECT_MAINFRAME_H
