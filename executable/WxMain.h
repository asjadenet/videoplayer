#ifndef INCLUDED_HELLOWORLDAPP_H
#define INCLUDED_HELLOWORLDAPP_H

#include "wx/wxprec.h"
#include <wx/snglinst.h>

#ifndef WX_PRECOMP
#	include "wx/wx.h"
#endif

class WxMain : public wxApp
{
public:
	virtual bool OnInit();
    virtual int OnExit();
private:
	wxSingleInstanceChecker* m_checker;
};
 
DECLARE_APP(WxMain)
 
#endif // INCLUDED_HELLOWORLDAPP_H