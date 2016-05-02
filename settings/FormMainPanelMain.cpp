#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <http_get_video_dir.h>
#include <map>
#include <map_to_json.h>
#include <write_string_to_file.h>

#include "FormMainDerived.h"
#include "FormMainPanelMain.h"
#include <boost/filesystem/operations.hpp>

#include <Config.h>
#include <cmake_conf.h>



FormMainPanelMain::FormMainPanelMain( FormMainDerived* parent )
:
PanelMain( parent )
{
    auto config_dir = ::wxStandardPaths::Get().GetUserConfigDir ();
    const bool ignoreFileExists = true;
    Config::read((std::string) config_dir, (std::string)APP_NAME, ignoreFileExists);

    parent->CreateStatusBar();
    parent->SetStatusText("konfiguratsioon:"+Config::config_file);

//    m_textCtrl_ip->ChangeValue(settings_map["kodiHostIp"]);
//    m_textCtrl_port->ChangeValue(settings_map["port"]);
//    m_textCtrl_http_timeout_ms->ChangeValue(settings_map["httpTimeOutMs"]);
//    m_textCtrl_video_dir->ChangeValue(settings_map["videoDir"]);

    if(!Config::fileExists)
        return;
    wxWindowList & children = this->GetChildren();
    for ( wxWindowList::Node *node = children.GetFirst(); node; node = node->GetNext() )
    {
        wxWindow *current = node->GetData();
        if (wxTextCtrl* derived = dynamic_cast<wxTextCtrl*>(current)) {
            derived->ChangeValue(Config::setting[(string)derived->GetName()]);
        }
    }
}

void FormMainPanelMain::btnSearchVideoDirClicked( wxCommandEvent& event )
{
    //    wxMessageBox("otsime video dir");
    std::string host (m_textCtrl_ip->GetValue());
    std::string port (m_textCtrl_port->GetValue());
    std::string video_dir = http_get_video_dir(host, port);
//    wxMessageBox(video_dir);
    m_textCtrl_video_dir->ChangeValue(video_dir);
}

void FormMainPanelMain::btnSaveAndExit( wxCommandEvent& event )
{
    wxWindowList & children = this->GetChildren();
    map<string, string> m;
    for ( wxWindowList::Node *node = children.GetFirst(); node; node = node->GetNext() )
    {
        wxWindow *current = node->GetData();
        if (wxTextCtrl* derived = dynamic_cast<wxTextCtrl*>(current)) {
            m.insert(std::pair<string, string>((string)derived->GetName(), (string)derived->GetValue()));
        }
    }
    write_string_to_file(Config::config_file, map_to_json(m));
    m_parent->Close(true);
}
