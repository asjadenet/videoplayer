#include <wx/wx.h>
#include <map>
#include "FormMainDerived.h"
#include "FormMainPanelMain.h"
#include <boost/filesystem/operations.hpp>

namespace fs = boost::filesystem;
using std::string;
using std::map;


FormMainDerived::FormMainDerived(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                 const wxSize &size,
                                 long style) : FormMain(parent, id, title, pos, size, style) {
    m_parent = parent;
    Centre();
    try {
        wxPanel *Panel1 = new FormMainPanelMain(this);
    }
    catch (std::runtime_error &e) {
        std::string msg("tekkis viga:");
        wxMessageBox(msg + e.what(), "", wxICON_ERROR);
        Close(true);
    }
}







