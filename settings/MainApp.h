//
// Created by tiit on 11.04.2016.
//

#ifndef MYGREATPROJECT_MAIN_H
#define MYGREATPROJECT_MAIN_H
#include "wx/wxprec.h"
#include <wx/snglinst.h>

#ifndef WX_PRECOMP
#	include "wx/wx.h"
#endif

class MainApp : public wxApp {
public:
    virtual bool OnInit();
    virtual int OnExit();

private:
    wxSingleInstanceChecker* m_checker;
};

DECLARE_APP(MainApp)

#endif //MYGREATPROJECT_MAIN_H
