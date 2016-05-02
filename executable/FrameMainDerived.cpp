#include <wx/wx.h>
//#include <fstream>
//#include <boost/asio/ip/tcp.hpp>
//#include <boost/filesystem/path.hpp>
//#include <boost/algorithm/string/replace.hpp>
#include "FrameMainDerived.h"


FrameMainDerived::FrameMainDerived(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                     long style) : FrameMain(parent, id, title, pos, size, style),  m_timer (this, TIMER_ID) {
    m_parent = parent;
    m_timer.Start(timer_ms);


    try {
        m_panel1 = new MainExecutablePanelMain(this);
    }
    catch (std::runtime_error &e) {
        std::string msg("tekkis viga:");
        wxMessageBox(msg + e.what(), "", wxICON_ERROR);
        Close(true);
    }

}

wxBEGIN_EVENT_TABLE(FrameMainDerived, FrameMain)
                EVT_TIMER(TIMER_ID, FrameMainDerived::OnTimer)
wxEND_EVENT_TABLE()

void FrameMainDerived::OnTimer(wxTimerEvent &event) {
    m_panel1->timer_tick();
}


