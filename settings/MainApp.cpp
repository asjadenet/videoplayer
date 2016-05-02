#include "MainApp.h"
#include "FormMainDerived.h"

std::string Config::config_file;
map<string, string> Config::setting;
bool Config::fileExists;
HttpConf Config::httpConf;

IMPLEMENT_APP(MainApp)

// This is executed upon startup, like 'main()' in non-wxWidgets programs.
bool MainApp::OnInit()
{
    m_checker = new wxSingleInstanceChecker;
    if ( m_checker->IsAnotherRunning() )    {
//        wxLogError(_("Another program instance is already running, aborting."));
        delete m_checker;
        // OnExit() won't be called if we return false
        m_checker = NULL;
        return false;
    }

//     wxFrame *frame = new wxFrame((wxFrame*) NULL, -1, _T("Hello wxWidgets World"));
    FormMainDerived *frame = new FormMainDerived((wxFrame*) NULL, -1, _T("seaded"));
    frame->Show(true);
    return true;
}

int MainApp::OnExit(){
    delete m_checker;
    return 0;
}