#ifndef MYGREATPROJECT_FORMMAIN_H
#define MYGREATPROJECT_FORMMAIN_H


#include <Config.h>
#include "FormMain.h"

class FormMainDerived : public FormMain {
public:
    FormMainDerived( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxCAPTION|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxRESIZE_BORDER|wxSTAY_ON_TOP|wxTAB_TRAVERSAL );
};


#endif //MYGREATPROJECT_FORMMAIN_H
