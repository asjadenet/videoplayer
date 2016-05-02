#include "WxMain.h"

#include "FrameMainDerived.h"
#include "cmake_conf.h"
#include <http_get_video_files.h>
#include <Config.h>

std::string Config::config_file;
map<string, string> Config::setting;
bool Config::fileExists;
HttpConf Config::httpConf;

IMPLEMENT_APP(WxMain)

bool WxMain::OnInit() {

    m_checker = new wxSingleInstanceChecker;
    if (m_checker->IsAnotherRunning()) {
        delete m_checker;
        m_checker = NULL;
        return false;
    }

//    wxFrame *frame = new wxFrame((wxFrame*) NULL, -1, _T("Hello wxWidgets World"));
//    frame->CreateStatusBar();
//    frame->SetStatusText(_T("Hello World"));
//    frame->Show(true);
//    SetTopWindow(frame);
//    return true;

    wxSize size(510, 400);
    FrameMainDerived *frame = new FrameMainDerived((wxFrame *) NULL, -1, _T("Videovaatamine"), wxDefaultPosition, size);
    frame->CreateStatusBar();
    std::string app_name = APP_NAME;
    frame->SetStatusText(_T("Rakendus:" + app_name));
    frame->Show(true);
    SetTopWindow(frame);
    return true;

//	HttpTest::execute();
//    exit(1);
//    return false;

}

int WxMain::OnExit() {
    delete m_checker;
    m_checker = NULL;
    return 0;
}